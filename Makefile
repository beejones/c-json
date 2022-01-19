CC=g++
CFLAGS = -Wall -Wextra
CFLAGS += $(shell pkg-config --cflags json-c)
LDFLAGS += $(shell pkg-config --libs json-c)
CFLAGS += $(shell pkg-config --cflags nlohmann_json)
//LDFLAGS += $(shell pkg-config --libs nlohmann_json)

DEPS = DataStore.h
OBJS = main.o DataStore.o

# The build target 
TARGET = main
  all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(TARGET): main.o $(DEPS)
	$(CC) $(CFLAGS) main.c DataStore.cpp  -o main