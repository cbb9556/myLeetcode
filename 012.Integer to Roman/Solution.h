#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
	
public:
	string intToRoman(int num) {
		std:unordered_map<int,std::string> mymap = {
			{1000,"M"}, 
			{900,"CM"}, 
			{500, "D"},
			{400,"CD"}, 
			{100,"C"}, 
			{90,"XC"}, 
			{50,"L"}, 
			{40,"XL"}, 
			{10,"X"}, 
			{9,"IX"}, 
			{5,"V"},
			{4,"IV"}, 
			{1,"I"},
		};
			
	}
		
};