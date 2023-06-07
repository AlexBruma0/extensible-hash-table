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
    int globalDepth;
    vector<Bucket *> buckets;
    ExtensibleHashTable();
    ExtensibleHashTable(int numOfKeys);
    bool find(int value);
    void insert(int value);
    bool remove(int value);
    void print();
    ~ExtensibleHashTable();
    void operator=(const ExtensibleHashTable& extensibleHashTable)
    {
        globalDepth = extensibleHashTable.globalDepth;
        buckets = extensibleHashTable.buckets;
    }
    ExtensibleHashTable(ExtensibleHashTable& extensibleHashTable){
        globalDepth = extensibleHashTable.globalDepth;
        buckets = extensibleHashTable.buckets;
    }
};

#endif /* ExtensibleHashTable_hpp */
