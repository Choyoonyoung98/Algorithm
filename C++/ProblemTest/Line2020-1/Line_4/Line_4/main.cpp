//
//  main.cpp
//  Line_4
//
//  Created by 조윤영 on 06/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    vector<vector<string>> answer;
    
    map<string, int> m;
    set<string> s;
    vector<string> accounts;
    
    for(int i=0; i<snapshots.size(); i++) {
        string accountname = snapshots[i][0];
        int accountBudget = stoi(snapshots[i][1]);
        
        m[accountname] = accountBudget;
    }
    
    for(int i=0; i<transactions.size(); i++) {
        string currentIndex = transactions[i][0];
        string currentAct = transactions[i][1];
        string currentAccountName = transactions[i][2];
        string currentMoney = transactions[i][3];
        
        auto itr = s.find(currentIndex);
        if(itr == s.end()) {
            accounts.push_back(currentAccountName);
                    
                    
            if(currentAct == "SAVE") {
                m[currentAccountName] += stoi(currentMoney);
            }else if(currentAct == "WITHDRAW") {
                m[currentAccountName] -= stoi(currentMoney);
            }
            s.insert(currentIndex);
        }
        
    }
    //시간 남으면 set
    sort(accounts.begin(), accounts.end());
    accounts.erase(unique(accounts.begin(),accounts.end()),accounts.end());
    
    answer.assign(accounts.size(), {});
    for(int i=0; i<accounts.size(); i++) {
        answer[i] = {accounts[i], to_string(m[accounts[i]])};
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
