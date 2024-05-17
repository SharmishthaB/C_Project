//item_entry.h
#include "globals.h"

#ifndef ITEM_H
#define ITEM_H
void item_entry();
void load_items_from_file(const char* filename, struct Item** items, int* num_items);
#endif