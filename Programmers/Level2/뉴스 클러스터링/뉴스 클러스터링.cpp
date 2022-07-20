#include <string>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int interact = 0, uni = 0;
    unordered_map<string, int> map1, map2;
    unordered_set<string> strset;

    //문자들 모두 대문자로 통일
    for(int i = 0; i < str1.size(); i++){
        if(islower(str1[i])) str1[i] = toupper(str1[i]);
    }
    for(int i = 0; i < str2.size(); i++){
        if(islower(str2[i])) str2[i] = toupper(str2[i]);
    }

    cout << str1 << str2;

    //두 문자 다 알파벳인 경우에만 map의 수 올려주기
    for(int i = 0; i < str1.size(); i++){
        if((str1[i]>='A' && str1[i]<='Z') && (str1[i+1]>='A' && str1[i+1]<='Z')){
            map1[str1.substr(i, 2)]++;
            strset.insert(str1.substr(i, 2));
        }
    }
    for(int i = 0; i < str2.size(); i++){
        if((str2[i]>='A' && str2[i]<='Z') && (str2[i+1]>='A' && str2[i+1]<='Z')){
            map2[str2.substr(i, 2)]++;
            strset.insert(str2.substr(i, 2));
        }
    }

    for(auto s : strset){
        interact += min(map1[s], map2[s]);
        uni += max(map1[s], map2[s]);
    }

    if(interact + uni == 0) answer = 65536;
    else answer = ((double)interact/uni) * 65536;

    return answer;
}