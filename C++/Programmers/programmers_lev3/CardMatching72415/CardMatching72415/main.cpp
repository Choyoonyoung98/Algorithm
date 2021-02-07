//
//  main.cpp
//  CardMatching72415
//
//  Created by 조윤영 on 2021/02/06.
//
//최단거리 + 백트래킹
//1) 보드판의 카드를 뒤집는 모든 순서를 방문하는 백트래킹 구현
//2) 보드판의 칸을 이동할 때 필요한 최소 키보드 입력 횟수 계산

#define INF 1e9
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
bool isAvailable(int y, int x);
struct Dir {
    int y;
    int x;
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};
struct Point {
    int y;
    int x;
    int cost;
    
    Point(int _y, int _x, int _cost) {
        y = _y;
        x = _x;
        cost = _cost;
    };
    Point(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

//[꿀팁]: struct 데이터를 우선순위 큐 비교 연산을 가능하게 하려면
bool operator < (Point a, Point b) { return a.cost > b.cost; }

Dir moveDir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//매칭할 카드가 남아있는지 확인하는 함수
bool isFinished(vector<vector<int>>& boards) { //&: 해당 값에 접근할 뿐 수정하지 않을 때 참조할 목적으로 사용하는듯
    for(vector<int> board: boards)
        for(int b: board) if( b != 0) return false;
    
    return true;
}

//Dijkstra
//어떤 카드에서 어떤 다른 카드까지 도달하기 위한 최단거리를 도춣해내기 위한 함수
//board[y1][x1] -> board[y2][x2]
int getDistance(vector<vector<int>>& board, int y1, int x1, int y2, int x2) {
    priority_queue<Point> pq;
    pq.push(Point(y1, x1, 0));
    int dist[4][4];
    for(int i=0; i<4; i++) fill(dist[i], dist[i] + 4, INF);
    dist[y1][x1] = 0;
    
    while(!pq.empty()) {
        int currentCost = pq.top().cost;
        int currentY = pq.top().y;
        int currentX = pq.top().x;
        pq.pop();

        if(dist[currentY][currentX] < currentCost ) continue;
        if(currentY == y2 && currentX == x2) return currentCost; // (y2, x2)에 도달했다면,
        
        for(int i=0; i<4; i++) {
            int cnt = 0;
            int nextY = currentY;
            int nextX = currentX;
            while(isAvailable(nextY + moveDir[i].y, nextX + moveDir[i].x)) {
                cnt ++;
                nextY += moveDir[i].y;
                nextX += moveDir[i].x;
                
                if(board[nextY][nextX] != 0) break; //카드가 존재한다면
                
                //일반 방향키 이동
                if(dist[nextY][nextX] > currentCost + cnt) {
                    dist[nextY][nextX] = currentCost + cnt;
                    pq.push(Point(nextY, nextX, currentCost+cnt));
                }
            }
            
            //Ctrl+방향키
            if(dist[nextY][nextX] > currentCost + 1) {
                dist[nextY][nextX] = currentCost + 1;
                pq.push(Point(nextY, nextX, currentCost+1));
            }
        }
    }
    return 0;
}

//전체 room의 방문상태에 대해 단순 visited check에서 더 나아가 방문한 칸 정보에 대해 지속적으로 가지고 있어야 한다면 DFS 사용이 옳다!
//DFS: board[y][x]의 위치로부터 모든 종류의 카드를 뒤집어보기
int solve(vector<vector<int>> board, int y, int x) {
    int result = INF;
    if(isFinished(board)) return 0; //매칭이 끝났을 경우
    
    for(int k=1; k <= 6; k++) {
        vector<Point> point;
        //4X4 보드판 탐색
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(board[i][j] == k) point.push_back(Point(i, j)); //카드가 존재하면 추가.
            }
        }

        if(point.empty()) continue; // 남아있는 카드가 없을 경우
        
        //solve함수가 한 번 수행될 때마다 임의으ㅢ 카드 한 쌍을 뒤집고 두 번째로 뒤집은 카드의 좌표엥서 다시 solve 함수 호출
        //카드 쌍을 뒤집을 때 둘 중 어떤 카드를 나중에 뒤집냐에 따라 다음 solve 함수의 매개변수가 달라지기 때문에 두 가지 경우를 모두 탐색해주어야 한다
        
        //앞카드를 먼저 뒤집을 경우
        int card1 = getDistance(board, y, x, point[0].y, point[0].x) + getDistance(board, point[0].y, point[0].x, point[1].y, point[1].x) + 2; //Enter 2번
        //뒷카드를 먼저 뒤집을 경우
        int card2 = getDistance(board, y, x, point[1].y, point[1].x) + getDistance(board, point[1].y, point[1].x, point[0].y, point[0].x) + 2;
        
        //DFS에 들어가기 전에 이미 방문했음을 체크해준다
        board[point[0].y][point[0].x] = 0;
        board[point[1].y][point[1].x] = 0;
        
        result = min(result, min(card1 + solve(board, point[1].y, point[1].x), card2 + solve(board, point[0].y, point[0].x)));
        
        //DFS에 들어간 후에 미방문으로 바꾸어준다.
        board[point[0].y][point[0].x] = k;
        board[point[1].y][point[1].x] = k;
    }
    
    return result;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = solve(board, r, c); //출발지점을 넘김으로써 DFS 시작
    return answer;
}

bool isAvailable(int y, int x) {
    return 0<= y && y<4 && 0<= x && x < 4;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> board = {{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}};
    int r = 1;
    int c = 0;
    cout<<"["<<solution(board, r, c)<<"]"<<endl;
    return 0;
}
