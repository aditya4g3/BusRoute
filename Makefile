COMPILER = gcc
CFLAGS = -Wall -Wextra -std=c99
FLAGS2 = -lm

SRCS = busAssignment.c Student.c BusRoute.c Point2D.c Strings.c
OBJS = $(SRCS:.c=.o)
TARGET = busAssignment

all: $(TARGET)

$(TARGET): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(TARGET) $(FLAGS2)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)