//
//  main.cpp
//  ChickenDelivery15686
//
//  Created by 조윤영 on 2021/01/09.
//
#define INF 1e9
#define MAX_SIZE 51
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int N, M = 0;
int map[MAX_SIZE][MAX_SIZE];
int visited[14];
struct Pos {
    int y;
    int x;
    Pos(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

struct CostInfo {
    int cost;
    int cnt;
    int index;
    CostInfo(int _cost, int _cnt, int _index) {
        cost = _cost;
        cnt = _cnt;
        index = _index;
    };
};
vector<Pos> houses;
vector<Pos> chickens;
vector<Pos> selected_chickens;
int answer = INF;

void input() {
    cin>> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>> map[i][j];
            if(map[i][j] == 1) houses.push_back(Pos(i, j));
            else if(map[i][j] == 2) chickens.push_back(Pos(i, j));
        }
    }
}

int calculateCost() {
    int result = 0;
    
    for(int i=0; i<houses.size(); i++) {
        int minCost = INF;
        for(int j=0; j<selected_chickens.size(); j++) {
            int cost = abs((houses[i].y - selected_chickens[j].y)) + abs((houses[i].x - selected_chickens[j].x));
            minCost = min(minCost, cost);
        }
        
        result += minCost;
    }
    return result;
}

//조합 문제
void dfs(int index, int cnt) {
    if(cnt == M) {
        answer  = min(answer, calculateCost());
        return;
    }
    
    for(int i=index; i<chickens.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        selected_chickens.push_back(chickens[i]);
        dfs(i+1, cnt+1);
        visited[i] = false;
        selected_chickens.pop_back();
    }
}
void solution() {
    dfs(0,0);
    cout<<answer<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}
