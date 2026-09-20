# MiniKeyValue

A small persistent key-value storage engine written in C++.

## MVP
- SET key value
- GET key
- DELETE key
- Store data in memory
- Save data to disk
- Load data when program starts

## Architecture
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


Session Log — September 19, 2026

Completed

* Created initial project structure and GitHub repository.
* Designed initial architecture:
    CLI → Command Parser → KeyValueStore → unordered_map → Persistence → Disk
* Implemented KeyValueStore.
* Added set(), get(), and remove().
* Tested insertion, retrieval, and deletion.
* Tested deleting nonexistent keys.
* Discovered that unordered_map::operator[] can create a missing key.
* Changed get() to use find() so reads do not accidentally create keys.
* Started basic CLI input with cin.
* Committed and pushed changes to GitHub.
* Added .gitignore and stopped tracking .DS_Store.
* Ended with a clean working tree.

What I Learned

* unordered_map stores key/value pairs using hashing.
* find() returns an iterator.
* end() represents the “not found” boundary for a lookup.
* erase() removes an entry.
* operator[] can modify the map even when used during a lookup.
* Git tracks files rather than understanding whether they are useful project files.
* .gitignore prevents unwanted files from being tracked.

Next Session

1. Parse commands such as SET name Joan.
2. Connect parsed commands to KeyValueStore.
3. Support GET and DELETE through the CLI.
4. Handle invalid/missing commands cleanly.
5. Add automated tests.
6. Begin persistence after the CLI is working.

Current State

Core in-memory storage is working. Basic CLI input is working. Full command parsing is the next milestone.