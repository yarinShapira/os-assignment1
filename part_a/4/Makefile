all:main1_1.out main1_2.out main1_3.out

main1_3.out: ../3/main1_3.c libhello_Ariel.so
	gcc ../3/main1_3.c -fPIC -ldl -o main1_3.out

main1_2.out:../2/main1_1.c libhello_Ariel.so ../2/hello_Ariel.h
	gcc ../2/main1_1.c -L. -l hello_Ariel -o main1_2.out

main1_1.out: ../1/main1_1.o hello_Ariel.o
	gcc -Wall -o main1_1.out ../1/main1_1.o hello_Ariel.o

main1_1.o: ../1/main1_1.c ../1/hello_Ariel.h
	gcc -Wall -c ../1/main1_1.c

hello_Ariel.o: ../1/hello_Ariel.c ../1/hello_Ariel.h
	gcc -Wall -c ../1/hello_Ariel.c

libhello_Ariel.so: ../1/hello_Ariel.h ../1/hello_Ariel.c
	gcc -o libhello_Ariel.so -shared -fPIC ../1/hello_Ariel.c

.PHONY: clean all

clean:
	rm -f *.o *.out *.so
	cd ../1 && rm -f main1_1.o