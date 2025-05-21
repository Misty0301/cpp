#include <iostream>
#include <vector>
#include <string>
#include <list>

class HashTable {
    private:
        int TABLE_SIZE = 10;
        std::vector<std::list<std::pair<int, std::string>>> table;
        int HashFunction (const std::string& key){
            int hash = 0;
            for (char ch : key){
                hash += ch;
                return hash % TABLE_SIZE;
            }
        }
    
    public:
        HashTable() : table(TABLE_SIZE) {};
        void insert(const std::string& key, int value){
            int index = HashFunction(key);
            for (auto& pair : table[index]){
                
            }
        }
}