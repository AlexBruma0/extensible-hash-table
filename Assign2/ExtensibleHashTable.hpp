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
    vector<Bucket *> uniqueBuckets;
    ExtensibleHashTable();
    ExtensibleHashTable(int numOfKeys);
    bool find(int value);
    void insert(int value);
    bool remove(int value);
    void print();
    //destructor
    ~ExtensibleHashTable();
    //overload assignment operator
    void operator=(const ExtensibleHashTable& extensibleHashTable)
    {
        globalDepth = extensibleHashTable.globalDepth;
        buckets = extensibleHashTable.buckets;
    }
    //copy constructor
    ExtensibleHashTable(ExtensibleHashTable& extensibleHashTable){
        globalDepth = extensibleHashTable.globalDepth;
        buckets = extensibleHashTable.buckets;
    }
    //helper methods
    void redistributeValues(Bucket * oldBucketPtr, Bucket * newBucketPtr);
    void insertNewBucket(Bucket * bucketPtr, int value);
    void bucketFull(Bucket * bucket, int value);
    void doubleDirSize(Bucket * bucket, int value);
    bool bucketIsUnique(Bucket * bucketPtr, int i  );
    bool sameValueError(int value, Bucket * bucket);
    void fixPointers(Bucket * newBucketPtr ,Bucket * oldBucketPtr, int newBucketIndex);
    void reorganizeBuckets();
    
};

#endif /* ExtensibleHashTable_hpp */
