class LRUCache{
public:
	LRUCache(int capacity)
	{
		this->capacity = capacity;
	}

	int get(int key)
	{
		if (hashTable.count(key))
		{
			auto it = hashTable[key];
			auto p = *it;
			cache.erase(it);
			cache.push_front(p);
			hashTable[key] = cache.begin();
			return p.second;
		}
		else
		{
			return -1;
		}
	}

	void set(int key, int value)
	{
		if (hashTable.count(key))
		{
			auto it = hashTable[key];
			cache.erase(it);
		}
		else if (hashTable.size() == capacity)
		{
			hashTable.erase((*cache.rbegin()).first);
			cache.pop_back();
		}
		cache.push_front(make_pair(key, value));
		hashTable[key] = cache.begin();
	}

private:
	list<pair<int, int> > cache;
	unordered_map<int, list<pair<int, int> >::iterator> hashTable;
	int capacity;
};