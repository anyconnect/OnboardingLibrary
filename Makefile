SHELL = /bin/sh
.PHONY: clean

CC= g++
CPPFLAGS= -std=c++11 -fPIC -g
LDFLAGS= -shared -pthread

SOURCES = $(shell echo *.cpp)
HEADERS = $(shell echo *.h)
OBJECTS=$(SOURCES:.cpp=.o)

MEDIA_LIBDIR= 
MEDIA_INCDIR= 

TARGET=libonboard.so

all: $(TARGET)

clean: 
	rm -f $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

