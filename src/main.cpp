#include <iostream>
#include "InMemoryDB.h"

int main(int argc, char* argv[]) 
{ 
    
    // Look at Figure 2

    InMemoryDB db;

    
    // Returns -1
    std::cout<< db.get("A") << std::endl;

    // throws an error bc transaction is not in progress
    //db.put("A", 5);
    
    // starts a new transaction
    db.begin_transaction();

    // set's value of A to 5, but not committed yet
    db.put("A", 5);

    // Returns -1
    std::cout<< db.get("A") << std::endl;

    // update A's value to 6 within the transaction
    db.put("A", 6);

    // commits the open transaction
    db.commit();

    // should return 6, that was the last value of A to be committed
    std::cout<< db.get("A") << std::endl;

    // throws an error, bc there is no open transaction
    //db.commit();

    // throws an error, bc there is no ongoing transaction
    //db.rollback();

    // should return null bc B does not exist in the database
    std::cout<< db.get("B") << std::endl;

    // starts a new transaction
    db.begin_transaction();

    // set key B's value to 10 within the transaction
    db.put("B", 10);

    // Rollback the transaction - revert any changes made to B
    db.rollback();

    // should return null bc changes to B were rolled back
    std::cout<< db.get("B") << std::endl;
    
    return 0;
}