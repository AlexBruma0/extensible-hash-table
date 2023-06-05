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
using namespace std;
const int bucketSize = 4;

struct key {
    int value;
    bool taken = false;
};

class Bucket {
  private:
    key keys[bucketSize];
    
  public:
    void addKey(int value);
    void removeKey(int value);
};

#endif /* Bucket_hpp */
