class MyHashMap {
   public:
    vector<vector<int> > myMap;

    MyHashMap() {
    }

    int isExist(int key) {
        for (int i = 0; i < myMap.size(); i++) {
            if (myMap[i][0] == key) return i;
        }
        return -1;
    }

    void put(int key, int value) {
        int idx = isExist(key);
        if (idx == -1)
            myMap.push_back({key, value});
        else {
            myMap[idx][1] = value;
        }
    }

    int get(int key) {
        int idx = isExist(key);
        if (idx == -1)
            return -1;
        else
            return myMap[idx][1];
    }

    void remove(int key) {
        int idx = isExist(key);
        if (idx != -1) myMap.erase(myMap.begin() + idx);
    }
};