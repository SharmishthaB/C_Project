#include <stdlib.h>
#include "globals.h"

int num_customers=0;
struct Item *items[MAX_ITEMS];
struct Customer customers[MAX_CUSTOMERS];
int item_id[MAX_ITEMS];

void initialize_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        /*items[i] = (struct Item*) malloc(sizeof(struct Item));
        if (items[i] != NULL) {
            items[i]->itemId = 0;*/ // Initialize item ID to 0 indicating an empty slot
        
        items[i] = NULL; // Initialize items to NULL
        item_id[i] = 0;  // Initialize item_id to 0 indicating an empty slot

        }
}

