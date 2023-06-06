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
    extensibleHashTable.print();
//    for( auto i = extensibleHashTable.buckets.begin(); i != extensibleHashTable.buckets.end(); ++i){
//        cout << *i;
//    }
    return 0;
}
