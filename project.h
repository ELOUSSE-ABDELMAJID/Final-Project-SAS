#ifndef PROJECT_H
# define PROJECT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// --> Structures Section

struct Product {
	char	code[15];
	char	nom[25];
	int		quantity;
	float	prix;
	float	prixTtc;
	int		date[3];
};

// --> Functions Section

// Operations on Products Functions

void    add_product(int n);
void    buy_product();
void    modifyProductQuantity();
void    remove_product();

// List Products Functions

void	list_products();
void    listProductsByName();
void    listProductsByPrice();
void	listProductByIndex(int index);

// Display Menus Functions

void    display_menu();
void    displaySearchMenu();
void    displayStatistiqueMenu();

// Search for Products Functions
void    findProductsByCode();
void    findProductsByQuantity();
void    findInferiourProductsQuantity();

// Statistiques Functions

float    totalProductsSold();
float    averageProductsSold();

// Files Functions
 
void    saveDataFile();
void    readDataFromFile();

void    exit_funct();

#endif