#include "KeyValueStore.h"
#include <fstream>

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

bool KeyValueStore::save(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    for (const auto& entry : data) {
        file << entry.first << '\t' << entry.second << '\n';
    }

    return true;
}

bool KeyValueStore::load(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    data.clear();

    string line;

    while (getline(file, line)) {
        size_t separator = line.find('\t');

        if (separator == string::npos) {
            continue;
        }

        string key = line.substr(0, separator);
        string value = line.substr(separator + 1);

        data[key] = value;
    }

    return true;
}