CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -pedantic
LIB_NAME = libfast_trigo.a
OBJECTS = fast_trigo.o
MAIN_OBJECT = main.o

all: esercitazione1

$(LIB_NAME): $(OBJECTS)
	$(AR) rcs $(LIB_NAME) $(OBJECTS)

esercitazione1: $(MAIN_OBJECT) $(LIB_NAME)
	$(CC) $(MAIN_OBJECT) -L. -lfast_trigo -lm -o esercitazione1 $(CFLAGS)

clean:
	rm -f *.o *.a main
