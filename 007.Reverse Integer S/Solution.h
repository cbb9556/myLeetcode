#define Integer_MAX_VALUE 2147483647
#define Integer_MIN_VALUE -2147483648

class Solution {
private:
public:
	int reverse(int x) {
		int ans = 0;
		while (x != 0) {
			/* code */
			int pop = x % 10;
			if (((ans*10 == Integer_MAX_VALUE) && pop > 7) || ans*10 > Integer_MAX_VALUE) {
				return 0;
			}
			if (((ans*10 == Integer_MAX_VALUE) && pop > 7) || ans*10 < Integer_MIN_VALUE) {
				/* code */
				return 0;
			}
			ans = ans * 10 + pop;
			x= x/10;
		}

		return ans;
	}
};