#include <stdio.h>
#include "find_item.h"
#include "globals.h"

void bill() {
    int customer_id, item_id, quantity;
    float total_price = 0, discount = 0, gst = 0;

    printf("Enter customer ID: ");
    scanf("%d", &customer_id);

    printf("\nAvailable Items:\n");
    for (int i = 0; i < 10; i++) {
        printf("Item ID: %d, Description: %s\n", *(items + i), *(item_description + i));
    }

    // Loop to input multiple items
    while (1) {
        printf("Enter item ID (or enter -1 to finish): ");
        scanf("%d", &item_id);
        
        // Check if the user wants to finish entering items
        if (item_id == -1)
            break;

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Find the item in the array
        int item_id_to_find = item_id;
        int* found_item = find_item(item_id_to_find, items, MAX_ITEMS);
        
        if (found_item != NULL) {
            int index = found_item - items;
            printf("Item found at index %d\n", index);

            
            // Check if the item is in stock
            if (item_stock[index] < quantity) {
                printf("Item out of stock\n");
                continue;
            }

            // Calculate the total price for this item
            float item_total_price = quantity * item_price[index];
            total_price += item_total_price;

            // Calculate GST for this item
            gst += item_total_price * 0.12;

             // Update the stock
            item_stock[index] -= quantity;

            // Print details of this item
            printf("Description: %s\n", item_description[index]);
            printf("Price: %.2f\n", item_price[index]);
            printf("GST: %.2f\n", item_total_price * 0.12);
            printf("Quantity: %d\n", quantity);
        } else {
            printf("Item not found\n");
        }
    }

    // Print the bill summary
    printf("\n--- BILL ---\n");
    printf("Customer ID: %d\n", customer_id);
    printf("Customer name: %s\n", customer_name);
    printf("Total price: %.2f\n", total_price);
    printf("GST: %.2f\n", gst);
    printf("Total amount payable (including GST): %.2f\n", total_price + gst);
}
