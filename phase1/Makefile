a.exe: main.o globals.o bill.o customer_entry.o print_menu.o item_entry.o find_item.o
	gcc main.o globals.o bill.o customer_entry.o print_menu.o item_entry.o find_item.o

main.o: main.c bill.h customer_entry.h print_menu.h globals.h item_entry.h
	gcc -c main.c

globals.o: globals.c globals.h
	gcc -c globals.c 

bill.o: bill.c bill.h
	gcc -c bill.c

customer_entry.o: customer_entry.c customer_entry.h
	gcc -c customer_entry.c

print_menu.o: print_menu.c print_menu.h 
	gcc -c print_menu.c 

customer_entry.o: customer_entry.c customer_entry.h
	gcc -c customer_entry.c 

item_entry.o: item_entry.c item_entry.h
	gcc -c item_entry.c

find_item.o: find_item.c item_entry.h
	gcc -c find_item.c

