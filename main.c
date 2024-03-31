#include <stdio.h>
#include <string.h>
#include "bill.h"
//#include "find_item.h"
#include "item_entry.h"
#include "customer_entry.h"
#include "print_menu.h"


int main() {
    int choice;
    int item_id[MAX_ITEMS]={1,2,3};
    int items[MAX_ITEMS]={10,20,30};
    char item_description[MAX_ITEMS][MAX_DESCRIPTION_LENGTH]={
        "Item 1 Description",
        "Item 2 Description",
        "Item 3 Description"
    };
    int item_stock[MAX_ITEMS]={5,10,15};
    float item_price[MAX_ITEMS]={10.99f, 20.49f, 5.99f};
    int customer_id[MAX_CUSTOMERS] = {101, 102, 103};
    char customer_name[MAX_CUSTOMERS][MAX_NAME_LENGTH]= {"Cust1","Cust2","Cust3"};

    char customer_contact[MAX_CUSTOMERS][MAX_CONTACT_LENGTH] = {"Cont1","Cont2","Cont3"};   
        


    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customer_entry();
                break;
            case 2:
                item_entry();
                break;
            case 3:
                bill();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
