//
//  Bucket.cpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#include "Bucket.hpp"
#include <iostream>

Bucket::Bucket(){
    localDepth = 1;
    bucketSize = 4;
    for(int i = 0; i < bucketSize; i++){
        keys.push_back({0,false});
    }
}

Bucket::Bucket(int numOfKeys){
    localDepth = 1;
    bucketSize = numOfKeys;
    for(int i = 0; i < numOfKeys; i++){
        keys.push_back({0,false});
    }
}


void Bucket::addKey(int value) {
    
    for(int i = 0; i < keys.size(); i++){
        if(keys[i].taken == false){
            keys[i].value = value;
            keys[i].taken = true;
            break;
        }
    }    
}

bool Bucket::removeKey(int value) {
    bool successful = false;
    for(int i = 0; i < keys.size(); i++){
        if(keys[i].value == value){
            keys[i].taken = false;
            successful = true;
        }
        
    }
    return successful;
    
}
vector<Key> Bucket::getKeys(){
    return keys;
}
int Bucket::getLocalDepth(){
    return localDepth;
}

bool Bucket::find(int value){
    if(value < 0)
        return false;
    bool successful = false;
    for(int i = 0; i < keys.size(); i++){
        if(keys[i].value == value && keys[i].taken == true){
            successful = true;
        }
        
    }
    return successful;
}
