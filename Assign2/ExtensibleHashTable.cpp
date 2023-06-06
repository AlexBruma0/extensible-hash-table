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
    for(int i = 0; i<2; i++){
        buckets.push_back(new Bucket(4));
    }

}
//
ExtensibleHashTable::ExtensibleHashTable(int numOfKeys){
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
