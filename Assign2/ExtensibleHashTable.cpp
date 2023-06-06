//
//  ExtensibleHashTable.cpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//


#include "ExtensibleHashTable.hpp"
#include <vector>
#include "Bucket.hpp"
#include <iostream>

ExtensibleHashTable::ExtensibleHashTable(){
    globalDepth = 1;
    for(int i = 0; i<2; i++){
        buckets.push_back(new Bucket(4));
    }

}
//
ExtensibleHashTable::ExtensibleHashTable(int numOfKeys){
    globalDepth = 1;
    Bucket bucket(numOfKeys);
    buckets.push_back(&bucket);
}

void printKeys(vector<Key> keys){
    for(int j = 0; j < keys.size(); j++){
        cout << keys[j].value << ' ' << keys[j].taken;
        cout << "\n";
    }
}


void ExtensibleHashTable::print(){
    for(int i=0; i< buckets.size(); i++){
        cout << "bucket " << i << "\n";
        vector<Key> keys = (*buckets[i]).getKeys();
        printKeys(keys);
        
        
    }
}
int getBucketNumber(int value, int globalDepth){
    int sum = 0;
    for(int i = 0; i < globalDepth; i++){
        sum += (1 << i)*((value >> i) % 2);
    }
    return sum;
}

void ExtensibleHashTable::insert(int value){
    int bucketNumber = getBucketNumber(value, globalDepth);
    (*buckets[bucketNumber]).addKey(value);
    
}


