#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, set<string>> hsmp;
    unordered_map<string, int> resmp;
    string str[2];
    
    for(auto s : report){
        stringstream st(s);
        st >> str[0] >> str[1];
        hsmp[str[1]].insert(str[0]);
    }
    for(auto it : hsmp){
        if(it.second.size() >= k){
            for(auto it2 : it.second) resmp[it2]++;
        }
    }
    for(auto it : id_list) answer.push_back(resmp[it]);
    return answer;
}