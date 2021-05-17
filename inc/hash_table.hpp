#include <iostream>
#include <list>
#include <cstring>

class HashTable
{
 public:
	static const int hashGroups = 10;
	std::list<std::pair<int, std::string>> table[hashGroups];
 private:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, std::string value);
	void removeItem(int key);
	std::string searchTable(int key);
	void printTable();
};

bool HashTable::isEmpty() const
{
	int sum{};
	for (int i = 0; i < hashGroups; ++i)
		sum += table[i].size();
	if (!sum)
		return true;
	return false;
}

int HashTable::hashFunction(int key)
{
	return key % hashGroups;
}

void HashTable::insertItem(int key, std::string value)
{

}
