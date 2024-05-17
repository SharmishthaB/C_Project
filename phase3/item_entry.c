#include <stdio.h>
#include <string.h> // for strcmp()
#include <stdlib.h>
#include "globals.h"
#include "item_entry.h"


void item_entry() {
    int i, id, found;
    struct Item *new_item;

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
            // Allocate memory for the new item
            new_item = (struct Item*) malloc(sizeof(struct Item));

            // Initialize the new item
            new_item->itemId = id;
            printf("Enter item description (max %d characters): ", MAX_ITEM_DESCRIPTION_LENGTH - 1);
            scanf("%s", new_item->description);
            printf("Enter item stock: ");
            scanf("%d", &(new_item->stock));
            printf("Enter item price: ");
scanf("%f", &(new_item->price));

            // Add the new item to the array
            item_id[i] = id;
            items[i] = new_item;

            printf("Item ID: %d, Description: %s, Stock: %d, Price: %.2f\n", item_id[i], new_item->description, new_item->stock, new_item->price);

            break;
        }
    }

    if (i == MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
    } else {
        printf("Item added successfully.\n");
    }
}

void load_items_from_file(const char* filename, struct Item** items, int* num_items) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open items file");
        return;
    }

    int id, stock;
    float price;
    char description[MAX_ITEM_DESCRIPTION_LENGTH];

    while (fscanf(file, "%d %s %d %f", &id, description, &stock, &price) == 4) {
        if (*num_items >= MAX_ITEMS) {
            printf("Maximum number of items reached\n");
            break;
        }

        struct Item *new_item = (struct Item*) malloc(sizeof(struct Item));
        if (new_item == NULL) {
            perror("Failed to allocate memory for new item");
            continue;
        }

        new_item->itemId = id;
        strncpy(new_item->description, description, MAX_ITEM_DESCRIPTION_LENGTH);
        new_item->stock = stock;
        new_item->price = price;

        items[*num_items] = new_item;
        item_id[*num_items] = id;
        (*num_items)++;
    }

    fclose(file);
}
