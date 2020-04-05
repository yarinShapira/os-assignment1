main1_3.out: main1_3.c libhello_Ariel.so
	gcc -Wall -o main1_3.out main1_3.c

main1_2.out:main1_1.c libhello_Ariel.so hello_Ariel.h
	gcc main1_1.c -L. -l hello_Ariel -o main1_2.out

main1_1.out: main1_1.o hello_Ariel.o
	gcc -Wall -o main1_1.out main1_1.o hello_Ariel.o

main1_3.o: main1_3.c hello_Ariel.h
	gcc -Wall -c main1_3.c

main1_1.o: main1_1.c hello_Ariel.h
	gcc -Wall -c main1_1.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	gcc -Wall -c hello_Ariel.c

libhello_Ariel.so: hello_Ariel.h hello_Ariel.c
	gcc -o libhello_Ariel.so -shared -fPIC hello_Ariel.c

.PHONY: clean 

clean:
	rm -f *.o *.out *.so