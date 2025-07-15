#ifndef TOKENIZADOR_H
#define TOKENIZADOR_H


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "algebra.h"

typedef struct s_embeding{
    int rows;
    int cols;
    float *data;
    float *grad;
    char **multitoken;
}   t_embeding;

typedef struct s_token
{
    int num_tokens;
    char **token;
    int **frecuencia;
    char **newtoken;
    struct s_token *nextoken;
    char *filename;
    int  close;
    char *filenamecorpus;
    t_embeding *embeding;
} t_token;
char **ft_split(char *str, char c) ;

#endif