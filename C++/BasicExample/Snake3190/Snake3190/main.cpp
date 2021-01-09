//
//  main.cpp
//  Snake3190
//
//  Created by 조윤영 on 2021/01/09.
//

#define MAX_SIZE 101
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N = 0;
int K = 0;
int L = 0;
struct Pos {
    int y;
    int x;
    
    Pos(int _y, int _x) {
        y = _y;
        x = _x;
    };
};
Pos moveDir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //상 우 하 좌
struct Direction {
    int time;
    char dir;
    Direction(int _time, int _dir) {
        time = _time;
        dir = _dir;
    };
};
queue<Direction> direction_list;
int board[MAX_SIZE][MAX_SIZE];
void input() {
    cin>> N;
    cin>>K;
    int y, x = 0;
    for(int i=0; i<K; i++) {
        cin>> y >> x;
        board[y-1][x-1] = 3;
    }

    cin>> L;
    int time;
    char dir;
    for(int i=0; i<L; i++) {
        cin >> time >> dir;
        direction_list.push(Direction(time, dir));
    }
}

bool isAvailable(int y, int x) {
    if(0<=y && y<N && 0<=x && x <N && board[y][x] != 1) return true;
    
    return false;
}

int solution() {
    int time = 0;
    int currentY = 0;
    int currentX = 0;
    int currentDir = 1;
    board[currentY][currentX] = 1;
    queue<Pos> q;
    q.push(Pos(currentY, currentX));
    while(true) {
        time++;
        int nextY = currentY + moveDir[currentDir].y;
        int nextX = currentX + moveDir[currentDir].x;

        if(isAvailable(nextY, nextX)) {
            currentY = nextY;
            currentX = nextX;
            
            //사과가 없다면
            if(board[currentY][currentX] != 3) {
                board[q.front().y][q.front().x] = 0;
                q.pop();
            }
            
            board[currentY][currentX] = 1;
            q.push(Pos(currentY, currentX));
            
            if(time == direction_list.front().time) {
                //방향전환 시간이 되었다면
                if(direction_list.front().dir == 'D') currentDir = (currentDir+1) % 4;
                else currentDir = (currentDir + 4 - 1) % 4;
                
                direction_list.pop();
            }
        } else return time;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution();
    return 0;
}

