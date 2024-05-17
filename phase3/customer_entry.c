#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"
#include "customer_entry.h"



void customer_entry(struct Customer* customers, int* num_customers) {
    if (*num_customers >= MAX_CUSTOMERS) {
        printf("Maximum number of customers reached\n");
        return;
    }

    printf("Enter customer ID: ");
    scanf("%d", &customers[*num_customers].customerId);

    printf("Enter customer name: ");
    scanf("%s", customers[*num_customers].name);

    printf("Enter customer contact: ");
    scanf("%s", customers[*num_customers].contact);

    (*num_customers)++;

    printf("Customer added successfully.\n");
}

void load_customers_from_file(const char* filename, struct Customer* customers, int* num_customers) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open customers file");
        return;
    }

    while (fscanf(file, "%d %s %s", &customers[*num_customers].customerId, customers[*num_customers].name, customers[*num_customers].contact) == 3) {
        (*num_customers)++;
        if (*num_customers >= MAX_CUSTOMERS) {
            printf("Maximum number of customers reached\n");
            break;
        }
    }

    fclose(file);
}