main: main.o hashmap.o
	gcc -o main main.o hashmap.o -g

main.o: main.c 
	gcc -c main.c -o main.o -g

hashmap.o: hashmap.c 
	gcc -c hashmap.c -o hashmap.o -g

clean: 
	rm *.o main