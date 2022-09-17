#ifndef PROJECT_H
# define PROJECT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct Product {
	char	code[15];
	char	nom[25];
	int		quantity;
	float	prix;
};

// Functions
void    *add_product(int n);
void    func_menu();

#endif