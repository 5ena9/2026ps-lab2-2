CC = gcc
CFLAGS = -W -Wall
TARGET = registration

all: $(TARGET)

$(TARGET): main.c manager.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	del *.o $(TARGET).exe