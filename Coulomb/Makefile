src = $(wildcard *.c)
obj = $(src:.c=.o)
CC = gcc
LDFLAGS = -lGL -lglut -lpng -lz -lm -Wall -pedantic

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog