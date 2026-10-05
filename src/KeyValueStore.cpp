#include "KeyValueStore.h"

void KeyValueStore::set(string key, string value) {
    data[key] = value;
}

pair<string, bool> KeyValueStore::get(string key) {
    auto it = data.find(key);

    if (it != data.end()) {
        return {it->second, true};
    }

    return {"", false};
}

bool KeyValueStore::remove(string key) {
    auto it = data.find(key);

    if (it != data.end()) {
        data.erase(it);
        return true;
    }

    return false;
}