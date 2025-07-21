CC = gcc
CFLAGS = -g
LDFLAGS = -lm

SRCS = project_main.c complex.c dataframe.c save_load.c fft.c fft_io.c fft_pipeline.c
OBJS = $(SRCS:.c=.o)
TARGET = project_main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
