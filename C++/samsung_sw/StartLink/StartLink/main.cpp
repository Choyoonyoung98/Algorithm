//
//  main.cpp
//  StartLink
//
//  Created by 조윤영 on 17/10/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_SIZE 20

using namespace std;
int N;

int room[MAX_SIZE][MAX_SIZE];
bool is_used[MAX_SIZE];
int gap =100;

void DFS(int curr_player, int cnt) {
    
    if(cnt == N/2) {
        vector<int> team_link, team_start;
        
        for(int i=0; i<N; i++) {
            if(is_used[i]) team_start.push_back(i);
            else team_link.push_back(i);
        }
        
        int stat_start = 0, stat_link = 0;
        for(int i=0; i<team_start.size(); i++) {
            for(int j=i+1; j<team_start.size(); j++) {
                int start_x = team_start[i], start_y = team_start[j];
                int link_x = team_link[i], link_y = team_link[j];
                stat_start +=room[start_x][start_y] + room[start_y][start_x];
                stat_link +=room[link_x][link_y ]+ room[link_y][link_x];
            }
        }
        gap = min(gap, abs(stat_start - stat_link));
        return;

    }

    //재귀호출에 대한 이해 잘 해라
    for(int i=curr_player+1; i<N; i++) {
        if(is_used[i] == false) {
            is_used[i] = true;
            DFS(i, cnt+1); //1,1
            //백트래킹
            is_used[i] = false;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> room[i][j];

    DFS(0,0);
    
    cout<<gap;
    
    
    return 0;
}
