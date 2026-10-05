#ifndef KEYVALUESTORE_H
#define KEYVALUESTORE_H

#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class KeyValueStore {
public:
    void set(string key, string value);
    pair<string, bool> get(string key);
    bool remove(string key);

private:
    unordered_map<string, string> data;
};

#endif