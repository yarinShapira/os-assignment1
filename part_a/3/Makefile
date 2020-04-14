out:main1_3.out

main1_3.out: main1_3.c libhello_Ariel.so
	gcc main1_3.c -fPIC -ldl -o main1_3.out

main1_1.o: main1_1.c hello_Ariel.h
	gcc -Wall -c main1_1.c

libhello_Ariel.so: hello_Ariel.h hello_Ariel.c
	gcc -o libhello_Ariel.so -shared -fPIC hello_Ariel.c

.PHONY: clean out

clean:
	rm -f *.o *.out *.so