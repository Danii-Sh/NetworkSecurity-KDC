CC=gcc
LIBS=-lpthread



DEPS= 
OBJ= New.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< 
New:	$(OBJ)
	gcc -o $@ $^ $(LIBS)
.PHONY:	clean
clean:
	rm *.o New
