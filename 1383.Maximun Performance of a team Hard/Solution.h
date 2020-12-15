class Solution {
public:
    using LL = long long;

    struct Staff {
        int s, e;
        bool operator < (const Staff& rhs) const {
            return s > rhs.s;
        }
    };

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Staff> v;
        priority_queue<Staff> q;
        for (int i = 0; i < n; ++i) {
            v.push_back({speed[i], efficiency[i]});
        }
        sort(v.begin(), v.end(), [] (const Staff& u, const Staff& v) { return u.e > v.e; });
        LL ans = 0, sum = 0;
        
        for (int i = 0; i < n; ++i) {
            LL minE = v[i].e;
            LL sumS = sum + v[i].s;
            ans = max(ans, sumS * minE);
            q.push(v[i]); 
            sum += v[i].s;
            if (q.size() == k) {
                sum -= q.top().s;
                q.pop();
            }
        }
        return ans % (int(1E9) + 7);
    }
};