#include <cstdio>
#include "DataStore.h"

int main() {    
    printf("Start experiment\n");
    insert("4", {"title", "back to the future"});
    print();
    del("2");
    print();
    update("4", {"title", "Back to the future"});
    print();

    // Error cases currently not trapped
    del("20");
    update("20", {"title", "Back to the future"});
    print();
}