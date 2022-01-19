#ifndef DATASTORE_H
#define DATASTORE_H
//using namespace std;
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
extern "C"
{
    extern void print();
    extern void insert(char *, json);
    extern void del(char *key);
    extern void update(char *key, json value);
    extern json search(char *key);
}
#endif