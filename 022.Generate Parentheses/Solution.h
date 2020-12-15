#include <vector>
#include <iostream>
#include <string>
#include <functional>

using std::string; using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        std::function<void(string, int, int)> addParenthesis = [&](string str, int ln, int rn) {
            if (ln == 0 && rn == 0) vec.push_back(str);
            if (ln > 0) addParenthesis(str+"(", ln-1, rn+1);
            if (rn > 0) addParenthesis(str+")", ln, rn-1);
        };
        addParenthesis("", n, 0);
        return vec;
    }
};

//暴力法 
class Solution2 {
    bool valid(const string& str) {
        int balance = 0;
        for (char c : str)
            if (c == '(')
                ++balance;
            else {
                --balance;
                if (balance < 0)
                    return false;
            }
        return balance == 0;
    }

    void generate_all(string& current, int n, vector<string>& result) {
        //当 构造出了一个“string”，那么就开始返回
        //
        if (n == current.size()) {
            if (valid(current))
                result.push_back(current);
            return;
        }
        current += '(';
        generate_all(current, n, result);
        //删除字符串最后一个
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }
};


class Solution3 {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            std::cout<<cur<<std::endl;
            return;
        }

        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};