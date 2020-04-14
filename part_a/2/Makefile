out:main1_2.out

main1_2.out:main1_1.c libhello_Ariel.so hello_Ariel.h
	gcc main1_1.c -L. -l hello_Ariel -o main1_2.out

libhello_Ariel.so: hello_Ariel.h hello_Ariel.c
	gcc -o libhello_Ariel.so -shared -fPIC hello_Ariel.c

.PHONY: clean out

clean:
	rm -f *.o *.out *.so