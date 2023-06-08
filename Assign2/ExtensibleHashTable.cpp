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
    for(int i = 0; i<2; i++){
        uniqueBuckets.push_back(buckets[i]);
    }
}

ExtensibleHashTable::ExtensibleHashTable(int numOfKeys){
    globalDepth = 1;
    for(int i = 0; i<2; i++){
        buckets.push_back(new Bucket(numOfKeys));
    }
    for(int i = 0; i<2; i++){
        uniqueBuckets.push_back(buckets[i]);
    }
}

void printKeys(vector<Key> keys){
    cout << "[";
    for(int j = 0; j < keys.size(); j++){
        if(j != 0)
            cout  << ",";

        if(keys[j].taken)
            cout << keys[j].value;
        else
            cout << "-";
            
    }
    cout << "] ";

}
bool ExtensibleHashTable::bucketIsUnique(Bucket * bucketPtr, int i ){
    for(int j= 0; j< uniqueBuckets.size(); j++){
        if( bucketPtr == uniqueBuckets[j] && j != i)
            return false;
    }
    uniqueBuckets.push_back(bucketPtr);
    return true;
}
void ExtensibleHashTable::print(){
    for(int i=0; i< buckets.size(); i++){
        cout << i << ": "<<buckets[i] << " --> ";
        if(bucketIsUnique(buckets[i], i)){
            vector<Key> keys = (*buckets[i]).getKeys();
            printKeys(keys);
            cout << "(" << (*buckets[i]).getLocalDepth() << ")";
        }
        cout << "\n";
    }
    uniqueBuckets.clear();
    
}
int getBucketNumber(int value, int depth){
    int sum = 0;
    for(int i = 0; i < depth; i++)
        sum += (1 << i)*((value >> i) % 2);
    
    return sum;
}

void ExtensibleHashTable::redistributeValues(Bucket * oldBucketPtr, Bucket * newBucketPtr){
    int bucketSize = (*oldBucketPtr).bucketSize;
    vector<Key> oldBucketKeys =(*oldBucketPtr).keys;
    int localdepth =(*oldBucketPtr).localDepth;
    for(int i = 0; i < bucketSize; i++){
        if (getBucketNumber(oldBucketKeys[i].value, localdepth) != getBucketNumber(oldBucketKeys[i].value, localdepth - 1) ){
            (*newBucketPtr).addKey(oldBucketKeys[i].value);
            (*oldBucketPtr).keys[i].taken = false;
        }
    }
    (*newBucketPtr).localDepth++;
}

void ExtensibleHashTable::doubleDirSize(Bucket * bucketPtr,int value){
    int bucketNumber = getBucketNumber(value, globalDepth);
    int dirSize = (1 << globalDepth);
    int newBucketNumber = bucketNumber + (1 << globalDepth);
    
    for( int i = dirSize; i < (dirSize *2); i++){
        if(i == newBucketNumber)
            buckets.push_back(new Bucket((*bucketPtr).bucketSize));
        else
            buckets.push_back(buckets[i - dirSize]);
    }
    (*bucketPtr).localDepth = (*bucketPtr).localDepth +1;
    redistributeValues(bucketPtr, buckets[newBucketNumber]);
    
}
void ExtensibleHashTable::insertNewBucket(Bucket * bucketPtr, int value){
    (*bucketPtr).localDepth++;
    int oldBucketNumber = getBucketNumber(value, globalDepth);
    int newBucketIndex = oldBucketNumber + (1 << (globalDepth - 1));
    Bucket * newBucketPtr = new Bucket((*bucketPtr).bucketSize);
    (*newBucketPtr).localDepth = (*bucketPtr).localDepth - 1;
    buckets[newBucketIndex] = newBucketPtr;
    redistributeValues(bucketPtr, newBucketPtr);
}

void ExtensibleHashTable::bucketFull(Bucket * bucketPtr, int value){
    int localDepth = (*bucketPtr).getLocalDepth();
    if(localDepth == globalDepth){
        doubleDirSize(bucketPtr,value);
        globalDepth++;
    }
    else{
        insertNewBucket(bucketPtr, value);
    }
}
bool ExtensibleHashTable::sameValueError(int value, Bucket * bucket){
    int bucketSize =(*bucket).bucketSize;
    for(int i = 0; i < bucketSize; i++){
        if(value != (*bucket).keys[i].value)
            return false;
    }
    return true;
}

void ExtensibleHashTable::insert(int value){
    
    int bucketNumber = getBucketNumber(value, globalDepth);
    Bucket * bucketPtr = buckets[bucketNumber];
    
    if (sameValueError(value, bucketPtr)){
        std::runtime_error e = std::runtime_error("inserting too many duplicate keys");
        cout << "Exception: " << e.what() << "\n";
        return;
    }
    
    if ((*bucketPtr).addKey(value)){
        return;
    }
    else{
        bucketFull(bucketPtr,value);
        insert(value);
    }
}

bool ExtensibleHashTable::remove(int value){
    int bucketNumber = getBucketNumber(value, globalDepth);
    bool successful = (*buckets[bucketNumber]).removeKey(value);
    return successful;
}

ExtensibleHashTable::~ExtensibleHashTable(){
    for( int i = 0; i < (1 << globalDepth); i++)
        if(bucketIsUnique(buckets[i], i)){
            delete buckets[i];
        }
}

bool ExtensibleHashTable::find(int value){
    int bucketNumber = getBucketNumber(value, globalDepth);
    if((*buckets[bucketNumber]).find(value))
        return true;
    else
        return false;
}


