//
//  main.cpp
//  FinalRank
//
//  Created by 조윤영 on 2020/09/09.
//  Copyright © 2020 조윤영. All rights reserved.
//최종 순위
//https://www.acmicpc.net/problem/3665
//순위, 선행 -> 위상 정렬

#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 501
using namespace std;
void solution();

int T,N, M = 0;
int inDegree[MAX_SIZE];
bool graph[MAX_SIZE][MAX_SIZE];

void input() {
    cin>> T;
    for(int t=0; t<T; t++) {
        //자료구조 데이터 초기화
        //fill(해당 변수, 변수+할당할 크기, 할당할 값)
        fill(inDegree, inDegree+MAX_SIZE, 0);
        for(int i=0; i<MAX_SIZE; i++) fill(graph[i], graph[i]+MAX_SIZE, false);
        
        cin>> N;
        
        //작년 순위 정보 입력
        vector<int> rank;
        rank.assign(N+1, 0);
        for(int i=1; i<=N; i++) {
            cin>>rank[i];
        }
        
        //위에서 받은 정보를 토대로
        //방향 그래프의 간선 정보 초기화
        for(int i=1; i<=N; i++) {
            int higherRankTeam = rank[i];
            for(int j=i+1; j<=N; j++) {
                int lowerRankTeam = rank[j];
                graph[higherRankTeam][lowerRankTeam] = true;
                inDegree[lowerRankTeam]++;//더 낮은 순위의 팀에 대해서 진입차수 올려주기
            }
        }
        
        cin>> M;
        int a,b = 0;
        for(int i=0; i<M; i++) {
            cin>> a>>b;
            if(graph[a][b]) { //작년의 순위에서 a가 b보다 순위가 더 높았다면,
                //반대로 올해에는 b가 a보다 순위가 높은 것이므로
                graph[a][b] = false; //과거 기록을 초기화하고
                graph[b][a] = true; //새로운 순위 기록
                inDegree[a]++;
                inDegree[b]--;
            } else {//작년의 순위에서 b가 a보다 순위가 더 높았다면,
                //반대로 올해에는 a가 b보다 순위가 높은 것이므로
                graph[a][b] = true;
                graph[b][a] = false;
                inDegree[b]++;
                inDegree[a]--;
            }
        }
        solution();
        cout<<"\n";
    }
}

void solution() {
    //위상 정렬(Topology Sort) 시작
    vector<int> result;
    queue<int> q;
    
    //진입차수가 0인 노드에 대해 큐에 넣어주기
    for(int i=1; i<=N; i++) {
        if(inDegree[i] == 0) q.push(i);
    }
    
    bool certain = true; //위상 정렬 결과가 오직 하나인지의 여부
    bool cycle = false; //그래프 내 사이클이 존재하는지 여부
    for(int i=0; i<N; i++) {
        //큐가 비어있다면 사이클이 발생했다는 것을 의미
        if(q.empty()) {
            cycle = true;
            break;
        }
        //큐의 원소가 2개 이상이라면 가능한 정렬 결과가 여러개라는 의미
        if(q.size() >= 2) {
            certain = false;
            break;
        }
        
        int currentTeam = q.front();
        q.pop();
        result.push_back(currentTeam);
        for(int j=1; j<=N; j++) {
            if(graph[currentTeam][j]) {
                inDegree[j]--;
                if(inDegree[j] == 0) q.push(j);
            }
        }
    }
    
    //사이클이 발생하거나 위상 정렬 결과가 여러 개인 경우
    if(cycle || !certain) cout<<"IMPOSSIBLE";
    else {
        for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}

/*
 3
 5
 5 4 3 2 1
 2
 2 4
 3 4
 3
 2 3 1
 0
 4
 1 2 3 4
 3
 1 2
 3 4
 2 3
 */
