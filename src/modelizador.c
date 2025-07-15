#include "../include/tokenizador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h> // For isspace

// Assuming t_token structure is defined in tokenizador.h
// typedef struct s_token {
//     char **token; // Array of token strings
//     int num_tokens; // Current count of tokens in the array
//     char *filename; // Path to the vocabulary file (output)
//     char *filenamecorpus; // Path to the corpus file (input)
//     int close; // Flag for errors or completion
//     struct s_token *nextoken; // If you are building a linked list (currently unused in this context)
// } t_token;

// --- Your existing functions (assuming they are in tokenizador.h or included before) ---
// char **ft_split(char *str, char c);
// void addtoken(t_token *token, char *newtoken);
// ... other utility functions ...
// --- End of existing functions ---


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


// --- Modified `addtoken` (ensuring it works as expected for a dynamic array) ---
void addtoken(t_token *token_data, char *new_token_str) {
    if (!new_token_str || strlen(new_token_str) == 0) return;

    // Check for duplicates to build a unique vocabulary
    for (int i = 0; i < token_data->num_tokens; i++) {
        if (token_data->token[i] && strcmp(token_data->token[i], new_token_str) == 0) {
            return; // Token already exists, do not add
        }
    }

    // Resize array
    char **new_array = realloc(token_data->token, sizeof(char *) * (token_data->num_tokens + 1));
    if (!new_array) {
        perror("Failed to realloc for new token");
        return;
    }
    token_data->token = new_array;

    // Copy new token string
    token_data->token[token_data->num_tokens] = strdup(new_token_str);
    if (!token_data->token[token_data->num_tokens]) {
        perror("Failed to strdup new token");
        // Robust error handling would involve rolling back realloc or exiting
        return;
    }

    token_data->num_tokens++;
}
// --- End of Modified `addtoken` ---


// --- Manual JSON String Extraction Function (from previous response) ---
char *extract_json_string_value(const char *json_obj_str, const char *target_key) {
    const char *ptr = json_obj_str;
    char *extracted_value = NULL;
    size_t target_key_len = strlen(target_key);

    // Skip initial whitespace and '{'
    while (*ptr && isspace((unsigned char)*ptr)) ptr++;
    if (*ptr == '{') ptr++;
    else return NULL; // Not a JSON object

    while (*ptr) {
        // Skip whitespace
        while (*ptr && isspace((unsigned char)*ptr)) ptr++;

        // Expect opening quote for key
        if (*ptr != '"') break; // Malformed JSON or end of object
        ptr++; // Move past opening quote

        // Extract key name
        const char *key_start = ptr;
        while (*ptr && *ptr != '"') {
            if (*ptr == '\\' && *(ptr + 1) != '\0') ptr++; // Skip escaped char
            ptr++;
        }
        if (*ptr != '"') break; // Malformed key string
        size_t current_key_len = ptr - key_start;
        ptr++; // Move past closing quote

        // Skip whitespace after key
        while (*ptr && isspace((unsigned char)*ptr)) ptr++;

        // Expect colon
        if (*ptr != ':') break; // Malformed JSON
        ptr++; // Move past colon

        // Skip whitespace after colon
        while (*ptr && isspace((unsigned char)*ptr)) ptr++;

        // Check if this is our target key
        if (current_key_len == target_key_len && strncmp(key_start, target_key, target_key_len) == 0) {
            // Found target key, now extract its value
            if (*ptr != '"') {
                // Not a string value, or malformed JSON
                return NULL;
            }
            ptr++; // Move past opening quote of value

            const char *value_start = ptr;
            while (*ptr && *ptr != '"') {
                if (*ptr == '\\' && *(ptr + 1) != '\0') { // Basic handling of escaped chars
                    ptr++; // Skip the '\'
                }
                ptr++;
            }
            if (*ptr != '"') {
                // Unclosed string or malformed value
                return NULL;
            }
            size_t value_len = ptr - value_start;

            extracted_value = malloc(value_len + 1);
            if (!extracted_value) {
                perror("Failed to allocate memory for JSON value");
                return NULL;
            }
            // Copy the value, handling escaped quotes
            size_t i = 0;
            size_t j = 0;
            while (i < value_len) {
                if (value_start[i] == '\\' && value_start[i+1] == '"') {
                    extracted_value[j++] = '"'; // Unescape \"
                    i += 2;
                } else {
                    extracted_value[j++] = value_start[i++];
                }
            }
            extracted_value[j] = '\0'; // Null-terminate

            return extracted_value; // Found and extracted, return
        }

        // If not target key, skip its value to continue parsing
        if (*ptr == '"') { // It's a string value
            ptr++; // Skip opening quote
            while (*ptr && *ptr != '"') {
                 if (*ptr == '\\' && *(ptr + 1) != '\0') ptr++; // Skip escaped char
                 ptr++;
            }
            if (*ptr != '"') break; // Malformed string
            ptr++; // Skip closing quote
        } else { // Handle other value types (numbers, booleans, nulls, objects, arrays) - rudimentary
            int brace_count = 0;
            int bracket_count = 0;
            if (*ptr == '{') { brace_count++; }
            if (*ptr == '[') { bracket_count++; }

            while (*ptr && (brace_count > 0 || bracket_count > 0 || (*ptr != ',' && *ptr != '}'))) {
                if (*ptr == '{') brace_count++;
                else if (*ptr == '}') brace_count--;
                else if (*ptr == '[') bracket_count++;
                else if (*ptr == ']') bracket_count--;
                ptr++;
            }
            if (brace_count > 0 || bracket_count > 0) break; // Unclosed structure
        }

        // Skip whitespace
        while (*ptr && isspace((unsigned char)*ptr)) ptr++;

        // Expect comma or end of object
        if (*ptr == ',') {
            ptr++; // Move past comma, continue loop
        } else if (*ptr == '}') {
            break; // End of object
        } else {
            break; // Malformed JSON
        }
    }

    return NULL; // Key not found or parsing error
}


// --- Function to read and tokenize the JSONL corpus (Manual Parsing) ---
void read_and_tokenize_jsonl_corpus(t_token *token_data, const char *jsonl_filepath) {
    FILE *fp = fopen(jsonl_filepath, "r");
    if (!fp) {
        perror("Error opening corpus file");
        token_data->close = 1;
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read_bytes;
    int line_num = 0;

    printf("Reading and tokenizing corpus from %s (manual JSON parsing)...\n", jsonl_filepath);

    while ((read_bytes = getline(&line, &len, fp)) != -1) {
        line_num++;
        // Remove trailing newline character if present
        if (read_bytes > 0 && line[read_bytes - 1] == '\n') {
            line[read_bytes - 1] = '\0';
        }

        char *code_snippet = extract_json_string_value(line, "code");

        if (code_snippet) {
            char **tokens_from_snippet = ft_split(code_snippet, ' '); // Simple space split for now

            if (tokens_from_snippet) {
                for (int i = 0; tokens_from_snippet[i] != NULL; i++) {
                    addtoken(token_data, tokens_from_snippet[i]); // Add token to the vocabulary
                    free(tokens_from_snippet[i]);
                }
                free(tokens_from_snippet);
            }
            free(code_snippet);
        } else {
            fprintf(stderr, "Warning: 'code' field not found or malformed JSON on line %d. Skipping line.\n", line_num);
        }

        if (line_num % 10000 == 0) {
            printf("Processed %d lines. Current unique tokens: %d\n", line_num, token_data->num_tokens);
        }
    }

    free(line);
    fclose(fp);
    printf("Finished reading corpus. Total unique tokens collected: %d\n", token_data->num_tokens);
    token_data->close = 0;
}
// --- End of `read_and_tokenize_jsonl_corpus` ---


// --- NEW: Function to load initial BPE vocabulary from a file ---
void load_initial_bpe_vocabulary(t_token *token_data, const char *bpe_vocab_filepath) {
    FILE *fp = fopen(bpe_vocab_filepath, "r");
    if (!fp) {
        perror("Error opening initial BPE vocabulary file");
        return; // Don't set token_data->close, as it's not a fatal error for the whole process
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read_bytes;
    int token_count = 0;

    printf("Loading initial BPE vocabulary from %s...\n", bpe_vocab_filepath);

    while ((read_bytes = getline(&line, &len, fp)) != -1) {
        // Remove trailing newline character if present
        if (read_bytes > 0 && line[read_bytes - 1] == '\n') {
            line[read_bytes - 1] = '\0';
        }

        // Add the line as a BPE token to the vocabulary
        if (strlen(line) > 0) { // Only add non-empty lines
            addtoken(token_data, line);
            token_count++;
        }
    }

    free(line);
    fclose(fp);
    printf("Loaded %d initial BPE tokens. Total unique tokens now: %d\n", token_count, token_data->num_tokens);
}
// --- End of NEW function ---


// --- Your existing `guardar_modelo_binario`, `cargar_modelo_binario`, `free_token_data`, `main` ---

void guardar_modelo_binario(t_token *token, const char *archivo) {
    FILE *fp = fopen(archivo, "wb");
    if (!fp) {
        perror("Error al abrir archivo para escritura binaria");
        return;
    }

    fwrite(&token->num_tokens, sizeof(int), 1, fp);
    for (int i = 0; i < token->num_tokens; i++) {
        int len = strlen(token->token[i]) + 1; // +1 for null terminator
        fwrite(&len, sizeof(int), 1, fp);
        fwrite(token->token[i], sizeof(char), len, fp);
    }

    int len_filename = (token->filename ? strlen(token->filename) : 0) + 1;
    fwrite(&len_filename, sizeof(int), 1, fp);
    if (token->filename) fwrite(token->filename, sizeof(char), len_filename, fp);

    int len_filenamecorpus = (token->filenamecorpus ? strlen(token->filenamecorpus) : 0) + 1;
    fwrite(&len_filenamecorpus, sizeof(int), 1, fp);
    if (token->filenamecorpus) fwrite(token->filenamecorpus, sizeof(char), len_filenamecorpus, fp);

    fwrite(&token->close, sizeof(int), 1, fp);

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
    memset(token, 0, sizeof(t_token)); // Initialize to zeros

    fread(&token->num_tokens, sizeof(int), 1, fp);

    token->token = malloc(sizeof(char*) * token->num_tokens);
    for (int i = 0; i < token->num_tokens; i++) {
        int len;
        fread(&len, sizeof(int), 1, fp);
        token->token[i] = malloc(sizeof(char) * len);
        fread(token->token[i], sizeof(char), len, fp);
    }

    int len_filename;
    fread(&len_filename, sizeof(int), 1, fp);
    token->filename = malloc(sizeof(char) * len_filename);
    fread(token->filename, sizeof(char), len_filename, fp);

    int len_filenamecorpus;
    fread(&len_filenamecorpus, sizeof(int), 1, fp);
    token->filenamecorpus = malloc(sizeof(char) * len_filenamecorpus);
    fread(token->filenamecorpus, sizeof(char), len_filenamecorpus, fp);

    fread(&token->close, sizeof(int), 1, fp);

    fclose(fp);
    printf("Modelo cargado en binario exitosamente desde %s\n", archivo);
    return token;
}

// Function to free t_token structure and its contents
void free_token_data(t_token *token) {
    if (!token) return;

    if (token->token) {
        for (int i = 0; i < token->num_tokens; i++) {
            free(token->token[i]);
        }
        free(token->token);
    }
    free(token->filename);
    free(token->filenamecorpus);
    free(token->nextoken); // If it's a linked list
    free(token);
}


int main(int ac, char **av) {
    if (ac > 1) {
        t_token *token_data = calloc(1, sizeof(t_token)); // Use calloc for zero-initialization
        if (!token_data) {
            perror("Failed to allocate t_token");
            return 1;
        }
        // Initialize pointers to NULL
        token_data->token = NULL;
        token_data->filename = NULL;
        token_data->filenamecorpus = NULL;
        token_data->nextoken = NULL; // Assuming no linked list of tokenizers

        if (strcmp(av[1], "train") == 0 && ac > 3) { // Now expects 3 arguments: program_name train bpe_vocab_path corpus_path
            const char *bpe_vocab_path = av[2];
            const char *corpus_path = av[3];

            token_data->filenamecorpus = strdup(corpus_path); // Corpus file path from arg
            token_data->filename = strdup("programming_vocabulary.bin"); // Output vocabulary file name

            // --- NEW: Load initial BPE vocabulary ---
            load_initial_bpe_vocabulary(token_data, bpe_vocab_path);
            printf("Initial vocabulary size after BPE load: %d\n", token_data->num_tokens);

            // Then, process the main corpus
            read_and_tokenize_jsonl_corpus(token_data, token_data->filenamecorpus);

            guardar_modelo_binario(token_data, token_data->filename); // Save the trained vocabulary

            free_token_data(token_data); // Clean up memory
        } else if (strcmp(av[1], "load") == 0 && ac > 2) {
            t_token *loaded_token_data = cargar_modelo_binario(av[2]);
            if (loaded_token_data) {
                printf("Loaded tokenizer model with %d unique tokens.\n", loaded_token_data->num_tokens);
                // Print a few tokens to verify
                printf("First 10 tokens:\n");
                for (int i = 0; i < (loaded_token_data->num_tokens > 10 ? 10 : loaded_token_data->num_tokens); i++) {
                    printf("  %s\n", loaded_token_data->token[i]);
                }
                free_token_data(loaded_token_data); // Clean up memory
            } else {
                fprintf(stderr, "Failed to load model from %s\n", av[2]);
            }
        } else {
            fprintf(stderr, "Usage:\n");
            fprintf(stderr, "  %s train <path_to_bpe_vocab_file> <path_to_jsonl_corpus_file>\n", av[0]);
            fprintf(stderr, "  %s load <path_to_tokenizer_bin_file>\n", av[0]);
            free_token_data(token_data);
            return 1;
        }
    } else {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "  %s train <path_to_bpe_vocab_file> <path_to_jsonl_corpus_file>\n", av[0]);
        fprintf(stderr, "  %s load <path_to_tokenizer_bin_file>\n", av[0]);
        return 1;
    }
    return 0;
}