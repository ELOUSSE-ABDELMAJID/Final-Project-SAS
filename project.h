#ifndef PROJECT_H
# define PROJECT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure
struct Product {
	char	code[15];
	char	nom[25];
	int		quantity;
	float	prix;
	float	prixTtc;
	int		date[3];
};

// Functions
void    add_product(int n);
void    display_menu();
void	list_products();
void    listProductsByName();
void    listProductsByPrice();
void	listProductByIndex(int index);
void    buy_product();
void    findProductsByCode();
void    findProductsByQuantity();
void    displaySearchMenu();
void    findInferiourProductsQuantity();
void    modifyProductQuantity();
void    remove_product();
void    displayStatistiqueMenu();
void    totalProductsSold();
void    averageProductsSold();

#endif