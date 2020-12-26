//
//  main.cpp
//  TravelPlan
//
//  Created by 조윤영 on 2020/09/03.
//  Copyright © 2020 조윤영. All rights reserved.
//
//여행 계획
//UnionSet

#include <iostream>
#include <vector>
#define MAX_SIZE 501
using namespace std;

int N, M = 0;
int parent[MAX_SIZE];
vector<int> plan;


int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

string solution() {
    cin>> N>>M;
    
    for(int i=1; i<=N; i++) parent[i] = i;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int x = 0;
            cin>> x;
            if(x == 1) unionParent(i, j); //연결됐을 경우 합집합(Union) 연산 수행
        }
    }
    
    for(int i=0; i<M; i++) {
        int place = 0;
        cin>>place;
        plan.push_back(place);
    }
    
    for(int i=0; i<M-1; i++) {
        if(findParent(plan[i] != findParent(plan[i+1]))) return "NO\n";
    }
    return "YES\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solution()<<"\n";
    return 0;
}

/*
 5 4
 0 1 0 1 1
 1 0 1 1 0
 0 1 0 0 0
 1 1 0 0 0
 1 0 0 0 0
 2 3 4 3
 */
