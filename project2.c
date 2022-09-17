#include "project.h"

void    func_menu()
{

    int op, n;
	printf("##################- MENU -################\n");
    printf("# 1) Ajouter un seul produit ou plusieurs#\n");
    printf("# 2) Lister les produits#\n");
    printf("# 3) Acheter un produit#\n");
    printf("# 4) Rechercher un produit#\n");
	printf("Choose an operation :\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Entrez le nombre de Produit a ajouter :\n");
        scanf("%d", &n);
        add_product(n);
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    default:
        printf("Entrez un nombre entre (1 - 4)\n");
        break;
    }
    
}