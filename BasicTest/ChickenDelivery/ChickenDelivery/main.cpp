//
//  main.cpp
//  ChickenDelivery
//
//  Created by 조윤영 on 2020/08/18.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/15686
//치킨 배달(*)

#include <iostream>
#include <cmath> //abs
#include <vector>
#include <algorithm>
#define MAX_SIZE 51

using namespace std;

int N = 0;
int M = 0;
int room[MAX_SIZE][MAX_SIZE];
struct Position {
    int y;
    int x;
    Position(int _y, int _x) {
        y = _y;
        x = _x;
    };
};
vector<Position> chicken_store;
vector<Position> houses;
vector<Position> selected_store;
int answer = 99999999; //(*)

void input() {
    cin>> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>> room[i][j];
            if( room[i][j] == 1) houses.push_back(Position(i,j));
            else if (room[i][j] == 2) chicken_store.push_back(Position(i,j));
        }
    }
}

void calculateChickenDistance() {
    int distanceSum =  0;
    for(int i=0; i<houses.size();  i++) {
        int  houseY = houses[i].y;
        int  houseX  = houses[i].x;
        int minDistanceChicken = 99999999;
        for(int j=0; j<selected_store.size(); j++) {
            int chickenY = selected_store[j].y;
            int chickenX = selected_store[j].x;
            
            int distance =  abs(houseY - chickenY) + abs(houseX - chickenX);
            minDistanceChicken =  min(minDistanceChicken, distance);
        }
        distanceSum+=  minDistanceChicken;
    }
    answer = min(answer, distanceSum);
}

void dfs(int index, int cnt) {
    if(cnt == M) {
        calculateChickenDistance();
        return;
    }
    for(int i=index+1; i<chicken_store.size();  i++) {
        selected_store.push_back(chicken_store[i]);
        dfs(i, cnt+1);
        selected_store.pop_back();
    }
}

int solution() {
    dfs(-1, 0);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    
    return 0;
}


/*1. 각각의 치킨 가게에서 집들로부터 거리의 총합을 구한 뒤
  2. 오름차순으로 정렬한 뒤,
  3. 주어진 M개만큼 치킨집을 선점
  4. 각각의 집으로부터 주어진 M개의 치킨 가게 중 가장 가까운 치킨 집의 거리를 구함.
  5. 최종적으로 각각의 집으로부터 가장 가까운 치킨 거리를 더함.
 
 => 아래 풀이는 아래와 같은 상황에서 오답을 낸다.
 5 2
 0 0 0 0 1
 0 0 0 0 1
 0 0 0 2 1
 1 0 2 0 1
 2 1 0 0 1
 -> 정답 = 13 BUT 내 답안 = 15
 */
//struct Position {
//    int y;
//    int x;
//    Position(int _y, int _x) {
//        y = _y;
//        x = _x;
//    };
//};
//vector<Position> chicken_store;
//vector<Position> survive_chicken_store;
//vector<Position> houses;
//vector<pair<int,int>> chickenDistance;
//
//void input() {
//    cin>> N >> M;
//
//    for(int i=0; i<N; i++) {
//        for(int j=0; j<N; j++) {
//            cin>> room[i][j];
//            if( room[i][j] == 1) houses.push_back(Position(i,j));
//            else if (room[i][j] == 2) chicken_store.push_back(Position(i,j));
//        }
//    }
//}
//
//int solution() {
//    int answer = 0;
//
//    for(int i=0; i<chicken_store.size(); i++) chickenDistance.push_back({0, i});
//
//    for(int i=0; i<houses.size(); i++) {
//
//        int houseY = houses[i].y;
//        int houseX = houses[i].x;
//        for(int j=0; j<chicken_store.size(); j++) {
//            int chickenY = chicken_store[j].y;
//            int chickenX = chicken_store[j].x;
//            int distance = abs(houseY - chickenY ) + abs(houseX - chickenX);
//
//            chickenDistance[j]  = {chickenDistance[j].first + distance, chickenDistance[j].second };
//        }
//    }
//    sort(chickenDistance.begin(), chickenDistance.end());
//
//    for(int i=0; i<chickenDistance.size(); i++) cout<<chickenDistance[i].first<<","<<chickenDistance[i].second<<endl;
//
//    for(int i=0; i<M; i++) {
//        if(i+1 > chickenDistance.size()) break;
//        int surviveChickenStoreIndex = chickenDistance[i].second;
//        int chickenY = chicken_store[surviveChickenStoreIndex].y;
//        int chickenX = chicken_store[surviveChickenStoreIndex].x;
//
//        survive_chicken_store.push_back(Position(chickenY, chickenX));
//    }
//
//    for(int i=0; i<houses.size(); i++) {
//        int houseY = houses[i].y;
//        int houseX = houses[i].x;
//        int minDistance = 2*N;
//        for(int j=0; j<survive_chicken_store.size(); j++) {
//            int chickenY = survive_chicken_store[j].y;
//            int chickenX = survive_chicken_store[j].x;
//            int distance = abs(houseY - chickenY ) + abs(houseX - chickenX);
//            minDistance = min(minDistance, distance);
//        }
//        answer += minDistance;
//    }
//
//    return answer;
//}

