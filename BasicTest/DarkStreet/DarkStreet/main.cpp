//
//  main.cpp
//  DarkStreet
//
//  Created by 조윤영 on 2020/09/09.
//  Copyright © 2020 조윤영. All rights reserved.
//
//어두운 길 - 최소 신장트리 - 크루스칼 알고리즘

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_SIZE 200000
using namespace std;

struct Edge {
    int cost;
    int a;
    int b;
    Edge(int _cost, int _a, int _b) {
        cost = _cost;
        a = _a;
        b = _b;
    };
};

bool compare(Edge &a, Edge &b) {
    if(a.cost == b.cost) return a.a<b.a;
    return a.cost < b.cost;
    
}

vector<Edge> edges;

int N,M = 0;
int parent[MAX_SIZE];
void input() {
    cin>> N>>M;
    for(int i=0; i<M; i++) {
        int X,Y,Z = 0;
        cin>>X>>Y>>Z;
        edges.push_back(Edge(Z,X,Y));
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
    if(a< b) parent[b] = a;
    else parent[a] = b;
}

int solution() {
    int total = 0;
    int result = 0;
    sort(edges.begin(), edges.end(), compare);
    
    for(int i=0; i<edges.size(); i++) {
        cout<<edges[i].cost<<endl;;
    }
    
    for(int i=1; i<=N; i++) parent[i] = i;
    
    for(int i=0; i<edges.size(); i++) {
        int cost = edges[i].cost;
        int a = edges[i].a;
        int b = edges[i].b;
        total += cost;
        if(findParent(a) != findParent(b)) {
            unionParent(a,b);
            result+= cost;
        }
    }
    
    return total - result;
}

int main(int argc, const char * argv[]) {
    input();
    cout<<solution()<<"\n";
    return 0;
}

/*
 7 11
 0 1 7
 0 3 5
 1 2 8
 1 3 9
 1 4 7
 2 4 5
 3 4 15
 3 5 6
 4 5 8
 4 6 9
 5 6 11
 */
