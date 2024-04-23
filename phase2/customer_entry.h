#ifndef CUSTOMER_ENTRY_H
#define CUSTOMER_ENTRY_H

#include "globals.h"
// Structure for customers
struct Customer {
    int customerId;
    char name[50];
    char contact[15];
};

struct Customer* find_customer(int customer_id, struct Customer* customers, int num_customers);
void customer_entry(struct Customer* customers, int* num_customers);
#endif