#include <cassert>
#include <iostream>
#include <cstdio>
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

    // Persistence: save and reload
    {
        KeyValueStore original;
        original.set("name", "Joan Contreras");
        original.set("project", "MiniKV");

        assert(original.save("test_minikv.db"));

        KeyValueStore loaded;
        assert(loaded.load("test_minikv.db"));

        assert(loaded.get("name").second == true);
        assert(loaded.get("name").first == "Joan Contreras");
        assert(loaded.get("project").first == "MiniKV");

        cout << "[PASS] Save and reload" << endl;
    }

    // Overwritten value persists
    {
        KeyValueStore store;
        store.set("language", "Java");
        store.set("language", "C++");

        assert(store.save("test_minikv.db"));

        KeyValueStore loaded;
        assert(loaded.load("test_minikv.db"));
        assert(loaded.get("language").first == "C++");

        cout << "[PASS] Overwrite persists" << endl;
    }

    // Deleted key stays deleted
    {
        KeyValueStore store;
        store.set("temporary", "value");
        store.remove("temporary");

        assert(store.save("test_minikv.db"));

        KeyValueStore loaded;
        assert(loaded.load("test_minikv.db"));
        assert(loaded.get("temporary").second == false);

        cout << "[PASS] Deletion persists" << endl;
    }

    // Missing database file should not crash
    {
        KeyValueStore store;

        bool loaded = store.load("file_that_does_not_exist.db");

        assert(loaded == false);

        cout << "[PASS] Missing file handled" << endl;
    }

    // Clean up test database
    remove("test_minikv.db");

    cout << endl;
    cout << "10/10 tests passed." << endl;

    return 0;
}