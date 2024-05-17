a.exe: main.o globals.o bill.o customer_entry.o item_entry.o find_item.o
	gcc main.o globals.o bill.o customer_entry.o item_entry.o find_item.o -o a.exe

main.o: main.c bill.h customer_entry.h item_entry.h globals.h
	gcc -c main.c

globals.o: globals.c globals.h
	gcc -c globals.c 

bill.o: bill.c bill.h globals.h find_item.h
	gcc -c bill.c

customer_entry.o: customer_entry.c customer_entry.h globals.h
	gcc -c customer_entry.c  

item_entry.o: item_entry.c item_entry.h globals.h
	gcc -c item_entry.c

find_item.o: find_item.c find_item.h globals.h
	gcc -c find_item.c
