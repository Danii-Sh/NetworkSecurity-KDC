CC=gcc
LIBS=-lpthread



DEPS= 
OBJ= Borland-AES-GCM.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< 
Borland-AES-GCM:	$(OBJ)
	gcc -o $@ $^ $(LIBS)
.PHONY:	clean
clean:
	rm *.o Borland-AES-GCM.c
