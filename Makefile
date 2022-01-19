CC=g++
CFLAGS = -g -Wall -Wextra  -Ijson-c/build -static -Ljson-c/build
#LDFLAGS = $(shell pkg-config --libs json-c)
#LIBJSON = json-c/build
#LIBJSON_OBJS =	$(LIBJSON)/json_util.o $(LIBJSON)/json_object.o $(LIBJSON)/json_tokener.o \
#				$(LIBJSON)/json_object_iterator.o $(LIBJSON)/printbuf.o $(LIBJSON)/linkhash.o \
#				$(LIBJSON)/arraylist.o $(LIBJSON)/random_seed.o $(LIBJSON)/debug.o $(LIBJSON)/strerror_override.o
#PG_CPPFLAGS = --std=c99 -I$(LIBJSON)

DEPS = DataStore.h
OBJS = main.o DataStore.o $(LIBJSON_OBJS)

# The build target 
TARGET = main
  all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(TARGET): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) main.c DataStore.c  -o main -ljson-c