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

//Part 5

int main() {
    HashTable ht;

vector<string> words = {
pomegrante","march","fourth","mango","alligatoer","koala","alpaca","camel","twentysix","redfox",
        "adele","beyonce","doja","rihanna","wizkid","tems","tyla","ayrastarr","twentythree","coffee",
        "tea","latte","mocha","espresso","cappuccino","macchiato","americano","milk","sugar","lion",
        "tiger","zebra","giraffe","elephant","rhino","hippo","cheetah","leopard","hyena","apple",
        "banana","orange","grape","peach","plum","kiwi","pear","melon","berry","sun",
        "moon","star","planet","galaxy","comet","asteroid","orbit","space","rocket","table",
        "chair","lamp","sofa","desk","bed","mirror","window","door","pillow","phone",
        "laptop","keyboard","mouse","screen","speaker","charger","camera","tablet","router","river",
        "ocean","lake","mountain","forest","desert","valley","island","beach","waterfall","doctor",
        "teacher","student","artist","driver","chef","writer","dancer","singer","painter","tyla"
};

for(int i = 0; i < words.size(); i++) {
   ht.insert(words[i], i +1);
}
cout << "Table capctiy:" << ht.getCapacity() << endl;


