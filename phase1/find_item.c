#include <stdio.h>
#include "globals.h"

int* find_item(int item_id, int* items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        if (items[i] == item_id) {
            return &items[i];
        }
    }
    return NULL;
}
