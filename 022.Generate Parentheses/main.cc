#include "Solution.h"
#include <iostream>

int main()
{
    Solution3 s;
    for (auto str : s.generateParenthesis(3))
        std::cout << str << std::endl;
    return 0;
} 
