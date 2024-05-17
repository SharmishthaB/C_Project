#ifndef GLOBALS_H
#define GLOBALS_H
#include "customer_entry.h"

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100
#define MAX_ITEM_DESCRIPTION_LENGTH 50

// Structure for items
struct Item {
    int itemId;
    char description[MAX_ITEM_DESCRIPTION_LENGTH];
    int stock;
    float price;
};

extern int num_customers;
extern struct Item *items[MAX_ITEMS];
extern struct Customer customers[MAX_CUSTOMERS];
extern int item_id[MAX_ITEMS];

void initialize_items();

#endif
