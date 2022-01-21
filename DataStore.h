#ifndef DATASTORE_H
#define DATASTORE_H

#include "stdio.h"
#include "json-c/json.h"

extern void mapInit();
extern void mapPrint();
extern void mapInsert(const char *key, const char *value);
extern void mapDeleteItem(const char *key);
extern void mapUpdate(const char *key, const char *value);

#endif
