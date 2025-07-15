#include "../include/tokenizador.h"

char **ft_split(char *str, char c) {
    if (!str) return NULL;

    // Contar número de palabras
    int word_count = 0;
    int i = 0;
    int in_word = 0;
    while (str[i]) {
        if (str[i] != c && !in_word) {
            in_word = 1;
            word_count++;
        } else if (str[i] == c) {
            in_word = 0;
        }
        i++;
    }

    // Alloc array de pointers (+1 para NULL terminator)
    char **result = malloc(sizeof(char *) * (word_count + 1));
    if (!result) return NULL;

    // Llenar el array
    i = 0;
    int idx = 0;
    while (str[i]) {
        // Saltar separadores
        while (str[i] == c) i++;
        if (!str[i]) break;

        // Encontrar fin de palabra
        int start = i;
        while (str[i] && str[i] != c) i++;
        int len = i - start;

        // Alloc y copiar palabra
        result[idx] = malloc(sizeof(char) * (len + 1));
        if (!result[idx]) {
            // Liberar si falla (simplificado)
            while (idx > 0) free(result[--idx]);
            free(result);
            return NULL;
        }
        strncpy(result[idx], str + start, len);
        result[idx][len] = '\0';
        idx++;
    }
    result[idx] = NULL;  // Terminator
    return result;
}


void cargarvocabulario(t_token *token) 
{
    int fd = open(token->filename, O_RDONLY);
    char *filename;
    read(fd, filename, sizeof(char) * 42);
    if(!filename)
        token->close = 1;
    token->token = ft_split(filename, ' ');

}

int ft_lstsize(t_token *token)
{
    int i = 0;
    while(token)
    {
        i++;
        token = token->nextoken;
    }
    return i;
}

int ft_rray(t_token *token) {
    int a = 0;
    if (!token || !token->token) return 0;
    while (token->token[a]) a++;
    return a;
}


int ft_birray(t_token *token) {
    if (!token || !token->token) return 0;
    int total = 0;
    for (int i = 0; i < token->num_tokens; i++) {
        total += strlen(token->token[i]);
    }
    return total;
}

void addtoken(t_token *token, char *newtoken) {
    if (!newtoken) return;

    // Redimensionar array
    char **new_array = realloc(token->token, sizeof(char *) * (token->num_tokens + 1));
    if (!new_array) {
        // Manejar error (simplificado)
        return;
    }
    token->token = new_array;

    // Copiar nuevo token
    token->token[token->num_tokens] = strdup(newtoken);  // Usa strdup para copiar
    if (!token->token[token->num_tokens]) {
        return;  // Error
    }

    // Actualizar contador
    token->num_tokens++;
}


char *newtoken(t_token *token, int media, int i, char *filename, int a)
{
    int k =0;
    int z =0;
    int b = 0;
    int isok = ft_lstsize(token) / media ;
    while(filename[i] == token->token[a][b])
    {
        z++;
        b++;
    }
    
    if(z >= isok)
    {
        char *newtoken = (char *)malloc(sizeof(char )* b );
        while(k <= b)
        {
            newtoken[k]= token->token[a][b - (b -k)];
            k++;
        }
        return newtoken;
    }
    return NULL;
    
}
void readcorpus(t_token *token, int media, int dimensiones)
{
    int a = 0;
    int b = 0;
    int i = 0;
    int x = 0;
    int z = 0;
    int fd = open(token->filenamecorpus, O_RDONLY);
    
    char *filename;
    read(fd, filename, sizeof(char) * 42);
    if(!filename)
        token->close =1;
    
    while(i <= ft_lstsize(token))
    {
        token->token[a] = filename;
        while(token->token[i][a] && b <= dimensiones)
        {
            printf("aqui\n");
            b++;
            if(newtoken(token,  media, i, filename, a) != NULL)
            {
                token->token = malloc(sizeof(char ) * ft_lstsize(token) + 1);

                token->token[a] = newtoken(token, media,  i , filename,a);
            }
            a++;
            
        }
        i++;
            
    }

}


void guardar_modelo_binario(t_token *token, const char *archivo) {
    FILE *fp = fopen(archivo, "wb");
    if (!fp) {
        perror("Error al abrir archivo para escritura binaria");
        return;
    }
    token->num_tokens = ft_lstsize(token);

    // Guardar num_tokens
    fwrite(&token->num_tokens, sizeof(int), 1, fp);
    int i = 0;
    while(i <token->num_tokens)
    {
        int len = strlen(token->token[i]) + 1;
        fwrite(&len, sizeof(int), 1, fp);
        fwrite(token->token[i], sizeof(char), len, fp);

        i++;
    }
    // Guardar filename: longitud + datos
    int len_filename = strlen(token->filename) + 1;
    fwrite(&len_filename, sizeof(int), 1, fp);
    fwrite(token->filename, sizeof(char), len_filename, fp);

    // Guardar filenamecorpus: longitud + datos
    int len_filenamecorpus = strlen(token->filenamecorpus) + 1;
    fwrite(&len_filenamecorpus, sizeof(int), 1, fp);
    fwrite(token->filenamecorpus, sizeof(char), len_filenamecorpus, fp);

    // Guardar close (flag simple)
    fwrite(&token->close, sizeof(int), 1, fp);

    // Agrega más campos si es necesario (e.g., media, dimensiones)
    fclose(fp);
    printf("Modelo guardado en binario exitosamente en %s\n", archivo);

}

t_token *cargar_modelo_binario(const char *archivo) {
    FILE *fp = fopen(archivo, "rb");
    if (!fp) {
        perror("Error al abrir archivo para lectura binaria");
        return NULL;
    }

    t_token *token = malloc(sizeof(t_token));
    if (!token) {
        fclose(fp);
        return NULL;
    }

    // Leer num_tokens
    fread(&token->num_tokens, sizeof(int), 1, fp);

    // Alloc y leer tokens
    token->token = malloc(sizeof(char*) * token->num_tokens);
    for (int i = 0; i < token->num_tokens; i++) {
        int len;
        fread(&len, sizeof(int), 1, fp);
        token->token[i] = malloc(sizeof(char) * len);
        fread(token->token[i], sizeof(char), len, fp);
    }

    // Leer filename
    int len_filename;
    fread(&len_filename, sizeof(int), 1, fp);
    token->filename = malloc(sizeof(char) * len_filename);
    fread(token->filename, sizeof(char), len_filename, fp);

    // Leer filenamecorpus
    int len_filenamecorpus;
    fread(&len_filenamecorpus, sizeof(int), 1, fp);
    token->filenamecorpus = malloc(sizeof(char) * len_filenamecorpus);
    fread(token->filenamecorpus, sizeof(char), len_filenamecorpus, fp);

    // Leer close
    fread(&token->close, sizeof(int), 1, fp);

    // Agrega más campos si es necesario
    fclose(fp);
    printf("Modelo cargado en binario exitosamente desde %s\n", archivo);
    return token;
}


int main(int ac, char **av)
{
    if(ac > 0)
    {
        t_token *token = calloc(1, sizeof(t_token*));
        if(strcmp(av[1] , "train") == 0) 
        {
            
            token->filename = "vocales.txt";
            token->filenamecorpus ="hola.txt";
            cargarvocabulario(token);
            
            readcorpus(token, 20, 300);
            
            guardar_modelo_binario(token, "tokenizer.bin");
        }
        else
            return 1;
    }
    return 0;
}