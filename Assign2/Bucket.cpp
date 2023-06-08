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

bool Bucket::addKey(int value) {

    for(int i = 0; i < keys.size(); i++){
        if(keys[i].taken == false){
            keys[i].value = value;
            keys[i].taken = true;
            return true;
        }
    }
    return false;
}

bool Bucket::removeKey(int value) {
    bool successful = false;
    for(int i = 0; i < keys.size(); i++){
        if(keys[i].value == value && keys[i].taken == true){
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

void Bucket::reorganizeKeys(){
    for(int j = 0; j < bucketSize; j++){
        for(int i = 0; i < bucketSize - 1; i++){
            if(keys[i].taken == false && keys[i + 1].taken == true)
                std::swap(keys[i], keys[i+1]);
        }
    }

}
