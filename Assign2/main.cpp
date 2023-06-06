//
//  main.cpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#include <iostream>
#include "Bucket.hpp"
#include "ExtensibleHashTable.hpp"

int main(int argc, const char * argv[]) {

    ExtensibleHashTable extensibleHashTable;
    extensibleHashTable.insert(5);
    extensibleHashTable.print();
    extensibleHashTable.remove(5);
    extensibleHashTable.print();

    return 0;
}
