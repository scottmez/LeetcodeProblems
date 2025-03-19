class LRUCache {
    private:
        int capacity;
        list<int> lru; //stores the keys
        unordered_map<int, pair<int, list<int>::iterator>> cache; //stores the key and value, and the iterator to the key in the lru list

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }
        
        int get(int key) {
            unordered_map<int, pair<int, list<int>::iterator>>::iterator p = cache.find(key);
            if (p == cache.end()) {
                return -1;
            }
            lru.erase(p->second.second); //could put key here instead of p->second.second
            lru.push_front(key);
            cache[key] = {p->second.first, lru.begin()};
            return p->second.first;
        }
        
        void put(int key, int value) {
            if (cache.find(key) != cache.end()) { //find() returns end if the key is not found
                lru.erase(cache[key].second); //erase the key from the lru list
                //we do this because we are going to add it to the front of the list (to update the most recently used)
            }
            lru.push_front(key);
            cache[key] = {value, lru.begin()}; 
            if (lru.size() > capacity) {
                cache.erase(lru.back());
                lru.pop_back();
            }
            return;
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */