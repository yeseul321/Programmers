// 아스키코드 값을 이용하여 풀이. (A : 65 ~ , a : 97 ~ )
// 공백문자는 예외적으로 둬야 하므로 먼저 조건문을 달아준다.
// 이후 알파벳일 경우에 A-Z 또는 a-z 까지 회전(?) 하면서 n만큼 변환되어야 하므로 % 연산자를 이용하였다.

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
