#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


void add_item(Item *item_list, double price, char *sku,
              char *category, char *name, int index);

void free_items(Item *item_list, int size);

double average_price(Item *item_list, int size);

void print_items(Item *item_list, int size);


int main(int argc, char *argv[])
{
    int size = 5;

    // Check that the user entered a SKU
    if(argc != 2)
    {
        printf("Incorrect amount of arguments\n");
        return 1;
    }

    // Dynamically allocate an array of 5 Items
    Item *item_list = malloc(size * sizeof(Item));

    if(item_list == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }


    // Add 5 grocery store items
    add_item(item_list, 5.00, "19282",
             "breakfast", "reese's cereal", 0);

    add_item(item_list, 3.95, "79862",
             "dairy", "milk", 1);

    add_item(item_list, 2.50, "14512",
             "produce", "apples", 2);

    add_item(item_list, 4.25, "56321",
             "bakery", "bread", 3);

    add_item(item_list, 7.99, "82451",
             "meat", "chicken", 4);


    // Print all items
    print_items(item_list, size);


    // Calculate and print average price
    double average = average_price(item_list, size);

    printf("average price of items = %f\n", average);


    // Search for the SKU entered through the command line
    char *sku = argv[1];

    int ct = 0;

    while(ct < size && strcmp(item_list[ct].sku, sku) != 0)
    {
        ct++;
    }


    // Check if item was found
    if(ct < size)
    {
        printf("\nItem found:\n");
        printf("###############\n");
        printf("item name = %s\n", item_list[ct].name);
        printf("item sku = %s\n", item_list[ct].sku);
        printf("item category = %s\n", item_list[ct].category);
        printf("item price = %f\n", item_list[ct].price);
        printf("###############\n");
    }
    else
    {
        printf("item not found\n");
    }


    // Free all dynamically allocated memory
    free_items(item_list, size);

    return 0;
}


void add_item(Item *item_list, double price, char *sku,
              char *category, char *name, int index)
{
    // Store price
    item_list[index].price = price;


    // Allocate memory for SKU
    item_list[index].sku =
        malloc((strlen(sku) + 1) * sizeof(char));

    // Copy SKU into allocated memory
    strcpy(item_list[index].sku, sku);


    // Allocate memory for category
    item_list[index].category =
        malloc((strlen(category) + 1) * sizeof(char));

    // Copy category into allocated memory
    strcpy(item_list[index].category, category);


    // Allocate memory for name
    item_list[index].name =
        malloc((strlen(name) + 1) * sizeof(char));

    // Copy name into allocated memory
    strcpy(item_list[index].name, name);
}


void free_items(Item *item_list, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }

    free(item_list);
}


double average_price(Item *item_list, int size)
{
    double total = 0.0;
    int i;

    for(i = 0; i < size; i++)
    {
        total = total + item_list[i].price;
    }

    return total / size;
}


void print_items(Item *item_list, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
    }

    printf("###############\n");
}
