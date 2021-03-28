#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "HashTable.hpp"


HashTabel::HashTabel(){
    // HashTabel::hashT[HashTabel::TABEL_SIZE];

}
int HashTabel::hash_funtion(std::string key){

    int hash = 17;
    int index;
    for (size_t i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % TABEL_SIZE;
    
    return index ;
}
int HashTabel::getHashT(){
    return HashTabel::hashT->size();
}
void HashTabel::insert(int Key,Book V){
    HashTabel::hashT[Key].push_back(V);
}

