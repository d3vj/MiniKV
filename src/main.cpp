#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class KeyValueStore {
public:
    void set(string key, string value);
    string get(string key);
    bool remove(string key);

private:
unordered_map<string , string> data ;
    


};

void KeyValueStore::set(string key, string value) {
    data[key] = value;
}


string KeyValueStore::get(string key) {
    if (data.find(key) != data.end()) {
        return data[key];
    } else {
        return "";
    }
}

bool KeyValueStore::remove(string key) {
    if (data.find(key) != data.end()) {
        data.erase(key);
        return true;
    } else {
        return false;
    }
}

int main() {
    KeyValueStore store;

    store.set("name", "Joan");

    cout << "Before delete: [" << store.get("name") << "]" << endl;

    cout << "Deleted: " << store.remove("name") << endl;

    cout << "After delete: [" << store.get("name") << "]" << endl;

    cout << "Delete again: " << store.remove("name") << endl;

    return 0;
}