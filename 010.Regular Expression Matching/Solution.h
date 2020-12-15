// 容易理解的版本 200ms
class Solution {
public:
    bool isMatch(string s, string p) {
    	//如果p为空，那么如果s也为空，则匹配。
        if (p.empty()) return s.empty();
        
        //由于是递归，首先检查s是不是已经为空，不为空则检查第一个字符是否相同。
        auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        
        //讨论p的第二个字符是不是* （记住这里是递归内部的p为第二个字符）；
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else {
        	//如果第二个字符不是*，或者只剩下一个字符，继续匹配余下的字符
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// 优化后的版本 20ms, 直接操作指针所用的时间比直接操作string所用的时间要短的多
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char* s, const char* p) {
        if(*p == 0) return *s == 0;
        //由于p不为空，此时如果s为空，那么返回false。如果s所指字符不为空，开始比较是否匹配
        auto first_match = *s && (*s == *p || *p == '.');
        
        if(*(p+1) == '*'){
            return isMatch(s, p+2) || (first_match && isMatch(++s, p));
        }
        else{
            return first_match && isMatch(++s, ++p);
        }
    }
};