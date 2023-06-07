//
//  Bucket.hpp
//  Assign2
//
//  Created by Alex  Bruma on 2023-06-04.
//

#ifndef Bucket_hpp
#define Bucket_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


struct Key {
    int value;
    bool taken;
};

class Bucket {
  private:
    vector<Key> keys;
    int localDepth;
    
  public:
    int bucketSize;
    Bucket();
    Bucket(int numOfKeys);
    void addKey(int value);
    bool removeKey(int value);
    bool find(int value);
    vector<Key> getKeys();
    int getLocalDepth();
   
    
};

#endif /* Bucket_hpp */
