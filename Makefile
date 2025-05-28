CC=gcc
CFLAGS=-Wall -Wextra -Iinclude
SRC=src/main.c src/shell.c src/builtins.c
OBJ=$(SRC:.c=.o)
TARGET=mini_shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
