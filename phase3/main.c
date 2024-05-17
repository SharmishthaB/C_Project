#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bill.h"
#include "customer_entry.h"
#include "item_entry.h"
#include "find_item.h"

int main() {
    int choice;
    int num_items = 0;

    // Initialize items array
    initialize_items();

    // Load customers and items from files
    load_customers_from_file("customers.txt", customers, &num_customers);
    load_items_from_file("items.txt", items, &num_items);
   

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
                //bill(customers,num_customers);
                int generate_another_bill;
                do {
                    bill(customers, num_customers);
                    printf("Do you want to generate another bill? (1 for Yes, 0 for No): ");
                    scanf("%d", &generate_another_bill);
                    if (generate_another_bill == 0) {
                        printf("Exiting...\n");
                        return 0; // Exit the program
                    }
                } while (generate_another_bill == 1);
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

