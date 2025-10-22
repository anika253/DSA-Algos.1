class Node{
    public:
    int key;
    int value;
    Node*next;
    Node*prev;
    Node( int key  , int val)
    {
        this->key = key;
        this->val = val;
      next = NULL;
        prev = NULL;
    }
}
class LRUCache {
public:
int capacity;
unordered_map<int ,Node*>mpp;
Node*head;
Node*tail;
LRUCache(int capacity)
{
    this->capacity = capacity;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev= head;
}

   void add(Node*node)
   {
    Node*temp = head->next;
    head->next = temp;
    temp->prev = head;
    node->next = temp;
    temp->prev= node;

   }
   void removeNode(Node*node)
   {
    Node*prevNode = node->prev;
    Node*nextnode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
   }
    
    int get(int key) {
        if(cache.find(key)!= cache.end())
        {
            Node*node cache[key];
            removeNode(node);
            addNode(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end())
        {
            Node*existing = cache[key];
            removeNode(existing);
            cache.erase(key);
            delete existing;
        }
        if(cache.size()==capacity)
        {
            Node*tp = tail->prev;
            removeNode(tp);
            cache.erase(tp->key);
            delete tp;
        }
        Node*nn = new Node(key , value);
        addNode(nn);
        cache[key]=nm'
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */