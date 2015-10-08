class LRUCache{
private:
    int m_Capacity;
    unordered_map<int, list<pair<int, int> >::iterator> m_Cache;
    list<pair<int, int> > m_RecentlyUsed;
    
public:
    LRUCache(int capacity) : m_Capacity(capacity) {
    }
    
    void updateRecentlyUsed(list<pair<int, int> >::iterator iter, int key, int value) {
        m_RecentlyUsed.erase(iter);
        m_RecentlyUsed.push_front(make_pair(key, value));
    }
    
    int get(int key) {
        auto iter = m_Cache.find(key);
        if(iter == m_Cache.end())
            return -1;
        
        int value = (*(iter->second)).second;
        updateRecentlyUsed(iter->second, key, value);
        m_Cache[key] = m_RecentlyUsed.begin();
        return value;
    }
    
    void set(int key, int value) {
        auto iter = m_Cache.find(key);
        if(iter == m_Cache.end()) {
            if(m_Cache.size() >= m_Capacity) {
                m_Cache.erase(m_RecentlyUsed.back().first);
                m_RecentlyUsed.pop_back();
            }
            m_RecentlyUsed.push_front(make_pair(key, value));
        }
        else
            updateRecentlyUsed(m_Cache[key], key, value);
        m_Cache[key] = m_RecentlyUsed.begin();
    }
};