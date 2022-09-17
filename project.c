#include "project.h"

void  *add_product(int n)
{
    struct Product produit[50];
    int i = 0;
    while (i < n)
    {
        fflush(stdin);
        printf("Entrez le code du Produit :\n");
        scanf("%s", produit[i].code);
        printf("Entrez le nom du Produit :\n");
        scanf("%s", produit[i].nom);
        printf("Entrez la quantite du Produit :\n");
        scanf("%d", &produit[i].quantity);
        printf("Entrez le prix du Produit :\n");
        scanf("%f", &produit[i].prix);
        i++;
    }
}

void	list_products()
{
	
}

void	buy_product()
{
	
}

void	search_product()
{
	
}

void	remove_product()
{
		
}

void	print_products()
{
	
}

// main function 
int main() {
	func_menu();
    return 0;
}