CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -fsanitize=address -g -Iinclude

APP = app

.PHONY: all clean run test

all: $(APP)

$(APP): main.c src/list.c src/stack.c src/queue.c
	$(CC) $(CFLAGS) -o $(APP) main.c src/list.c src/stack.c src/queue.c

run: $(APP)
	./$(APP)

test: $(APP)
	./$(APP)

clean:
	rm -f $(APP)