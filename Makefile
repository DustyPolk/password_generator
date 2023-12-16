CC=gcc
CFLAGS=-I.
DEPS = password_generator.h
OBJ = main.o password_generator.o 
LIBS=-lssl -lcrypto

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

password_generator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o password_generator