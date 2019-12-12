//
//  main.cpp
//  Printer
//
//  Created by 조윤영 on 12/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

//큐는 FILO: First In First Out!
int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool flag = true;
    int n = 0;
    int cnt = 0;
    
    vector<int> temp = priorities;
    vector<bool> visited(temp.size(),false);
    queue<int> q;
   
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    for(int i=0; i<priorities.size(); i++) {
        q.push(priorities[i]);
    }
    
    while(flag == true){
         n = q.front();
        for(int i=0; i<temp.size(); i++) {
            cout<<n<<endl;
            if(visited[i]==false && n == temp[i]){
                cout<<i<<endl;
                cnt++;
                
                if(i==location){
                    flag = false;
                    break;
                }
                
                q.pop();
                visited[i] = true;
                n= q.front();
            }
        }
    }
    answer = cnt;
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> priorites = {1,1,9,1,1,1};
    int location = 0;
    cout<<solution(priorites, location);
    
    return 0;
}
