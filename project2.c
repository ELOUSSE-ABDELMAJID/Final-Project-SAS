#include "project.h"

void    displaySearchMenu()
{

    int op, n;
	printf("\t\t\t  =====================================================================================================\n");
	printf("\t\t\t                                                Search MENU                                            \n");
	printf("\t\t\t  =====================================================================================================\n");
    printf("\t\t\t   1) Rechercher un produit par son code  \n");
    printf("\t\t\t   2) Rechercher un produit par son quantite \n");
    printf("\t\t\t   3) Afficher les produits dont la quantité est inférieure a 3\n");
    printf("\n");
	printf("\t\t\t  Choose The number of your operation : ");
    scanf("\t\t\t %d", &op);
    printf("\n");
    switch (op)
    {
    case 1:
        findProductsByCode();
        break;
    case 2:
        findProductsByQuantity();
        break;
    case 3:
        findInferiourProductsQuantity();
        break;
    default:
        printf("\nEntrez un nombre entre (1 - 3)\n");
        display_menu();
        break;
    }
    
}

void    display_menu()
{

    int op, n;
	printf("\t\t\t  =====================================================================================================\n");
	printf("\t\t\t                                                MENU                                                    \n");
	printf("\t\t\t  =====================================================================================================\n");
    printf("\t\t\t   1) Ajouter un seul produit   \n");
    printf("\t\t\t   2) Ajouter Plusieurs Produit \n");
    printf("\t\t\t   3) Lister les produits on ordre alphabetique croissant du nom\n");
    printf("\t\t\t   4) Lister les produits selon l'ordre décroissant du prix \n");
    printf("\t\t\t   5) Acheter un produit \n");
    printf("\t\t\t   6) Rechercher un produit \n");
    printf("\t\t\t   7) Alimenter le stock \n");
    printf("\t\t\t   8) Supprimer une produit \n");
    printf("\t\t\t   9) Statistique de vente \n");
    printf("\n");
	printf("\t\t\t  Choose The number of your operation : ");
    scanf("\t\t\t %d", &op);
    printf("\n");
    switch (op)
    {
    case 1:
        add_product(1);
        display_menu();
        break;
    case 2:
        printf("Entrez le nombre de Produit a ajouter : ");
        scanf("%d", &n);
        add_product(n);
        display_menu();
        break;
    case 3:
        listProductsByName();
        display_menu();
        break;
    case 4:
        listProductsByPrice();
        display_menu();
        break;
    case 5:
        buy_product();
        display_menu();
        break;
    case 6:
        displaySearchMenu();
        display_menu();
        break;
    case 7:
        modifyProductQuantity();
        break;
    case 8:
        
        break;
    case 9:

        break;
    default:
        printf("\t\t\t  #####################################################################################################\n");
	    printf("\t\t\t                                                NUMBER NOT FOUND IN MENU                               \n");
        printf("\t\t\t  #####################################################################################################\n");
        display_menu();
        break;
    }  
}