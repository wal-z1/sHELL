CC ?= gcc
CFLAGS ?= -Wall -Wextra -O2
TARGET = shell

ifeq ($(OS),Windows_NT)
    TARGET_BIN = $(TARGET).exe
    RM = del /Q /F
else
    TARGET_BIN = $(TARGET)
    RM = rm -f
endif

all: $(TARGET_BIN)

$(TARGET_BIN): shell.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(TARGET_BIN) *.o

.PHONY: all clean
