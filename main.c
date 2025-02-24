#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
	item_list[index].price = (price);
	item_list[index].sku = strdup(sku); 
   	item_list[index].category = strdup(category);
    	item_list[index].name = strdup(name);
}

void free_items(Item *item_list, int size){
int i; 
	for (i = 0; i < size; i++){
	if (item_list[i].sku) {
            free(item_list[i].sku);  
        }
        if (item_list[i].category) {
            free(item_list[i].category);  	
        }
        if (item_list[i].name) {
            free(item_list[i].name);    
        }
    }
	free(item_list);
}

double average_price(Item *item_list, int size){
int i;
	double total_price = 0;
	for (i = 0; i < size; i++){
		total_price += item_list[i].price;
		}
	return total_price / size;
}


void print_items(Item *item_list, int size){
int i;
	for (i = 0; i < size; i++){
	printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %.6f\n", item_list[i].price);
        printf("###############\n");
	}
}

int main(int argc, char *argv[]){
	//dynamically allocate space for the items
	Item *item_list = malloc(5 * sizeof(Item));
	
	add_item(item_list, atof("4"), "10011", "cereal", "Fruit Loops", 1);
	add_item(item_list, atof("12"), "20011", "Steak", "New York Strip", 2);
	add_item(item_list, atof("3")," 30011", "Drink", "Celsius", 3);
	add_item(item_list,atof( "25"), "40011", "Clothes", "T-Shirt", 4);
	add_item(item_list, atof("125"), "50011", "Shoes", "Nike", 5);

	print_items(item_list, 5);
	
	double avg_price = average_price(item_list, 5);
	printf("Print average price: %.3f", avg_price);
	free_items(item_list, 5);
	

	if(argc > 1){
		char *search_sku = argv[1];
		int found = 0;

		int i; 
		for(i = 0; i < 5; i++){
			if (strcmp(item_list[i].sku, search_sku) == 0) {
                printf("Item found:\n");
                printf("###############\n");
                printf("item name = %s\n", item_list[i].name);
                printf("item sku = %s\n", item_list[i].sku);
                printf("item category = %s\n", item_list[i].category);
                printf("item price = %.3f\n", item_list[i].price);
                printf("###############\n");
                found = 1;
                break;
            }
	if(!found){
		printf("Item not found\n");
}
	return 0;


}
}
}
