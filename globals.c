#include "globals.h"
#include <stdio.h>

int item_id[MAX_ITEMS]={1,2,3,4,5,6,7,8,9,10};
    int items[MAX_ITEMS]={1,2,3,4,5,6,7,8,9,10}; //
    char item_description[MAX_ITEMS][MAX_DESCRIPTION_LENGTH]={
        "oil",
        "perfume",
        "lip balm",
        "chocolate bar",
        "talking toys"
    };
    int item_stock[MAX_ITEMS]={10,10,10,10,10};
    float item_price[MAX_ITEMS]={50.00, 75.00, 45.00,20.00,60.00};
    int customer_id[MAX_CUSTOMERS] = {101, 102, 103,104,105};
    char customer_name[MAX_CUSTOMERS][MAX_NAME_LENGTH]= {"Customer1","Customer2","Customer3"};

    char customer_contact[MAX_CUSTOMERS][MAX_CONTACT_LENGTH] = {"Cont1","Cont2","Cont3"};