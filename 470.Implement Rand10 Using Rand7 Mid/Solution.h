// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
#include <cstdio>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <random>                                // For random_device class
#include <iostream>
using namespace std;

class Solution {
public:
    int rand7 ()
    {
      std::random_device rd;                         // A function object for generating seeds
      /* generate secret number between 1 and 10: */
      return (rd() % 7 + 1);
    }

    int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40)
                return 1 + (idx - 1) % 10;
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60)
                return 1 + (idx - 1) % 10;
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20)
                return 1 + (idx - 1) % 10;
        }
    }
};