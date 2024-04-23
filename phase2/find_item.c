#include <stddef.h>
#include "globals.h"
struct Item* find_item(int item_id, struct Item** items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        if (items[i] != NULL && items[i]->itemId == item_id) {
            return items[i];
        }
    }
    return NULL;
}
