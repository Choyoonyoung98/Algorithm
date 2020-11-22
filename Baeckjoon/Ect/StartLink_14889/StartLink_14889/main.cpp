//
//  main.cpp
//  StartLink_14889
//
//  Created by 조윤영 on 08/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX_SIZE 21

using namespace std;

int N = 0;
int room[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int answer = 100;

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin>> N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>room[i][j];
        }
    }
    
}

void dfs(int player, int cnt) {
    
    if(cnt == N/2) {//절반의 팀원이 구해졌을 경우
        vector<int> team_start, team_link;
        
        //뽑은 사람을 start팀으로, 뽑히지 않은 사람을 link팀으로 집어넣는다.
        for(int i=0; i<N; i++) {
            if(visited[i]){
                team_start.push_back(i);
            }
            else {
                team_link.push_back(i);
            }
            
        }
        
        int sum_startTeam = 0;
        int sum_linkTeam = 0;
        
        for(int i=0; i<N/2; i++) {
            for(int j=i+1; j<N/2; j++) {
                int start_y = team_start[i];
                int start_x = team_start[j];
                int link_y = team_link[i];
                int link_x = team_link[j];
                
                sum_startTeam += room[start_y][start_x] + room[start_x][start_y];
                sum_linkTeam += room[link_y][link_x] + room[link_x][link_y];
                
            }
        }
        
        answer = min(answer, abs(sum_startTeam - sum_linkTeam));
        
    }
    
    for(int i=player+1; i<N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, cnt+1);
            visited[i] = false;
        }
    }
}

void solution() {
    dfs(0,0);
    cout<<answer<<"\n";
}

int main(int argc, const char * argv[]) {
    
    input();
    solution();
    
    return 0;
}
