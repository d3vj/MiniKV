# MiniKV

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