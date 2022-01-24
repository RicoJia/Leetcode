class LRUCache {
public:
    LRUCache(int capacity): cap_(capacity) {
        
    }
    
    int get(int key) {
        if (mp_.count(key) == 0)
            return -1; 
        q_.erase(std::find(q_.begin(), q_.end(), key));
        q_.push_back(key);
        return mp_[key]; 
    }
    
    void put(int key, int value) {
        if (q_.size() == cap_ && mp_.count(key) == 0){
            evict(); 
        }
        mp_[key] = value; 
        q_.push_back(key); 
    }
private: 
    unordered_map<int, int> mp_; 
    deque<int> q_; 
    int cap_;
    
    void evict(){
        // pop empty stack? 
        if (!q_.empty()){
                int top_key = q_.front(); 
            q_.pop_front(); 
            mp_.erase(top_key); 
        }
        
    }
};

