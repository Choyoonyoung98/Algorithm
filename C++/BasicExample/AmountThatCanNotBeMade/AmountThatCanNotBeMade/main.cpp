//
//  main.cpp
//  AmountThatCanNotBeMade
//
//  Created by 조윤영 on 2020/08/09.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N = 0;
vector<int> coin;
map<int, bool> m;

void input() {
    cin>> N;
    
    coin.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin>> coin[i];
    }
}

//그리디 풀이(*)
int soluiton2() {
    int answer = 0;
    
    return answer;
    sort(coin.begin(), coin.end());
    int target = 1;
    for(int c: coin) {
        if(target < c) break;
        
        target += c;
    }
}

//DFS 풀이
void dfs(int index, int sum) {
    cout<<sum<<endl;
    for(int i= index+1; i<coin.size(); i++) {
        sum += coin[i];
        if(m[sum] == NULL)  m[sum] = true;
        dfs(i, sum);
    }
}

int  solution() {
    int sum = 0;
    
    for(int i=0; i<coin.size(); i++) {
        m[coin[i]] = true;
        dfs(i, coin[i]);
    }
    
    for(int c: coin) sum += c;
    
    for(int  i=1; i<sum+1; i++) {
        if(m[i] == NULL) return i;
    }
    
    return  sum+1;
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution()<<"\n";
    return 0;
}
