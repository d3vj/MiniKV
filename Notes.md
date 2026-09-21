# MiniKV

A small persistent key-value storage engine written in C++.

## MVP

- `SET key value` — insert or update a key-value pair
- `GET key` — retrieve a value by key
- `DELETE key` — remove a key-value pair
- Store data in memory
- Persist data to disk
- Load persisted data when the program starts

## Architecture

```text
CLI
 ↓
Command Parser
 ↓
KeyValueStore
 ↓
unordered_map
 ↓
Persistence
 ↓
Disk
```

## Current State

The core in-memory storage layer is implemented and the CLI can execute basic commands.

Implemented:

- `set()`
- `get()`
- `remove()`
- `SET` CLI command
- `GET` CLI command
- `REMOVE` CLI command
- Command loop using `while`
- `EXIT` command
- Iterator-based lookups and deletion

Persistence and a more complete command parser have not been implemented yet.

---

# Session Log — September 19, 2026

## Built

- Created the initial C++ project structure and GitHub repository.
- Implemented `KeyValueStore` using `std::unordered_map<std::string, std::string>`.
- Implemented:
  - `set()`
  - `get()`
  - `remove()`
- Added basic CLI input.
- Added `.gitignore` and stopped tracking macOS metadata files.
- Committed and pushed changes to GitHub.

## Learned

- `std::unordered_map` is a hash table that stores key-value pairs.
- Hashing maps a key to a bucket so the table can locate entries efficiently.
- Different keys can hash to the same bucket, creating collisions.
- `unordered_map` lookup is **O(1) average case**, with worse behavior possible when collisions are significant.
- `find(key)` returns an iterator to the matching key-value entry.
- `it->first` accesses the key and `it->second` accesses the value.
- `data.end()` is the special iterator used to indicate that a lookup did not find a matching entry.
- `erase(it)` removes the key-value entry referenced by the iterator.
- `operator[]` can modify an `unordered_map`, so using it for lookup can accidentally create a missing key.
- Using `find()` in `get()` avoids that unintended modification.
- Using the iterator returned by `find()` allows `get()` and `remove()` to reuse the lookup result instead of searching for the same key again.
- `while (true)` can keep the CLI running for an unknown number of commands.
- `break` exits the nearest loop.
- CLI commands and keys are currently case-sensitive.

## Testing

Verified:

- Insert a key-value pair with `SET`.
- Retrieve an existing key with `GET`.
- Retrieve a missing key.
- Remove an existing key with `REMOVE`.
- Attempt to remove a nonexistent key.
- Continue executing multiple commands in one program session.
- Exit the CLI with `EXIT`.

Example:

```text
MiniKV > SET Dog Bark
MiniKV > GET Dog
Bark
MiniKV > REMOVE Dog
1
MiniKV > GET Dog

MiniKV > REMOVE Dog
0
MiniKV > EXIT
```

## Current Implementation

### `get()`

```cpp
string KeyValueStore::get(string key) {
    auto it = data.find(key);

    if (it != data.end()) {
        return it->second;
    }

    return "";
}
```

### `remove()`

```cpp
bool KeyValueStore::remove(string key) {
    auto it = data.find(key);

    if (it != data.end()) {
        data.erase(it);
        return true;
    }

    return false;
}
```

Both operations use the iterator returned by `find()`.

---

# Session Log — September 20, 2026

## Built

- Connected the CLI to a `KeyValueStore` instance.
- Added `SET` command handling.
- Added `GET` command handling.
- Added `REMOVE` command handling.
- Added a command loop so the program accepts multiple operations without restarting.
- Added `EXIT` to terminate the CLI.

## Learned

- `main()` creates a `KeyValueStore` object that remains alive while the command loop runs.
- The CLI translates user input into calls to the storage layer.
- The storage layer does not need to know how commands are entered.
- `cin >>` reads whitespace-separated tokens, so `SET Dog Bark` is parsed as separate command, key, and value tokens.
- The CLI and storage engine are currently simple enough to understand end-to-end, but command parsing is still basic.
- An unknown command currently produces no error message and simply returns to the prompt.

## Next

1. Improve command handling and report unknown commands.
2. Decide on consistent CLI command names (`REMOVE` vs. `DELETE`).
3. Add automated tests for `set()`, `get()`, and `remove()`.
4. Test edge cases such as empty values and repeated `SET` operations.
5. Design the persistence layer before implementing file I/O.
6. Implement saving data to disk.
7. Implement loading data when MiniKV starts.

## Engineering Questions

- How should commands be parsed and validated?
- What should `GET` return when a key does not exist?
- Should `SET key value` allow spaces inside the value?
- Should the CLI use `REMOVE` or `DELETE`?
- What file format should MiniKV use for persistence?
- When should data be written to disk?
- What should happen if the persistence file is missing or corrupted?

---

# Git

Repository is maintained with incremental commits as features are implemented and tested.

Current development principle:

> Understand the data structure, control flow, and tradeoffs before adding the next feature.