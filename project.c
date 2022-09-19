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
        printf("--> Product Number : %d\n", size+1);
        printf("Entrez le code du Produit :\n");
        scanf("%s", prod[size].code);
        printf("Entrez le nom du Produit :\n");
        scanf("%s", prod[size].nom);
        printf("Entrez la quantite du Produit :\n");
        scanf("%d", &prod[size].quantity);
        printf("Entrez le prix du Produit :\n");
        scanf("%f", &prod[size].prix);
        size++;
        i++;
    }
}

void    listProductsByName()
{
    char temp[100];
    int i, j;

    for(i = 0; i < size; i++)
    {
      for(j = i+1; j < size; j++)
      {
         if(strcmp(prod[i].nom,prod[j].nom) > 0)
         {
            strcpy(temp,prod[i].nom);
            strcpy(prod[i].nom,prod[j].nom);
            strcpy(prod[j].nom,temp);
         }
      }
   }
   printf("\nLes Produits selon l'ordre alphabétique croissant du nom :\n");
   list_products();
}

void    listProductsByPrice()
{
    int i, j;
    float tmp;
    for (i = 0; i < size; i++) 
    {
        for (j = i + 1; j < size; j++)
        {
            if (prod[i].prix < prod[j].prix)
            {
                tmp = prod[i].prix;
                prod[i].prix = prod[j].prix;
                prod[j].prix = tmp;
            }
        }
    }
    printf("\nLes Produits selon l'ordre décroissant du prix :\n");
    list_products();
}

void	list_products()
{
    int i = 0;
	while (i < size)
    {
        printf("--> Product ID : %d\n", i+1);
        printf("->Code : %s\n",prod[i].code);
        printf("->Nom : %s\n",prod[i].nom);
        printf("->Quantity : %d\n",prod[i].quantity);
        printf("->Prix : %.2f\n",prod[i].prix);
        i++;
    }
}

void	listProductByIndex(int index)
{
    printf("--> Product ID : %d\n", index+1);
    printf("-> Code : %s\n",prod[index].code);
    printf("-> Nom : %s\n",prod[index].nom);
    printf("-> Quantity : %d\n",prod[index].quantity);
    printf("-> Prix : %.2f\n",prod[index].prix);
}

void    buy_product()
{
    char id[15];
    int i = 0;
    int quantite;
    printf("Entrez le Code de Produit que vous voulez acheter : ");
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
    printf("Entrez la quantite que vous voulez acheter : ");
    scanf("%d", &quantite);
    if (prod[i].quantity >= quantite)
    {
        prod[i].quantity = prod[i].quantity - quantite;
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

    printf("Entrez le Code de Produit que vous voulez Rechercher : ");
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
                display_menu();
            }
        }
        i++;
    }
}

void    findProductsByQuantity()
{
    int quantite;
    int i = 0;
    int found = 1;

    printf("Entrez la quantite de Produit que vous voulez Rechercher : ");
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

    printf("Les Produits avec une quantite inferiour a 3 : \n");
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

    printf("Entrez le Code de Produit que vous voulez mofifier son quantite : ");
    scanf("%s", id);
    while (i < size)
    {
        if (strcmp(prod[i].code, id) == 0)
        {
            printf("Entrez la quantity que vous voulez ajouter : ");
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

    printf("Entrez le Code de Produit que vous voulez Supprimer : ");
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
                display_menu();
            }
        }
        i++;
    }
}

// main function 
int main()
{
	display_menu();
    return 0;
}