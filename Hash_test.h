#ifndef Math_Hash_test_h
#define Math_Hash_test_h

#include "Hash.h"
#include "Double.h"
#include <iostream>
using std::cout;
using std::endl;

void Hash_test() {
    UnorderedMap<Token, Double, HashForToken> umap;
    
    umap.insert("hello", 1362);
    umap.insert("world", 2904);
    Double hello = umap.find("hello");
    Double world = umap.find("world");
    
    cout<<world.value()<<endl;
    cout<<hello.value()<<endl;
    
}

#endif
