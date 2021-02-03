//
//  main.cpp
//  TaxiPayment72413
//
//  Created by 조윤영 on 2021/02/03.
//

#define MAX_SIZE 201
#define INF 1e9
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//최소비용
//dijkstra && plyoid
//queue
//가장 cost가 적은 길부터 우선적으로 탐색하되, 이미 더 적은 cost를 이용해 그 길을 지나간 적 있으면 무시
int costs[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int d[MAX_SIZE];
bool visited2[MAX_SIZE];
int d2[MAX_SIZE];
vector<vector<int>> routes;
int calculateDistance(int s, int e) {
    int result = INF;
    memcpy(visited2, visited, sizeof(visited));
    memcpy(d2, d, sizeof(d));
    
    if(s == e) return 0;
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
    pq2.push({0, s});
    while(!pq2.empty()) {
        int index = pq2.top().second;
        int cost = pq2.top().first;
        pq2.pop();
        if(cost > d2[index]) continue;
        if(index == e) result = min(result, cost);
        
        for(int i=0; i<routes[index].size(); i++) {
            int nextIndex = routes[index][i];
            if(!visited2[nextIndex]) {
                int nextCost = cost + costs[index][nextIndex];
                if(nextCost < d2[nextIndex]) {
                    d2[nextIndex] = nextCost;
                    pq2.push({nextCost, nextIndex});
                }
            }
        }
    }
    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    routes.assign(n+1, {});
    //노드별 visited check
    //S에서 출밣해서 각 노드들에 진입하는 껄 dijkstra로 진입
    //각 노드에 도착할 때마다 해당 지점으로부터 A까지의 최단거리 && B까지의 최단거리 합산해서 answer = min(answer, costSum) 해보기
    for(vector<int> fare: fares) {
        int a = fare[0];
        int b = fare[1];
        int cost = fare[2];
        routes[a].push_back(b);
        routes[b].push_back(a);
        costs[a][b] = cost;
        costs[b][a] = cost;
    }
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    fill(visited, visited + MAX_SIZE, false); //무조건 확실하게 초기화하고 넘어가기
    fill(d, d+ MAX_SIZE, INF);
    d[s] = 0;
    q.push({0, s});
    
    while(!q.empty()) {
        int index = q.top().second;
        int cost = q.top().first;
        q.pop();
        visited[index] = true;
        if(cost > d[index]) { continue; }
    
        answer = min(answer, cost + calculateDistance(index, a) + calculateDistance(index, b));
        
        for(int i=0; i<routes[index].size(); i++) {
            int nextNode = routes[index][i];
            if(!visited[nextNode]) {
                int nextCost = cost + costs[index][nextNode];
                if(nextCost < d[nextNode]) {
                    d[nextNode] = nextCost;
                    q.push({nextCost, nextNode});
                }
            }
        }
        
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 6;
    int s = 4;
    int a = 5;
    int b = 6;
    vector<vector<int>> fares = {{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}};
    
    cout<<solution(n, s, a, b, fares);
    return 0;
}
