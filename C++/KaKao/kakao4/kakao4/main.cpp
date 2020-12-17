//
//  main.cpp
//  kakao4
//
//  Created by 조윤영 on 09/05/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int N;

//우 좌 하 상
struct Dir {
    int y;
    int x;
};

Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

vector<vector<set<pair<int, int>>>> visited;
int moves{ 0 };

vector<int> answers;

int limit = -1;
bool checked = false;

int solution(vector<vector<int>> board) { //0빈칸 1벽
   N = board.size();
   visited.resize(N, vector<set<pair<int, int>>>(N));

   vector<pair<int, int>> tmp;
   tmp.push_back(make_pair(0, 0));

   visited[0][0].insert(make_pair(0, 0));
   visited[0][0].insert(make_pair(1, 0));
   visited[0][0].insert(make_pair(2, 0));
   visited[0][0].insert(make_pair(3, 0));


   //진행방향, 코너 수를 저장하며 bfs
   while (true) {
      limit--;
      if (limit == 0)break;
      moves++;
      vector<pair<int, int>> next_tmp;
      //cout << limit << "\n";
      for (auto a : tmp) {
         
         for (int d{ 0 }; d < 4; d++) {
            int x = moveDir[d].x + a.first;
            int y = moveDir[d].y + a.second;
            
            if (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0) {
               
               //도착
               if (x == N - 1 && y == N - 1) {

                  int answer = moves * 100; //직선도로 비용

                  //코너도로 비용
                  vector<int> cornerCost;
                  for (auto pairs : visited[a.first][a.second]) {
                     if (pairs.first == d) cornerCost.push_back(pairs.second);
                     else cornerCost.push_back(pairs.second + 1);
                  }

                  sort(cornerCost.begin(), cornerCost.end());
                  answer += 500 * cornerCost.front();
                  answers.push_back(answer);

                  if (checked == false) {
                     checked = true;
                     limit = 10;
                  }
                  
               }

               for (auto pairs : visited[a.first][a.second]) {

                  if (pairs.first == d) { //진행방향이 같을 경우
                     if (visited[x][y].count(make_pair(d, pairs.second)) == 0) {
                        visited[x][y].insert(make_pair(d, pairs.second));
                        next_tmp.push_back(make_pair(x, y));
                     }
                  }
                  else { //진행 방향이 다를 경우
                     if (visited[x][y].count(make_pair(d, pairs.second+1)) == 0) {
                        visited[x][y].insert(make_pair(d, pairs.second+1));
                        next_tmp.push_back(make_pair(x, y));
                     }
                  }
               }
            }
         }
      }
      tmp = next_tmp;

   }

   sort(answers.begin(), answers.end());
   return answers.front();
}
