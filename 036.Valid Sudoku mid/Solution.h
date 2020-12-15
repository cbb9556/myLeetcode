#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};// 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
        // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
        int col[9][10] = {0};// 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
        int box[9][10] = {0};// 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
        for(int i=0; i<9; i++){
            for(int j = 0; j<9; j++){
                // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
                // 同时判断这个数在其所在的列有没有出现过
                // 同时判断这个数在其所在的box中有没有出现过
                if(board[i][j] == '.') continue;
                int curNumber = board[i][j]-'0';//将字符变化为数字
                if(row[i][curNumber]) return false; //如果出现过那么错误
                if(col[j][curNumber]) return false;
                if(box[j/3 + (i/3)*3][curNumber]) return false;

                row[i][curNumber] = 1;// 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
                col[j][curNumber] = 1;
                box[j/3 + (i/3)*3][curNumber] = 1;
            }
        }
        return true;
    }
};

//hashmap
class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> row(9), col(9), block(9);
        for(int i = 0; i < 9; ++ i){
            for(int j = 0; j < 9; ++ j){
                int bindex =  (i / 3)* 3 + j / 3;
                char cur = board[i][j];
                if(cur == '.')  continue;
                //如果当前的值在这个hash里面，那么返回1，也就是说这个值出现了两次返回0
                if(row[i].count(cur) || col[j].count(cur) || block[bindex].count(cur))  return false;
                row[i][cur] = 1;
                col[j][cur] = 1;
                block[bindex][cur] = 1;
            }
        }
        return true;
    }
};

//hashset
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9), col(9), block(9);
        for(int i = 0; i < 9; ++ i){
            for(int j = 0; j < 9; ++ j){
                int bindex =  (i / 3)* 3 + j / 3;
                char cur = board[i][j];
                if(cur == '.')  continue;
                if(row[i].count(cur) || col[j].count(cur) || block[bindex].count(cur))  return false;
                row[i].insert(cur);
                col[j].insert(cur);
                block[bindex].insert(cur);
            }
        }
        return true;
    }
};