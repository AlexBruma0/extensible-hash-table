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
    cout << "----------------------------------------\n" ;
    
    extensibleHashTable.insert(4);
    extensibleHashTable.print();
    cout << "----------------------------------------\n" ;
    extensibleHashTable.insert(3);
    extensibleHashTable.print();
    cout << "----------------------------------------\n" ;
    extensibleHashTable.insert(2);
    extensibleHashTable.print();
    cout << "----------------------------------------\n" ;
    extensibleHashTable.insert(1);
    extensibleHashTable.print();
    cout << "----------------------------------------\n" ;
    extensibleHashTable.insert(92);
    extensibleHashTable.print();
    cout << "----------------------------------------\n" ;
   // extensibleHashTable.remove(5);


    return 0;
}
