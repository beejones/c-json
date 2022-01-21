#include <cstdio>
#include "DataStore.h"

int main() {    
    printf("Start experiment\n");
    mapInit();
    mapInsert("4", "{\"title\": \"back to the future\"}");
    mapPrint();
    mapDeleteItem("2");
    mapPrint();
    mapUpdate("4", "{\"title\": \"Back to the future\"}");
    mapPrint();
}