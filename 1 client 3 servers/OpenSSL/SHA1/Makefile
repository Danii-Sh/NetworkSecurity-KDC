CC=gcc
LIBS=-lpthread



DEPS= 
OBJ= new.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< 
new:	$(OBJ)
	gcc -o $@ $^ $(LIBS)
.PHONY:	clean
clean:
	rm *.o new
