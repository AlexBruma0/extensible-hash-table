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

 
    
  public:
    vector<Key> keys;
    int localDepth;
    int bucketSize;
    Bucket();
    Bucket(int numOfKeys);
    bool addKey(int value);
    bool removeKey(int value);
    bool find(int value);
    vector<Key> getKeys();
    int getLocalDepth();
   
    
};

#endif /* Bucket_hpp */
