#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

class InMemoryDB
{
    std::unordered_map<std::string, int> keys;
    std::unordered_map<std::string, int> tempKeys;

    bool active;

    public:

    InMemoryDB();

    // starts a new transaction
    // Only 1 transaction can exist at a time 
    void begin_transaction();

    // Creates a new key with the provided value if a key doesn't exist
    // Otherwise, update the value of the existing key
    // throws an exception if called when a transaction is not in progress
    void put(std::string key, int value);

    // Returns the value associated with the key or -1 if the key doesn't exist
    // can be called anytime, even when a transaction is not in progress
    // TODO: cannot return null without using Integer class or int pointers, so using -1 instead
    int get(std::string key);

    // applies changes made within the transaction to the main state
    // allowing any future gets() to "see" if the changes made within the transaction
    // throws an error if no transaction in progress
    void commit();

    // Abort all the changes made within the transaction and 
    // everything should go back to the way it was before
    // throws an error if no transaction in progress
    void rollback();

    void printKeyValues();
};