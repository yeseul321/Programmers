#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> ans_st;
    int a = 0, b = 0;
    for(int i = 0; i < moves.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[j][moves[i] - 1] != 0){
                if(!ans_st.empty() && ans_st.top() == board[j][moves[i] - 1]){
                    ans_st.pop();
                    answer+=2;
                }
                else ans_st.push(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}