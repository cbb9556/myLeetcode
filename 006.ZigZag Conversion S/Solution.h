#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;


        for (char c : s) {
            rows[curRow] += c;
            //curRow来回变换的关键，每当curRow到达Z形的尾部，调转方向。同理没到到达首部也调转方向
            //将字符存在string的容器中
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};