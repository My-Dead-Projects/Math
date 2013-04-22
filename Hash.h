#ifndef Math_Hash_h
#define Math_Hash_h

#include "Expression.h"
#include <vector>
#include <utility>

class HashForToken {
public:
    size_t operator()(Token value) {
        size_t hashcode = 0;
        for (char c : value) {
            hashcode += static_cast<size_t>(c);
        }
        return hashcode;
    }
};

template <class Key, class Value, class HashFunction>
class UnorderedMap {
    
    std::vector<std::vector<std::pair<Key, Value> > > table;
    HashFunction hash;
    
public:
    
    UnorderedMap(size_t n = 1024) : table(n) {}
    
    void insert(Key key, Value value) {
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
