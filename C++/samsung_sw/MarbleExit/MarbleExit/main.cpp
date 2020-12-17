//
//  main.cpp
//  MarbleExit
//
//  Created by 조윤영 on 15/10/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
#define MAX_SIZE 11
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


using namespace std;

/*방향 설정*/
typedef  struct{
    int y;
    int x;
}Dir;
Dir moveDir [4]= {{-1,0},{1,0},{0,-1},{0,1}};

typedef pair<int,int> Point;

struct Ball {
    int depth;
    Point red;
    Point blue;
};

char room[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
int N,M;
inline void doMove(Point &ball, int dir) {
    while(true) {
        ball.first +=moveDir[dir].y;
        ball.second +=moveDir[dir].x;
        
        char cell = room[ball.first][ball.second];
        if(cell == 'O') {
            break;
        }
        else if(cell == '#') {
            ball.first -=moveDir[dir].y;
            ball.second -=moveDir[dir].x;
            break;
        }
    }
}
int main() {
    cin>> N >> M;
    Point red,blue;
    Point hole;
    
    for(int n=1; n<=N; n++) {
        for(int m=1; m<=M; m++) {
            cin >> room[n][m];
            switch(room[n][m]) {
                case 'O':
                    hole = {n,m};
                    break;
                case 'R':
                    red = {n,m};
                    break;
                case 'B':
                    blue = {n,m};
                    break;
            }
        }
    }
    
    int depth = -1;
    queue<Ball> q;
    q.push(Ball{0, red,blue});
    
    while(!q.empty()) {
        Ball ball = q.front();
        q.pop();
        
        if(ball.depth >10) break;
        
        if(ball.red == hole) {
            depth = ball.depth;
            break;
        }
        
        for(int i=0; i<4; i++) {
            Point cRed = ball.red, cBlue = ball.blue;
            doMove(cRed, i);
            doMove(cBlue, i);
            
            if(cBlue == hole) continue;
            
            if(cRed == cBlue) {
                if (i == UP) {
                    // 파란색 공이 더 아래에 있었을 경우
                    if (ball.red.first < ball.blue.first) {
                        cBlue.first++;
                    }
                    else {
                        cRed.first++;
                    }
                }
                // 아래
                else if (i == DOWN) {
                    // 파란색 공이 더 아래에 있었을 경우
                    if (ball.red.first < ball.blue.first) {
                        cRed.first--;
                    }
                    else {
                        cBlue.first--;
                    }
                    
                }
                // 좌
                else if (i == LEFT) {
                    // 파란색 공이 더 오른쪽에 있었을 경우
                    if (ball.red.second < ball.blue.second) {
                        cBlue.second++;
                    }
                    else {
                        cRed.second++;
                    }
                }
                // 우
                else {
                    // 파란색 공이 더 오른쪽에 있었을 경우
                    if (ball.red.second < ball.blue.second) {
                        cRed.second--;
                    }
                    else {
                        cBlue.second--;
                    }
                }
            }
            
            if (!visited[cRed.first][cRed.second][cBlue.first][cBlue.second]) {
                q.push({ ball.depth + 1, cRed, cBlue });
                visited[cRed.first][cRed.second][cBlue.first][cBlue.second] = true;
            }
            
        }
    }
    cout << depth << endl;
}

/***내가 풀었는데 망함***/
//int cnt = 0; int N,M;
//char room[MAX_SIZE][MAX_SIZE];
//int RedX,RedY,BlueX,BlueY,ExitX,ExitY;
//int BlockX= -1;
//int BlockY = -1;
//char r;
//queue<pair<int,int>>tracks;
//
//
//void findExit(int N, int M) {
//
//    int nextRX, nextRY,nextBX,nextBY;
//    int prevX = -1; int prevY=-1;
//
//    /***********여기이상해************/
//    //빨간색 공을 기울일 수 있는 공간 탐색
//    while(room[RedY][RedX] != room[ExitY][ExitX]) {
//        int k=0;
//        for( k=0; k<4; k++) {
//
//            tracks.push({moveDir[k].y,moveDir[k].x});
//
//            nextRY = RedY+moveDir[k].y;
//            nextRX = RedX+moveDir[k].x;
//
//            nextBY = BlueY+moveDir[k].y;
//            nextBX = BlueX+moveDir[k].x;
//
//            //이동하면 안되는 공간
//            if(nextRX == RedX+BlockX && nextRY == RedY+BlockY) {
//                continue;//다른방향 알아보아라~
//            }
//
//            //장애물이 없을 경우 파란구슬도 함께 이동.
//            if(0<=nextBY&&nextBY<=N&&0<=nextBX&&nextBX<=M
//               &&room[nextBY][nextBX]!='#'&&room[nextBY][nextBX]!=room[nextRY][nextRX]
//               ){
//                BlueY = nextBY;
//                BlueX = nextBX;
//            }
//
//            //파란구슬이 빠질 경우 다시 시작
//            if(BlueX==ExitX&& BlueY == ExitY) {
//                RedX-=tracks.front().second;
//                RedY-=tracks.front().first;
//                BlueX-=tracks.front().second;
//                BlueY-=tracks.front().first;
//
//                BlockX =tracks.front().second;
//                BlockY = tracks.front().first;
//
//                tracks.pop();
//                break;
//            }
//
//
//            //빨간구슬 이동.
//            if(0<=nextRY&& nextRY <=N && 0<=nextRX && nextRX<=M
//               &&(nextRY!=prevY || nextRX !=prevX)
//               && room[nextRY][nextRX] !='#'&&room[nextRY][nextRX] !='B'){
//
//                cout<<"들어오기는 하는데?"<<endl;
//                prevY = RedY;
//                prevX = RedX;
//
//                RedY = nextRY;
//                RedX = nextRX;
//
//                cnt++;
//                break;
//            }
//
//            //빨간 구슬이 더 나아갈 방향이 없거나,
//            if(k==3&&prevX == RedX && prevY == RedY){
//                cout<<"확인";
//                RedX-=tracks.front().second;
//                RedY-=tracks.front().first;
//                BlueX-=tracks.front().second;
//                BlueY-=tracks.front().first;
//
//                BlockX =tracks.front().first;
//                BlockY = tracks.front().second;
//
//                tracks.pop();
//                break;
//            }
//
//        }
//
//    }
//}
//
//int main(int argc, const char * argv[]) {
//
//    //입출력의 최적화
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> N >> M; //행, 열 입력하기
//
//    //빨간 구슬, 파란 구슬, 탈출구 위치를 찾아 저장한다.
//    for(int i=0; i<N; i++) {
//        for(int j=0; j<M; j++) {
//            cin>> room[i][j];//해당 칸의 값 입력하기
//
//            r = room[i][j];
//
//            switch(r) {
//                case 'B':
//                    BlueY = i;
//                    BlueX = j;
//                    break;
//                case 'R':
//                    RedY = i;
//                    RedX = j;
//                    break;
//                case 'O':
//                    ExitY = i;
//                    ExitX = j;
//                    break;
//            }
//
//        }
//
//    }
//
//    findExit(N,M);
//
//
//    cout<<cnt<<"\n";
//    return 0;
//}
