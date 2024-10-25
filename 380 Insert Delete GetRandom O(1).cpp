//#include <unordered_set>
class RandomizedSet {
public:
    vector<int> elements;
    unordered_map<int,int> myMap;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (myMap.count(val) < 1) {
            elements.push_back(val);
            myMap.insert({val, elements.size() - 1});
            return true;
        }
        else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (myMap.count(val) > 0) {
            int index = myMap.at(val);

            elements.at(index) = elements.at(elements.size() - 1);
            myMap.at(elements.at(index)) = index;
            
            elements.pop_back();
            myMap.erase(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    int getRandom() {
        return elements.at(rand() % (elements.size()));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */