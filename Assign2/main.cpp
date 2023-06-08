//
//  main.cpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#include <iostream>
#include "Bucket.hpp"
#include "ExtensibleHashTable.hpp"
#include  <cstdlib>

int main(int argc, const char * argv[]) {
    // Providing a seed value
    srand((signed) time(NULL));

    ExtensibleHashTable extensibleHashTable(6);
    //int array[5] = {5,13,21,29,37};
    //int array[16] = {24,96,20,88,81,50,80,80,76,55,94,58,75,86,64,42};
    for(int i = 0; i < 40; i++){
        //int random = array[i];
        int random = rand() % 100;
        extensibleHashTable.insert(random);
        cout << "inserting: " << random << "\n";
        extensibleHashTable.print();
        cout << "----------------------------------------\n" ;

    }

    return 0;
}
