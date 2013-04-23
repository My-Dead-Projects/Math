#ifndef Math_ListTypes_h
#define Math_ListTypes_h

#include <vector>
using std::vector;

template <class T>
class Stack {
protected:
    vector<T> data;
public:
    void push(T obj) {
        data.push_back(obj);
    }
    T top() {
        return data.back();
    }
    void pop() {
        data.pop_back();
    }
    size_t size() {
        return data.size();
    }
    bool empty() {
        return data.empty();
    }
};

template <class T>
class Queue {
protected:
    vector<T> data;
public:
    void push(T obj) {
        data.push_back(obj);
    }
    T front() {
        return data.front();
    }
    void pop() {
        data.erase(data.begin());
    }
    size_t size() {
        return data.size();
    }
    bool empty() {
        return data.empty();
    }
};

#endif
