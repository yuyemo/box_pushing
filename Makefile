CC = gcc
CFLAGS = -Wall -g

SRCS = main.c map.c game.c timer.c undo.c ui.c 
OBJS = $(SRCS:.c=.o)
TARGET = sokoban

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
