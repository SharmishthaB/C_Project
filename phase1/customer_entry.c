#include <stdio.h>
#include "customer_entry.h"
#include "globals.h"
void customer_entry() {
    int i, id, found;

    printf("Enter customer ID: ");
    scanf("%d", &id);

    // Check if the customer ID already exists
    found = 0;
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        if (customer_id[i] == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Customer with ID %d already exists.\n", id);
        return;
    }

    // Add the new customer to the array
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        if (customer_id[i] == 0) { // 0 represents an empty slot
            customer_id[i] = id;
            printf("Enter customer name: ");
            scanf("%s", customer_name[i]);
            printf("Enter customer contact: ");
            scanf("%20s", customer_contact[i]);
            break;
        }
    }

    if (i == MAX_CUSTOMERS) {
        printf("Maximum number of customers reached.\n");
    } else {
        printf("Customer added successfully.\n");
    }
}