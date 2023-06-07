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
    cout << "[";
    for(int j = 0; j < keys.size(); j++){

        if(keys[j].taken)
            cout << keys[j].value << ",";
        else
            cout  << ",-";
    }
    cout << "] ";

}


void ExtensibleHashTable::print(){
    for(int i=0; i< buckets.size(); i++){
        cout << i << ": "<<buckets[i] << " --> ";
        vector<Key> keys = (*buckets[i]).getKeys();
        printKeys(keys);
        cout << "(" << (*buckets[i]).getLocalDepth() << ")";
        cout << "\n";
        
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

bool ExtensibleHashTable::remove(int value){
    int bucketNumber = getBucketNumber(value, globalDepth);
    bool successful = (*buckets[bucketNumber]).removeKey(value);
    return successful;
}

ExtensibleHashTable::~ExtensibleHashTable(){
    for( int i = 0; i < (1 << globalDepth); i++){
        delete buckets[i];
    }
}

