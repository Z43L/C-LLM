#ifndef TENSOR_H
#define TENSOR_H

#include <stdlib.h>
#include <stdio.h>

// estructura para representar un tensor 
// Tensor struct: Contiene las dimensiones (rows, cols), un puntero data 
// para los valores numéricos y un puntero grad para los gradientes que calcularemos en la Fase 3.

/*
 * rows ---> numero de filas
 * cols ---> nuemro de  columnas
 * data ---> puntero a los datos(almacenados en un array 1D);
 * grad ---> puntero a los gradientes correspondientes
 */

typedef struct {
	int rows;
	int cols;
	float *data;
	float *grad;
}

// Creacion y destrucion
Tensor* create_tensor(int rows, int cols);
void free_tensor(Tensor *t);


//Funciones de utilidad
void print_tensor(const Tensor* t, const char* name);
void fill_tensor_random(Tensor* t, float scale);


#endif
