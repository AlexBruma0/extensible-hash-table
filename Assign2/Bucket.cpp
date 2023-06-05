//
//  Bucket.cpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#include "Bucket.hpp"
#include <iostream>


void Bucket::addKey(int value) {
    
    for(int i = 0; i < bucketSize; i++){
        if(keys[i].taken == false){
            keys[i].value = value;
            keys[i].taken = true;
            break;
        }
    }    
}

void Bucket::removeKey(int value) {
    
    for(int i = 0; i < bucketSize; i++){
        if(keys[i].value == value){
            keys[i].taken = false;
        }
    }
    
}
