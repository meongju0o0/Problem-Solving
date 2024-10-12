# Makefile for BOJ(Baekjoon Online Judge) Debug & Build

CC = gcc

CFLAGS = -Wall -O2 -Wno-unused-result
LDFLAGS = -L../lib -lm
TARGET = BOJ9366
SRCS = BOJ9366.c
OBJS = $(addprefix build/, $(SRCS:.c=.o))

.SUFFIXES = .c .o

build/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	$(CC) -o build/$@ $(OBJS) $(LDFLAGS)

clean:
	rm -rf build
	mkdir -p build
