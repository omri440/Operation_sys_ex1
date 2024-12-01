CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = OS

OBJS = main.o my_fork.o print_pids.o count_lines.o print_threads.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c my_fork.h print_pids.h count_lines.h print_threads.h
	$(CC) $(CFLAGS) -c main.c

my_fork.o: my_fork.c my_fork.h
	$(CC) $(CFLAGS) -c my_fork.c

print_pids.o: print_pids.c print_pids.h my_fork.h
	$(CC) $(CFLAGS) -c print_pids.c

count_lines.o: count_lines.c count_lines.h
	$(CC) $(CFLAGS) -c count_lines.c

print_threads.o: print_threads.c print_threads.h
	$(CC) $(CFLAGS) -c print_threads.c

clean:
	rm -f $(OBJS) $(TARGET)
