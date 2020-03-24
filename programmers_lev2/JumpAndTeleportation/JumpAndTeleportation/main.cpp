//
//  main.cpp
//  JumpAndTeleportation
//
//  Created by 조윤영 on 24/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_SIZE 50000

using namespace std;

int solution(int n)
{
    int answer = 0;
    
    //무작정 bfs, dfs, dp 중에서 접근하려고 하지 말기..

    while (n > 0)
    {
        answer += n % 2;
        n /= 2;
    }
    
    return answer;
}

//무한루프에 빠진 풀이
int solution2(int n)
{
    int answer = MAX_SIZE;
    
    //bfs?
    queue<pair<int,int>> q; //위치, 사용량
    q.push({1,1});
    
    while(!q.empty()) {
        
        int index = q.front().first;
        int useBatteryCnt = q.front().second;
        q.pop();
        
        cout<<"["<<index<<"]"<<endl;
        if(index == n) {
            cout<<useBatteryCnt<<endl;
            answer = min(answer, useBatteryCnt);
            continue;
        }
    
        
        //순간이동
        if(index*2 <=n) q.push({index*2, useBatteryCnt});
        
        //점프
        if(index +1 <=n) q.push({index+1, useBatteryCnt+1});
        
    }
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 6;
    cout<<solution(n);
    
    return 0;
}
