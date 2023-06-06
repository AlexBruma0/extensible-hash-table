//
//  ExtensibleHashTable.hpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#ifndef ExtensibleHashTable_hpp
#define ExtensibleHashTable_hpp

#include <stdio.h>
#include "Bucket.hpp"
#include <vector>
using namespace std;


class ExtensibleHashTable {

public:
    vector<Bucket *> buckets;
    ExtensibleHashTable();
    ExtensibleHashTable(int numOfKeys);
//    bool find(int);
//    void insert(int);
//    bool remove(int);
      void print();
    
    
};

#endif /* ExtensibleHashTable_hpp */
