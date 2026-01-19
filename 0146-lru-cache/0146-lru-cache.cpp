class LRUCache {
public:
int capacity;
list<int>dll;
map<int , pair<list<int>::iterator, int>>cache;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void maker(int key)
    {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key))return -1;
        maker(key);
        return cache[key].second;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end())return ;
        else{
            dll.push_front(key);
            cache[key]={dll.begin(), value};
          capacity--;
        }
            if(capacity < 0)
            {
              
                cache.erase(dll.back());
                dll.pop_back();
                capacity++;
            }
        }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */