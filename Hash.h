#ifndef Math_Hash_h
#define Math_Hash_h

#include "Expression.h"
#include <vector>
#include <utility>

template <class Key, class Value, class HashFunction>
class UnorderedMap {
    
    std::vector<std::vector<std::pair<Key, Value> > > table;
    HashFunction hash;
    
public:
    
    UnorderedMap(size_t n = 1024) : table(n) {}
    
    void insert(Key key, Value value) {
        try {
            find(key) = value;
        } catch (Key) {}
        table[hash(key)%table.size()].push_back(std::make_pair(key, value));
    }
    
    Value& find(Key key) {
        for (std::pair<Key, Value>& pair : table[hash(key)]) {
            if (key == pair.first) {
                return pair.second;
            }
        }
        throw key;
    }

};

#endif
