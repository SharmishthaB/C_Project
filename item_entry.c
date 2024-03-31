#include <stdio.h>
#include "globals.h"

void item_entry() {
    int i, id, found;

    printf("Enter item ID: ");
    scanf("%d", &id);

    // Check if the item ID already exists
    found = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (item_id[i] == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Item with ID %d already exists.\n", id);
        return;
    }

    // Add the new item to the array
    for (i = 0; i < MAX_ITEMS; i++) {
        if (item_id[i] == 0) { // 0 represents an empty slot
            item_id[i] = id;
            items[i] = id;
            printf("Enter item description: ");
            scanf("%s", &item_description[i]);
            printf("Enter item stock: ");
            scanf("%d", &item_stock[i]);
            printf("Enter item price: ");
            scanf("%f", &item_price[i]);
            
            printf("Item ID: %d, Description: %s, Stock: %d, Price: %.2f\n", item_id[i], item_description[i], item_stock[i], item_price[i]);
            
            break;
        }
    }

    if (i == MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
    } else {
        printf("Item added successfully.\n");
    }
}