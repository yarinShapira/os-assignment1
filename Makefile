main.out: main1_1.o hello_Ariel.o
	gcc -Wall -o main.out main1_1.o hello_Ariel.o

main1_1.o: main1_1.c hello_Ariel.h
	gcc -Wall -c main1_1.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	gcc -Wall -c hello_Ariel.c	

.PHONY: clean 

clean:
	rm -f *.o *.out