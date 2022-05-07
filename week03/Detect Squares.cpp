class DetectSquares {
public:
    int BASE = 1000000007;
    unordered_map<long long, int> points;
    
    DetectSquares() {
        points.clear();
    }
    
    long long getSerialised(int x, int y){
        return 1ll * x * BASE + y;
    }
    
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[getSerialised(x,y)]++;
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        int qx = point[0];
        int qy = point[1];
        
        for(auto &pnt : points){
            int x = pnt.first/BASE;
            int y = pnt.first%BASE;
            
            if(x == qx || abs(x-qx) != abs(y-qy)) continue;
            
            if(points.count(getSerialised(qx,y)) and points.count(getSerialised(x,qy))){
                cnt += points[getSerialised(qx, y)] * points[getSerialised(x,qy)] * points[getSerialised(x, y)];
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 
 
 
 
 
 
 
 */