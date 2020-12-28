#include <vector>
#include <queue>
using namespace std;
using PII = pair<int, int>;

class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& d) {
        int n = a.size();
        int ans = 0, i = 0;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({d[0], a[0]});
        while (!q.empty() || i < n) {
            while (!q.empty() && (q.top().first <= i || q.top().second <= 0)) q.pop(); 
            if (!q.empty()) {
                auto p = q.top(); q.pop();
                q.push({p.first, p.second - 1});
                ans++;
            }
            i++;
            if (i < n) q.push({i + d[i], a[i]});
        }
        return ans;
    }
};