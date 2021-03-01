//
//  main.cpp
//  RestoreDatabase_Line2020_1
//
//  Created by 조윤영 on 2021/02/28.
//

#define MAX_SIZE 100000
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    vector<vector<string>> answer;
    map<string, int> m;
    bool visited[MAX_SIZE];
    //계좌정보 map에 초기화
    for(int i=0; i<snapshots.size(); i++) {
        string account = snapshots[i][0];
        int cash = stoi(snapshots[i][1]);
        m[account] = cash;
    }
    
    for(int i=0; i<transactions.size(); i++) {
        int id = stoi(transactions[i][0]);
        string action = transactions[i][1];
        string account = transactions[i][2];
        int cost = stoi(transactions[i][3]);
        
        if(visited[id]) continue;
        
        visited[id] = true;
        if(m[account] == NULL) m[account] = 0;
        if(action == "SAVE") {
            m[account] += cost;
        } else { //"WITHDRAW"
            m[account] -= cost;
        }
    }

    for(auto iter = m.begin(); iter != m.end(); iter++) { //iter++
        string account = iter->first;
        string cash = to_string(iter->second);
        vector<string> a = {account, cash};
        answer.push_back(a);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(int argc, const char * argv[]) {
    //계좌 이름, 잔액
    vector<vector<string>> snapshots = {{"ACCOUNT1", "100"}, {"ACCOUNT2", "150"}};
    //ID, 동작종류, 계좌 이름, 출금 금액
    //SAVE, WITHDRAW
    vector<vector<string>> transactions = {{"1", "SAVE", "ACCOUNT2", "100"}, {"2", "WITHDRAW", "ACCOUNT1", "50"}, {"1", "SAVE", "ACCOUNT2", "100"}, {"4", "SAVE", "ACCOUNT3", "500"}, {"3", "WITHDRAW", "ACCOUNT2", "30"}};
    solution(snapshots, transactions);
    return 0;
}
