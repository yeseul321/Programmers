#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mp;
    for(auto c : completion){
        mp[c]--;
    }
    for(auto p : participant){
        mp[p]++;
        if(mp[p]>0) return p;
    }

    return answer;
}