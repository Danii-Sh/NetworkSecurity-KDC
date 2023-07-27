CC=gcc
LIBS=-lpthread



DEPS= 
OBJ= writeonfile.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< 
writeonfile:	$(OBJ)
	gcc -o $@ $^ $(LIBS)
.PHONY:	clean
clean:
	rm *.o writeonfile
