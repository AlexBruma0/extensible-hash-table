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
    
  public:

    Bucket();
    Bucket(int numOfKeys);
    void addKey(int value);
    void removeKey(int value);
    vector<Key> getKeys();
    
};

#endif /* Bucket_hpp */
