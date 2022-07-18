#include <string>
#include <vector>
#include <iostream>
#include <algorithm> //sort를 쓰기 위한 헤더파일

using namespace std;

bool compare(pair<int, double> &a, pair<int, double> &b){ // 조건에 맞는 정렬을 하기 위한 compare 함수
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> user_stg(N); // 각 stage에 머무르고 있는 user의 수
    vector<pair<int, double>> fault; // 각 stage의 실패율 (stage, 실패율)
    int users = stages.size();
    
    for(int i = 0; i < stages.size(); i++){
        if(stages[i] == N+1) continue; //모든 stage를 통과한 user는 user 수 에서 제외
        user_stg[stages[i] - 1] += 1;
    }
    for(int i = 0; i < N; i++){
        if(user_stg[i] == 0) fault.push_back({i+1, 0}); // 머무르고 있는 user의 수가 0일 때 수식의 오류를 대비한 코드
        else{
            fault.push_back({i+1, user_stg[i]/users});
        }
        users = users - user_stg[i];
    }
    sort(fault.begin(), fault.end(), compare);
    for(int i = 0; i < N; i++){
        answer.push_back(fault[i].first);
    }
    return answer;
}