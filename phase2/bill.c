#include <stdio.h>
#include "find_item.h"
#include "globals.h"
#include "bill.h"
#include "customer_entry.h"



struct Customer* find_customer(int customer_id, struct Customer* customers, int num_customers);
struct Item* find_item(int item_id, struct Item** items, int num_items);

void bill(struct Customer* customers, int num_customers) {
    int customer_id;
    int  item_id, quantity;
    float total_price = 0, discount = 0, gst = 0;
    

    // Find the number of customers in the array
    while (customers[num_customers].customerId != 0 && num_customers < MAX_CUSTOMERS) {
        num_customers++;
    }

    printf("customers array:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Customer %d: ID = %d, name = %s\n", i, customers[i].customerId, customers[i].name);
    }

    printf("num_customers = %d\n", num_customers);

    printf("Enter customer ID: ");
    scanf("%d", &customer_id);

    // Find the customer in the array
    struct Customer *found_customer = find_customer(customer_id, customers, num_customers);
    
    if (found_customer == NULL) {
        printf("Customer not found\n");
        return;
    }

    printf("\nAvailable Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i] == NULL) continue;
        printf("Item ID: %d, Description: %s\n", items[i]->itemId, items[i]->description);
    }

    // Loop to input multiple items
    while (1) {
        printf("Enter item ID (or enter -1 to finish): ");
        scanf("%d", &item_id);

        // Check if the user wants to finish entering items
        if (item_id == -1)
            break;

        // Find the item in the array
        struct Item *found_item = find_item(item_id, items, MAX_ITEMS);
        
        if (found_item == NULL) {
            printf("Item not found\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Check if the item is in stock
        if (found_item->stock < quantity) {
            printf("Item out of stock\n");
            continue;
        }

        // Calculate the total price for this item
        float item_total_price = quantity * found_item->price;
        total_price += item_total_price;

        // Calculate GST for this item
        gst += item_total_price * 0.12;

        // Update the stock
        found_item->stock -= quantity;

        // Print details of this item
        printf("Description: %s\n", found_item->description);
        printf("Price: %.2f\n", found_item->price);
        printf("GST: %.2f\n", item_total_price * 0.12);
        printf("Quantity: %d\n", quantity);
    }

    // Print the bill summary
    printf("\n--- BILL ---\n");
    printf("Customer ID: %d\n", customer_id);
    printf("Customer name: %s\n", found_customer->name);
    printf("Total price: %.2f\n", total_price);
    printf("GST: %.2f\n", gst);
    printf("Total amount payable (including GST): %.2f\n", total_price + gst);
}

// Function to find a customer in the array
struct Customer* find_customer(int customer_id, struct Customer* customers, int num_customers) {
    printf("Searching for customer with ID %d\n", customer_id);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].customerId == customer_id) {
            return &customers[i];
        }
    }
    printf("Customer with ID %d not found\n", customer_id);
    return NULL;
}
