//
//  main.cpp
//  PlanetTunnel
//
//  Created by 조윤영 on 2020/09/09.
//  Copyright © 2020 조윤영. All rights reserved.
//
//최소 신장 트리 - 크루스칼

#include <iostream>
#include <vector>
#define MAX_SIZE 100000
using namespace std;

int N = 0;
int parent[MAX_SIZE];
struct Planet {
    int x;
    int y;
    int z;
    
    Planet(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    };
};

vector<pair<int,pair<int,int>>> edges;
vector<pair<int,int>> x;
vector<pair<int,int>> y;
vector<pair<int,int>> z;

void input() {
    cin>> N;
    for(int i=1; i<=N; i++) {
        int a,b,c = 0;
        cin>> a >>b >>c;
        x.push_back({a,i});
        y.push_back({b,i});
        z.push_back({c,i});
    }
}

int findParent(int x) {
    if(x == parent[x]) return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int solution() {
    int answer = 0;
    for(int i=1; i<=N; i++) parent[i] = i;
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    
    //인접합 노드들로부터 간선 정보를 추출하여 처리
    for(int i=0; i<N-1; i++) {
        edges.push_back({x[i+1].first-x[i].first, {x[i].second, x[i+1].second}});
        edges.push_back({y[i+1].first - y[i].first, {y[i].second, y[i+1].second}});
        edges.push_back({z[i+1].first - z[i].first, {z[i].second, z[i+1].second}});
    }
    sort(edges.begin(), edges.end()); //간선을 오름차순으로 정렬
    
    for(int i=0; i<edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
        //사이클이 발생하지 않는 경우에만 집합에 포함
        if(findParent(a) != findParent(b)) {
            unionParent(a,b);
            answer += cost;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    input();
    cout<<solution()<<"\n";
    return 0;
}

/*
 5
 11 -15 -15
 14 -5 -15
 -1 -1 -5
 10 -4 -1
 19 -4 19
 */
