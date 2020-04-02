//
//  main.cpp
//  SumOfNumbers_2003
//
//  Created by 조윤영 on 01/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//투포인터
//https://www.acmicpc.net/problem/2003

#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> numbs;


void input() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>> N >> M;
    
    int numb = 0;
    
    for(int i=0; i<N; i++) {
        cin>>numb;
        numbs.push_back(numb);
    }
}
void solution() {
    int answer = 0;
    
    int start = 0;
    int end = 0;
    int sum = 0;
    
    while(1) {
        if(sum >= M)sum -= numbs[start++];//시작점을 한단계 앞으로 이동하면서 합에서 빼주기
        else if(end == N-1)break;
        else sum += numbs[end++];
        
        if(sum == M)answer++;
        
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
