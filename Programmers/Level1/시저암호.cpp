#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') continue;
        else if(s[i] < 97) s[i] = ((s[i] - 65 + n) % 26) + 65;
        else s[i] = ((s[i] - 97 + n) % 26) + 97;
    }
    return s;
}