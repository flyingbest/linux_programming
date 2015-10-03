st0311:	list0311A.o	list0311B.o
	gcc list0311A.o	list0311B.o -o list0311

list0311A.o:	list0311A.c
	gcc	-c	-o	list0311A.o	list0311A.c

list0311B.o:	list0311B.c
	gcc -c	-o	list0311B.o	list0311B.c

