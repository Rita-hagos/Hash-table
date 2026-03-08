#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iomanip>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const string& key) const;
    void rehash();

public:
    HashTable(int size = 11);

    void insert(const string& key, int value);
    bool remove(const string& key);
    int search(const string& key) const;
    double loadFactor() const;
    int size() const;
    bool isEmpty() const;
    void printTable() const;

    int getCapacity() const;
    int getCollisionCount() const;
    int getMaxBucketSize() const;
    double getAverageBucketLength() const;
};

Part 2:
 int HashTable:: insert(const string& key, int value) 
{
int index = hashFunction(key);
for (auto& item : table [index]) {
if (item.first == key) {
    item.second = value ;
return ;
  }
}
if (!table[index].empty()) {
    collisionCount++;
}
table[index].push_back({key, value});
currentSize++;

if(laodFactor() > 0.75 {
    rehash();
 }
}

Part 4: Resizing
  void HashTable :: rehash() {
       vector<list<pair<string, int >>> oldTable = table;
capacity = capacity *2;
table.clear();
table.resize(capacity);

currentSize = 0;
collisionCount = 0;

for(const auto& bucket : oldTable) {
    for (const auto& item : bucket) {
       insert(item.first, item.second);
    }
  }
}

