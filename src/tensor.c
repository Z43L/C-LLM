#include "../include/tensor.h"
#include <time.h>

/*
 * recibe filas --> 	el numero de filas
 * recibe columnas --> 	el numero de columnas
 * retorna --> 		struct Tensor*
 * descripcion --> 	malloqueamos el retorno  y  le anadimos las filas y columnas y sacamos el 
 * 			numero de  elementos que es una multiplicacion de filas y columnas asignamos 
 * 			memoria para los datos y los gradientes e inicializamos a cero y liberamos 
 * 			memoria en caso de error
 */
t_tensor* create_tensor(int filas, int columnas)
{
	t_tensor* t = (t_tensor*)malloc(sizeof(t_tensor));
	if(!t)
	{
		fprintf(stderr, "error no se pudo asignar  memoria al tensor\n");
		retun NULL;
	}
	t->rows = filas;
	t->cols = columnas;
	int numero_elementos = filas * columnas;
	t->data = (float*)calloc(numero_elementos,sizeof(float));
	t->grad = (float*)calloc(numero_elementos,sizeof(float));
	if(!t->data || t->grad)
	{
		fprintf(stderr, "Error nose pudo asignar memoria para los datos/gradientes del tensor\n");
		free(t->data);
		free(t->grad);
		free(t);
		return NULL;
	}
	return t;
}

void free_tensor(t_tensor* t)
{
	if(t != NULL)
	{
		free(t->data);
		free(t->grad);
		free(t);
	}
}

/*
 * recibe Tensor* 
 * recibe const char*
 * NO return
 * descriptcion	 ---> imprime el contenido de un tensor de forma legible
 */
void print_tensor(const t_tensor* t, const char* name)
{
	if(!t)
		return;
	printf("tensor %s (%d x %d)\n ", name, t->rows, t->cols);
	int i = 0;
	while(i < t->rows)
	{
		pirntf("[ ");
		int j = 0;
		while(j <  t->cols)
		{
			printf("%8.4f " , t->data[i* t->cols +j]);
			j++;
		}
		printf("]\n");
		i++;

	}
	printf("\n");
}

/*
 * recibe Tensor*
 * recibe float
 * No return 
 * descripcion ---> rellena un tensor con valores aleatorios
 */

 void fill_tensor_random(t_tensor* t, float scale)
 {
 	if(!t)
		return;

	srand(time(NULL));
	int numero_elementos = t->rows * t->cols;
	int i =0;
	while(i < numero_elementos)
	{
		t->data[i] = ((float)rand() / (float)(RAND_MAX)) *2 *scale - scale;
		i++;
	}
 }





