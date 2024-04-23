#ifndef GLOBALS_H
#define GLOBALS_H
#define MAX_CUSTOMERS 100
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CONTACT_LENGTH 100
#define MAX_NAME_LENGTH 100
#define MAX_ITEMS 100


extern int item_id[MAX_ITEMS];
extern int items[MAX_ITEMS];
extern char item_description[MAX_ITEMS][MAX_DESCRIPTION_LENGTH];
extern int item_stock[MAX_ITEMS];
extern float item_price[MAX_ITEMS];
extern int customer_id[MAX_CUSTOMERS];
extern char customer_name[MAX_CUSTOMERS][MAX_NAME_LENGTH];
extern char customer_contact[MAX_CUSTOMERS][MAX_CONTACT_LENGTH];



#endif