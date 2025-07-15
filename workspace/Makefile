CC = gcc
CFLAGS = -g
SRCS = project_main.c complex.c
OBJS = $(SRCS:.c=.o)
TARGET = project_main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
