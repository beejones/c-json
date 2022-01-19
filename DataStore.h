#ifndef DATASTORE_H
#define DATASTORE_H

#include <cstdio>
#include "json-c/json.h"

extern void print();
extern void insert(char *, char *);
extern void del(char *key);
extern void update(char *key, char *value);

#endif
