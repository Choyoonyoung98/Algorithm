//
//  main.cpp
//  Retire_14501
//
//  Created by 조윤영 on 08/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/14501

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int,int>> consulting;
int N = 0;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T = 0; int P = 0;
    cin>>N;
    
    for(int i=0; i<N; i++) {
        cin>>T>>P;
        consulting.push_back({T,P});
    }
    
}

void solution() {
    queue<pair<int,int>> q;
    int answer = 0;
    
    for(int i=0; i<N; i++) {
        if(i+consulting[i].first-1<N)
            q.push({i, consulting[i].second});
        
        while(!q.empty()) {
            int consultingDay = q.front().first;
            int duration = consulting[consultingDay].first;
            int profit = q.front().second;
            

            q.pop();
            
            bool hasNextConsulting = false;
            for(int j=consultingDay+1; j<N; j++) {

                if(j+consulting[j].first-1<N) {

                    if(consultingDay+duration-1<j) {

                    hasNextConsulting = true;
                    q.push({j,profit+consulting[j].second});

                    }
                }
            }
            
            if(hasNextConsulting == false) {
                //마지막 상담이라면
                answer = max(answer, profit);
            }
//            cout<<"-----------------------"<<endl;
        }
//        cout<<"=============>"<<answer;
    }
    cout<<answer<<"\n";
    
}

int main(int argc, const char * argv[]) {
    input();
    solution();
    
    return 0;
}
