#include "project.h"

struct Product prod[100];
struct Product sold[100];
static int size = 0;
static int s = 0;
// Files Functions

void    readDataFromFile()
{
    FILE *database = fopen("database.txt", "r");
    while (1)
    {
       fscanf(database, "%d\t%s\t%s\t%d\t%f\t%f", &size+1, prod[size].code, prod[size].nom, &prod[size].quantity, &prod[size].prix, &prod[size].prixTtc);
       if (feof(database))
            break;
       size++;
    }
    fclose(database);
}

void    saveDataFile()
{
    int i = 0;

    FILE *database = fopen("database.txt", "w");
    while (i < size)
    {
        fprintf(database, "%d\t%s\t%s\t%d\t%.2f\t%.2f\n", i+1, prod[i].code, prod[i].nom, prod[i].quantity, prod[i].prix, prod[i].prixTtc);
        i++;
    }
    fclose(database);
}

// Operations on Products Functions

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
        size++;
        i++;
    }
    for (i = 0; i < size; i++)
    {
        prod[i].prixTtc = prod[i].prix * 0.15 + prod[i].prix;
    }
    printf("\t\t\t  #####################################################################################################\n");
    printf("\t\t\t                                              PRODUCT ADDED SUCCESSFULLY                               \n");
	printf("\t\t\t  #####################################################################################################\n");
    saveDataFile();
}

void    buy_product()
{
    char id[15];
    int i = 0;
    int quantite;
    time_t tm;
    time(&tm);
    struct tm *date = localtime(&tm);

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
        prod[i].date[0] = date->tm_mday;
        prod[i].date[1] = date->tm_mon+1;
        prod[i].date[2] = date->tm_year+1900;
        // Save products sold in the sold array
        strcpy(sold[s].code,prod[i].code);
        strcpy(sold[s].nom,prod[i].nom);
        sold[s].quantity = prod[i].quantity;
        sold[s].prix = prod[i].prix;
        sold[s].prixTtc = prod[i].prixTtc;
        sold[s].date[0] = prod[i].date[0];
        sold[s].date[1] = prod[i].date[1];
        sold[s].date[2] = prod[i].date[2];
        s++;
        printf("\t\t\t  #####################################################################################################\n");
	    printf("\t\t\t                                                PRODUCT BUY SUCCESSFUL                                 \n");
	    printf("\t\t\t  #####################################################################################################\n");
        saveDataFile();
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
    saveDataFile();
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
                strcpy(prod[j].code,prod[j + 1].code);
                strcpy(prod[j].nom,prod[j + 1].nom);
                prod[j].quantity = prod[j + 1].quantity;
                prod[j].prix = prod[j + 1].prix;
                prod[j].prixTtc = prod[j + 1].prixTtc;
                prod[j].date[0] = prod[j + 1].date[0];
                prod[j].date[1] = prod[j + 1].date[1];
                prod[j].date[2] = prod[j + 1].date[2];
            }
            size--;
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
    saveDataFile();
    display_menu();
}

// List Products Functions

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

// Search for Products Functions

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

// Staitstiques Functions

float    totalProductsSold()
{
    int i = 0;
    float total = 0;
    time_t tm;
    time(&tm);
    struct tm *date = localtime(&tm);

    while (i < s)
    {
        if (sold[i].date[0] == date->tm_mday && sold[i].date[1] == date->tm_mon+1 && sold[i].date[2] == date->tm_year+1900)
            total += sold[i].prix;
        i++;
    }
    return total;
}

float    averageProductsSold()
{
    int i = 0;
    float average = 0;
    int count = 0;
    time_t tm;
    time(&tm);
    struct tm *date = localtime(&tm);

    while (i < s)
    {
       if (sold[i].date[0] == date->tm_mday && sold[i].date[1] == date->tm_mon+1 && sold[i].date[2] == date->tm_year+1900)
            count++;
        i++;
    }
    average = totalProductsSold() / count; 
    return average;
}

float  maxProductsSold()
{
    int i = 0;
    float max;
    time_t tm;
    time(&tm);
    struct tm *date = localtime(&tm);

    max = sold[i].prix;
    while (i < s)
    {
       if (sold[i].date[0] == date->tm_mday && sold[i].date[1] == date->tm_mon+1 && sold[i].date[2] == date->tm_year+1900)
       {
            if (sold[i].prix > max)
                max = sold[i].prix;
       }
       i++;
    }
    return max;
}

float   minProductsSold()
{
    int i = 0;
    float min;
    time_t tm;
    time(&tm);
    struct tm *date = localtime(&tm);

    min = sold[i].prix;
    while (i < s)
    {
       if (sold[i].date[0] == date->tm_mday && sold[i].date[1] == date->tm_mon+1 && sold[i].date[2] == date->tm_year+1900)
       {
            if (sold[i].prix < min)
                min = sold[i].prix;
       }
       i++;
    }
    return min;
}

// main function 

int main()
{
    readDataFromFile();
	display_menu();
    return 0;
}