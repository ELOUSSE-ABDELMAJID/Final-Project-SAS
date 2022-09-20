#include "project.h"

struct Product prod[100];
static int size = 0;

void    fillWithData()
{
    int i = 0;

    FILE *database = fopen("database.txt", "r");
    while (1)
    {
       //fscanf(database, "%s%s%d%f", prod[i].code, prod[i].nom, prod[i].quantity, prod[i].prix);
       if (feof)
        break;
       i++;
    }
    fclose(database);
}

void    saveData(int i)
{
    //FILE *database = fopen("database.txt", 'a');
    //while (i < count)
       // fprintf(database, "%s%s%d%.2f", prod[i].code, prod[i].nom, prod[i].quantity, prod[i].prix);
}

// int    checkCode(struct Product produit)
// {
//     while (produit.code[0] == '\0')
//     {
//         fillWithData();
//         while (i < count)
//         {
//             if (strcmp(tolower(produit->code), tolower(prod[i].code)) == 0)
//                 return (2);
//             i++;
//         }
        
//     }
//     return (1);
    
// }

void  add_product(int n)
{
    int i = 0;
    while (i < n)
    {
        fflush(stdin);
        printf("\t\t\t  # Product Number : %d\n", size+1);
        printf("\t\t\t  Entrez le code du Produit : ");
        scanf("%s", prod[size].code);
        printf("\t\t\t  Entrez le nom du Produit : ");
        scanf("%s", prod[size].nom);
        printf("\t\t\t  Entrez la quantite du Produit : ");
        scanf("%d", &prod[size].quantity);
        printf("\t\t\t  Entrez le prix du Produit : ");
        scanf("%f", &prod[size].prix);
        prod[i].prixTtc = prod[i].prix * 0.15 + prod[i].prix;
        size++;
        i++;
    }
}

void    listProductsByName()
{
    struct Product temp;
    int i, j;

    for(i = 0; i < size; i++)
    {
      for(j = i+1; j < size; j++)
      {
         if(strcmp(prod[i].nom,prod[j].nom) > 0)
         {
            strcpy(temp.nom,prod[i].nom);
            strcpy(temp.code,prod[i].code);
            temp.quantity = prod[i].quantity;
            temp.prix = prod[i].prix;
            strcpy(prod[i].nom,prod[j].nom);
            strcpy(prod[i].code,prod[j].code);
            prod[i].quantity = prod[j].quantity;
            prod[i].prix = prod[j].prix;
            strcpy(prod[j].nom,temp.nom);
            strcpy(prod[j].code,temp.code);
            prod[j].quantity = temp.quantity;
            prod[j].prix = temp.prix;
         }
      }
   }
   printf("\n\t\t\t  Les Produits selon l'ordre alphabétique croissant du nom :\n");
   list_products();
}

void    listProductsByPrice()
{
    int i, j;
    struct Product tmp;

    printf("\n\t\t\t  Les Produits selon l'ordre décroissant du prix :\n");
    for (i = 0; i < size; i++) 
    {
        for (j = i + 1; j < size; j++)
        {
            if (prod[i].prix < prod[j].prix)
            {
                tmp.prix = prod[i].prix;
                tmp.quantity = prod[i].quantity;
                strcpy(tmp.nom,prod[i].nom);
                strcpy(tmp.code,prod[i].code);
                prod[i].prix = prod[j].prix;
                prod[i].quantity = prod[j].quantity;
                strcpy(prod[i].nom,prod[j].nom);
                strcpy(prod[i].code,prod[j].code);
                prod[j].prix = tmp.prix;
                prod[j].quantity = tmp.quantity;
                strcpy(prod[j].nom,tmp.nom);
                strcpy(prod[j].code,tmp.code);
            }
        }
    }
    list_products();
}

void	list_products()
{
    int i = 0;

    printf("\t\t\t  -----------------------------------------------------\n");
    printf("\t\t\t  |  PROD ID  | PROD NOM |  PROD PRIX  | PROD PRIXTTC | \n");
    printf("\t\t\t  -----------------------------------------------------\n");
	while (i < size)
    {
        printf("\t\t\t      %d\t\t%s\t   %.2f\t     %.2f\n", i+1, prod[i].nom, prod[i].prix, prod[i].prixTtc);
        printf("\t\t\t  -----------------------------------------------------\n");
        i++;
    }
}

void	listProductByIndex(int index)
{
    printf("\t\t\t  -----------------------------------------------------\n");
    printf("\t\t\t  |  PROD ID  | PROD NOM |  PROD PRIX  | PROD PRIXTTC | \n");
    printf("\t\t\t  -----------------------------------------------------\n");
    printf("\t\t\t      %d\t\t%s\t   %.2f\t     %.2f\n", index+1, prod[index].nom, prod[index].prix, prod[index].prixTtc);
    printf("\t\t\t  -----------------------------------------------------\n");
}

void    buy_product()
{
    char id[15];
    int i = 0;
    int quantite;
    time_t t;

    t = time(NULL);
    printf("\t\t\t  Entrez le Code de Produit que vous voulez acheter : ");
    scanf("%s", id);
    while (i < size)
    {
        if (strcmp(prod[i].code, id) == 0)
            break;
        if (i == size - 1)
        {
            if (strcmp(prod[i].code, id) != 0)
            {
                printf("\t\t\t  #####################################################################################################\n");
	            printf("\t\t\t                                                Product Code Not Found                                 \n");
	            printf("\t\t\t  #####################################################################################################\n");
                display_menu();
            }
        }
        i++;
    }
    printf("\t\t\t  Entrez la quantite que vous voulez acheter : ");
    scanf("%d", &quantite);
    if (prod[i].quantity >= quantite)
    {
        prod[i].quantity -= quantite;
        prod[i].tim = *localtime(&t);
        printf("\t\t\t  #####################################################################################################\n");
	    printf("\t\t\t                                                Purchase Complete                                      \n");
	    printf("\t\t\t  #####################################################################################################\n");
        display_menu();
    }
    else
    {
        printf("\t\t\t  #####################################################################################################\n");
	    printf("\t\t\t                                                OUT OF STOCK                                           \n");
	    printf("\t\t\t  #####################################################################################################\n");
        display_menu();
    }
}

void    findProductsByCode()
{
    char id[15];
    int i = 0;

    printf("\t\t\t  Entrez le Code de Produit que vous voulez Rechercher : ");
    scanf("%s", id);
    while (i < size)
    {
        if (strcmp(prod[i].code, id) == 0)
            listProductByIndex(i);
        if (i == size - 1)
        {
            if (strcmp(prod[i].code, id) != 0)
            {
                printf("\t\t\t  #####################################################################################################\n");
	            printf("\t\t\t                                                Product Not Found                                      \n");
	            printf("\t\t\t  #####################################################################################################\n");
                printf("\n");
            }
        }
        i++;
    }
    display_menu();
}

void    findProductsByQuantity()
{
    int quantite;
    int i = 0;
    int found = 1;

    printf("\t\t\t  Entrez la quantite de Produit que vous voulez Rechercher : ");
    scanf("%d", &quantite);
    while (i < size)
    {
        if (prod[i].quantity == quantite)
        {
            listProductByIndex(i);
            found = 0;
        }
        i++;
    }
    if (found)
    {
        printf("\t\t\t  #####################################################################################################\n");
	    printf("\t\t\t                                                Product Not Found                                      \n");
        printf("\t\t\t  #####################################################################################################\n");
        printf("\n");
    }
    display_menu();
}

void    findInferiourProductsQuantity()
{
    int i = 0;

    printf("\t\t\t  Les Produits avec une quantite inferiour a 3 : \n");
    while (i < size)
    {
        if (prod[i].quantity < 3)
            listProductByIndex(i);
        i++;
    }
    display_menu();
}

void    modifyProductQuantity()
{
    int i = 0;
    char id[15];
    int quantite;

    printf("\t\t\t  Entrez le Code de Produit que vous voulez mofifier son quantite : ");
    scanf("%s", id);
    while (i < size)
    {
        if (strcmp(prod[i].code, id) == 0)
        {
            printf("\t\t\t  Entrez la quantity que vous voulez ajouter : ");
            scanf("%d", &quantite);
            prod[i].quantity += quantite;
            break;
        }
        if (i == size - 1)
        {
            if (strcmp(prod[i].code, id) != 0)
            {
                printf("\t\t\t  #####################################################################################################\n");
	            printf("\t\t\t                                                Product Code Not Found                                 \n");
	            printf("\t\t\t  #####################################################################################################\n");
            }
        }
        i++;
    }
    display_menu();
}

void    remove_product()
{
    char id[15];
    int i = 0;

    printf("\t\t\t  Entrez le Code de Produit que vous voulez Supprimer : ");
    scanf("%s", id);
    while (i < size)
    {
        if (strcmp(prod[i].code, id) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                prod[j] = prod[j + 1];
                size--;
            }
            printf("\t\t\t  #####################################################################################################\n");
	        printf("\t\t\t                                                Product Removed Successfully                           \n");
	        printf("\t\t\t  #####################################################################################################\n");
            break;
        }
        if (i == size - 1)
        {
            if (strcmp(prod[i].code, id) != 0)
            {
                printf("\t\t\t  #####################################################################################################\n");
	            printf("\t\t\t                                                Product Not Found                                      \n");
	            printf("\t\t\t  #####################################################################################################\n");
                printf("\n");
            }
        }
        i++;
    }
    display_menu();
}

void    totalProductsSold()
{
    int i = 0;
    time_t t;
    float total = 0;

    t = time(NULL);
    while (i < size)
    {
       if (prod[i].tim = *localtime(&t))
            total += prod[i].prix;
    }
    printf("\t\t\t  Le total des prix des produits vendus Ce journée : %.2f", total);
}

// main function 
int main()
{
	display_menu();
    return 0;
}