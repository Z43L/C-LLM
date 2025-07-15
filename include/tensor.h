#ifndef TENSOR_H
#define TENSOR_H

#include <stdlib.h>
#include <stdio.h>
#include "tokenizador.h"
// estructura para representar un tensor 
// Tensor struct: Contiene las dimensiones (rows, cols), un puntero data 
// para los valores numéricos y un puntero grad para los gradientes que calcularemos en la Fase 3.

/*
 * rows ---> numero de filas
 * cols ---> nuemro de  columnas
 * data ---> puntero a los datos(almacenados en un array 1D);
 * grad ---> puntero a los gradientes correspondientes
 */

typedef struct s_tensor{
	int rows;
	int cols;
	float *data;
	float *grad;
}	t_tensor;

// Creacion y destrucion
t_tensor* create_tensor(int rows, int cols);
void free_tensor(t_tensor *t);


//Funciones de utilidad
void print_tensor(const t_tensor* t, const char* name);
void fill_tensor_random(t_tensor* t, float scale);


#endif
