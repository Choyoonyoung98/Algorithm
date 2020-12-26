//
//  main.cpp
//  CorrectRanking
//
//  Created by 조윤영 on 2020/09/02.
//  Copyright © 2020 조윤영. All rights reserved.
//
//정확한 순위
//플로이드워셜 알고리즘 추천

#include <iostream>
#include <vector>
#define MAX_SIZE 501
#define INF 1e9
using namespace std;
int N = 0;
int M = 0;
vector<vector<int>> graph;
void input() {
    cin>> N>> M;
    graph.assign(N+1, vector<int>(N+1, INF));
    for(int i=0; i<M; i++) {
        int A, B = 0;
        cin>> A >> B;
        graph[A][B] = 1;
    }
}

int solution() {
    int answer = 0;
    for(int k=1; k<=N; k++) {
        for (int a=1; a<=N; a++) {
            for(int b=1; b<=N; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    
    for(int i=1; i<=N; i++) {
        int cnt = 0;
        for(int j=1; j<=N; j++) {
            if((graph[i][j] != INF ||  graph[j][i] != INF) || i == j) cnt++;
        }
        if(cnt == N) answer++;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}

/*
 6 6
 1 5
 3 4
 4 2
 4 6
 5 2
 5 4
 */

//DFS
/*
 int N = 0;
 int M = 0;
 vector<int> rank_list;
 vector<vector<int>> compare_score;
 vector<bool> visited;
 void input()  {
     cin>>N>>M;
     rank_list.assign(N+1, 0);
     compare_score.assign(N+1, {});
     visited.assign(N, false);
     for(int i=0; i<M; i++) {
         int A, B =  0;
         cin>> A>>B;
         compare_score[A].push_back(B);// A의 성적이 B 학생보다 낮다!
     }
 }

 void dfs(int index) {
     rank_list[index]++;
     for(int i=0; i<compare_score[index].size(); i++) {
         if(!visited[i]) {
             visited[i] = true;
             dfs(i);
             visited[i] = false;
         }
     }
 }

 int solution() {
     int answer = 0;
     for(int i=1; i<=N; i++) {
         visited[i] = true;
         dfs(i);
         visited[i] = false;
     }

     vector<int> cnt(N+1, 0);
     for(int i=1; i<rank_list.size(); i++) cnt[rank_list[i]]++;
     for(int i=0;  i<cnt.size(); i++) if(cnt[i] == 1) answer++;
     
     return answer;
 }
 */
