src = $(wildcard *.c)
obj = $(src:.c=.o)
CC = gcc
LDFLAGS = -lGL -lglut -lpng -lz -lm -Wall -pedantic -g3

coulomb.exe: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) coulomb.exe
