#include "InMemoryDB.h"


InMemoryDB::InMemoryDB()
{
    active = false;
}

void InMemoryDB::begin_transaction()
{
    if (!active) { active = true; }
}

void InMemoryDB::put(std::string key, int value)
{
    if (!active)
    {
        throw std::runtime_error("Error: No transaction in progress. Must begin a transaction before adding any key value pairs.");
    }

    auto existingKey = keys.find(key);
    auto tempKey = tempKeys.find(key);

    if (existingKey == keys.end() && tempKey == tempKeys.end())
    {
        tempKeys.emplace(key, value);
    }
    else if (existingKey != keys.end() && tempKey != tempKeys.end())
    {
        tempKey->second = value;
    }
    else if (existingKey != keys.end() && tempKey == tempKeys.end())
    {
        tempKeys.emplace(key, value);
    }
    else if (existingKey == keys.end() && tempKey != tempKeys.end())
    {
        tempKey->second = value;
    }
}


int InMemoryDB::get(std::string key)
{
    int value = -1;

    auto existingKey = keys.find(key);

    if (existingKey != keys.end())
    {
        return existingKey->second;
    }

    return value;
}

void InMemoryDB::commit()
{
    if (!active)
    {
        throw std::runtime_error("Error: No transaction in progress. Unable to commit changes.");
    }

    auto key = tempKeys.begin();

    for (; key != tempKeys.end(); key++)
    {
        auto existingKey = keys.find(key->first);

        if (existingKey != keys.end())
        {
            existingKey->second = key->second;
        }
        else
        {
            keys.emplace(key->first, key->second);
        }
    }

    active = false;
    tempKeys.clear();
}

void InMemoryDB::rollback()
{    
    if (!active)
    {
        throw std::runtime_error("Error: No transaction in progress. Unable to rollback changes.");
    }
    
    active = false;
    tempKeys.clear();
}

void InMemoryDB::printKeyValues()
{
    auto key = keys.begin();

    for (; key != keys.end(); key++)
    {
        std::cout << "(" << key->first << ", " << key->second << ") ";
    }

    std::cout << std::endl;
}