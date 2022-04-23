class RandomizedSet {
public:
    unordered_set<int> uset;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        int ans = uset.count(val) == 1 ? true : false;
        uset.insert(val);
        return !ans;
    }
    
    bool remove(int val) {
        int ans = uset.count(val) == 1 ? true : false;
        uset.erase(val);
        return ans;
    }
    
    int getRandom() {
        int offset = rand()%uset.size();
        auto base = uset.begin();
        return *next(base, offset);
    }
};
