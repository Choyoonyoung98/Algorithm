//
//  main.cpp
//  FindASpecificDistanceCity
//
//  Created by 조윤영 on 2020/08/20.
//  Copyright © 2020 조윤영. All rights reserved.
//
//DFS VS BFS 선택할 때 시간복잡도 어떻게 계산하는지 알아보기
//https://www.acmicpc.net/problem/18352
#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 300001
#define MAX_SIZE2 10000001

using namespace std;

vector<int> distances;
vector<vector<int>> related_cities;
vector<int> answer;
int visited[MAX_SIZE];
int N, M, K, X = 0;
int A, B = 0;

void input() {
    cin>> N >> M >> K >> X;
    
    related_cities.assign(N+1, {});
    distances.assign(N+1, MAX_SIZE2);
    for(int i=0; i<M; i++) {
        cin>> A >> B;
        related_cities[A].push_back(B);
    }
}

//BFS
void solution() {
    queue<pair<int, int>> q; //index, distance
    q.push({X,0});
    while(!q.empty()) {
        int index = q.front().first;
        int dist = q.front().second;
        distances[index] = min(distances[index], dist);
        visited[index] =  true;
        q.pop();
        int relatedCitiesSize = related_cities[index].size();
        for(int  i=0; i<relatedCitiesSize;  i++)  {
            int toIndex = related_cities[index][i];
            if(!visited[toIndex]) q.push({toIndex, dist+1});
        }
    }
    
    bool hasAnswer = false;
    int distanceSize = distances.size();
    for(int i=0; i<distanceSize; i++) {
        if(distances[i] == K) {
            hasAnswer = true;
            cout<<i<<"\n";
        }
    }
    if(!hasAnswer) cout<<"-1"<<"\n";
}
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    input();
    solution();
    return 0;
}

//DFS
//void dfs(int index, int cnt) {
//
//    distances[index] = min(distances[index], cnt);
//    for(int i=0; i<related_cities[index].size(); i++) {
//        int toIndex = related_cities[index][i];
//        if(!visited[toIndex]) {
//            visited[toIndex] = true;
//            dfs(toIndex, cnt+1);
//            visited[toIndex] = false;
//        }
//    }
//}
//
//void solution() {
//    visited[X] = true;
//    distances[X] = 0;
//    for(int i=0; i<related_cities[X].size(); i++) {
//        int  toIndex = related_cities[X][i];
//        visited[toIndex] = true;
//        dfs(toIndex, 1);
//        visited[toIndex] = false;
//    }
//
//    bool hasAnswer = false;
//    for(int i=0; i<distances.size(); i++) {
//        if(distances[i] == K) {
//            hasAnswer = true;
//            cout<<i<<"\n";
//        }
//    }
//
//    if(!hasAnswer) cout<<"-1"<<"\n";
//}

//int main(int argc, const char * argv[]) {
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    input();
//    solution();
//    return 0;
//}
