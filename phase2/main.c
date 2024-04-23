#include <stdio.h>
#include <string.h>
#include "bill.h"
#include "customer_entry.h"
#include "item_entry.h"
#include "find_item.h"

int main() {
    int choice;
   

    // Menu loop
    do {
        printf("\n===== Billing System Menu =====\n");
        printf("1. Customer Entry\n");
        printf("2. Item Entry\n");
        printf("3. Generate Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customer_entry(customers,&num_customers);
                break;
            case 2:
                item_entry(items);
                break;
            case 3:
                bill(customers,num_customers);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

