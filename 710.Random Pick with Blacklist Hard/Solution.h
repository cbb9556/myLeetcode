class Solution {
public:

    unordered_map<int, int> m;
    int wlen;

    Solution(int n, vector<int> b) {
        wlen = n - b.size();
        unordered_set<int> w;
        for (int i = wlen; i < n; i++) w.insert(i);
        for (int x : b) w.erase(x);
        auto wi = w.begin();
        for (int x : b)
            if (x < wlen)
                m[x] = *wi++;
    }

    int pick() {
        int k = rand() % wlen;
        //由于m中只存储了，高位不是b中的数据，其他的数据，还是按照k存储的；
        return m.count(k) ? m[k] : k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */