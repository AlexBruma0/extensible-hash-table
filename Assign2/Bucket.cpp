//
//  Bucket.cpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#include "Bucket.hpp"
#include <iostream>

Bucket::Bucket(){
    for(int i = 0; i < 4; i++){
        keys.push_back({0,false});
    }
}

Bucket::Bucket(int numOfKeys){
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

void Bucket::removeKey(int value) {
    
    for(int i = 0; i < keys.size(); i++){
        if(keys[i].value == value){
            keys[i].taken = false;
        }
    }
    
}
vector<Key> Bucket::getKeys(){
    return keys;
}
