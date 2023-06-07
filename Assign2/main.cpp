//
//  main.cpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#include <iostream>
#include "Bucket.hpp"
#include "ExtensibleHashTable.hpp"
#include<cstdlib>

int main(int argc, const char * argv[]) {
    // Providing a seed value
    srand((signed) time(NULL));

    ExtensibleHashTable extensibleHashTable;
    
    for(int i = 0; i < 10; i++){
        int random = rand() % 100;
        extensibleHashTable.insert(random);
        extensibleHashTable.print();
        cout << "----------------------------------------\n" ;
        
    }

    return 0;
}
