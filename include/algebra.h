# ifndef ALGEBRA_H
# define ALGEBRA_H

#include "tokenizador.h"


typedef struct s_algrebra
{
    char caracter;
    char palabra;
    int frecuencia;
    struct s_algebra **vector;

} t_algebra;

#endif