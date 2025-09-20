class Router {
public:
    queue<tuple<int, int, int>> q;
    set<tuple<int, int, int>> st;
    unordered_map<int, deque<int>> destTimes; 
    int memoryLimit;

    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> packet = {source, destination, timestamp};
        if (st.find(packet) != st.end()) {
            return false;
        }

        if (memoryLimit == 0) {
            return false;
        }

        if ((int)q.size() >= memoryLimit) {
            auto old = q.front();
            q.pop();
            st.erase(old);

            int oldDest = get<1>(old);
            int oldTs = get<2>(old);
            auto &dqOld = destTimes[oldDest];
            if (!dqOld.empty() && dqOld.front() == oldTs) {
               
                dqOld.pop_front();
            } else {
               
                auto it = find(dqOld.begin(), dqOld.end(), oldTs);
                if (it != dqOld.end()) dqOld.erase(it);
            }
            if (dqOld.empty()) destTimes.erase(oldDest);
        }

        q.push(packet);
        st.insert(packet);

        auto &dq = destTimes[destination];
        if (dq.empty() || timestamp >= dq.back()) {
            dq.push_back(timestamp);
        } else {
            auto it = upper_bound(dq.begin(), dq.end(), timestamp);
            dq.insert(it, timestamp);
        }

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto [sr, ds, ts] = q.front();
        q.pop();
        st.erase({sr, ds, ts});

        auto &dq = destTimes[ds];
        if (!dq.empty() && dq.front() == ts) {
            dq.pop_front();
        } else {
            auto it = find(dq.begin(), dq.end(), ts);
            if (it != dq.end()) dq.erase(it);
        }
        if (dq.empty()) destTimes.erase(ds);

        return {sr, ds, ts};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimes.find(destination);
        if (it == destTimes.end()) return 0;
        auto &dq = it->second;
        auto lb = lower_bound(dq.begin(), dq.end(), startTime);
        auto ub = upper_bound(dq.begin(), dq.end(), endTime);
        return (int)(ub - lb);
    }
};