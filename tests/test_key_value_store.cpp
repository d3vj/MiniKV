#include <cassert>
#include <iostream>
#include "../src/KeyValueStore.h"

using namespace std;

int main() {
    KeyValueStore store;

    // SET + GET
    store.set("name", "Joan");
    auto result = store.get("name");

    assert(result.second == true);
    assert(result.first == "Joan");
    cout << "[PASS] SET and GET" << endl;

    // Missing key
    result = store.get("missing");

    assert(result.second == false);
    cout << "[PASS] Missing key" << endl;

    // Overwrite existing value
    store.set("name", "MiniKV");
    result = store.get("name");

    assert(result.second == true);
    assert(result.first == "MiniKV");
    cout << "[PASS] Overwrite" << endl;

    // Multiple independent keys
    store.set("language", "C++");
    store.set("project", "MiniKV");

    assert(store.get("language").first == "C++");
    assert(store.get("project").first == "MiniKV");
    cout << "[PASS] Multiple keys" << endl;

    // REMOVE existing key
    bool removed = store.remove("name");

    assert(removed == true);
    assert(store.get("name").second == false);
    cout << "[PASS] REMOVE existing key" << endl;

    // REMOVE missing key
    removed = store.remove("does-not-exist");

    assert(removed == false);
    cout << "[PASS] REMOVE missing key" << endl;

    cout << endl;
    cout << "6/6 tests passed." << endl;

    return 0;
}