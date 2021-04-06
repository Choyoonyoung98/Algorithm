//
//  main.cpp
//  WizardSharkAndTornado20057
//
//  Created by 조윤영 on 2021/04/03.
//
#define MAX_SIZE 500
#include <iostream>
using namespace std;

int N;
int room[MAX_SIZE][MAX_SIZE];

struct Dir {
    int y;
    int x;
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

struct TornadoSpread {
    int y;
    int x;
    int percent;
    TornadoSpread(int _y, int _x, int _percent) {
        y = _y;
        x = _x;
        percent = _percent;
    };
};

Dir moveDir[4] = {{0,-1}, {1, 0}, {0, 1}, {-1, 0}};
TornadoSpread spreads[4][9] = {
    //왼쪽
    {{-1, 1, 1}, {1, 1, 1}, {1, 0, 7}, { -1, 0, 7}, {2, 0, 2}, { -2, 0, 2}, {1,-1, 10}, {-1, -1, 10}, {0, -2, 5}},
    //아래
    {{-1, -1, 1}, {-1, 1, 1}, {0, -1, 7}, {0, 1, 7}, {0, -2, 2}, {0, 2, 2}, {1, -1, 10}, {1, 1, 10}, {2, 0, 5}},
    //오른쪽
    {{-1, -1, 1}, {1, -1, 1}, {-1, 0, 7}, {1, 0, 7}, {-2, 0, 2}, {2, 0, 2}, {-1, 1, 10}, {1, 1, 10}, {0, 2, 5}},
    //위
    {{1, -1, 1}, {1, 1, 1}, {0, -1, 7}, {0, 1, 7}, {0, -2, 2}, {0, 2, 2}, {-1, -1, 10}, {-1, 1, 10}, {-2, 0, 5}}
};

int tornadoMap[MAX_SIZE][MAX_SIZE];
int startY, startX;
void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> room[i][j];
            if(room[i][j] != 0) {
                startY = i;
                startX = j;
            }
        }
    }
}

bool isInBoundary(int y, int x) {
    if(0<= y && y < N && 0<= x && x < N) return true;
    return false;
}

bool visited[MAX_SIZE][MAX_SIZE];
void initialTornadoMap() {
    int y = 0;
    int x = 0;
    int cnt = 1;
    int dir = 2;
    while(true) {
        tornadoMap[y][x] = cnt;
        visited[y][x] = true;
        int nextY = y + moveDir[dir].y;
        int nextX = x + moveDir[dir].x;
        if(isInBoundary(nextY, nextX) && !visited[nextY][nextX]) {
            y = nextY;
            x = nextX;
        } else {
            int rightDir = (dir + 4 - 1) % 4;
            nextY = y + moveDir[rightDir].y;
            nextX = x + moveDir[rightDir].x;
            if(isInBoundary(nextY, nextX) && !visited[nextY][nextX]) {
                dir = rightDir;
                y = nextY;
                x = nextX;
            } else return;
        }
        cnt++;
    }
}

int solution() {
    int answer = 0;
    int tornadoY = N/2;
    int tornadoX = N/2;
    int tornadoIdx = N*N;
    int tornadoDir = 0;
    initialTornadoMap();
    
    while(true) {
        if(tornadoY == 0 && tornadoX == 0) return answer;
        //토네이도 이동
        int nextY = tornadoY + moveDir[tornadoDir].y;
        int nextX = tornadoX + moveDir[tornadoDir].x;

        if(tornadoMap[nextY][nextX] != tornadoIdx - 1) {
            int leftDir = (tornadoDir + 1) % 4;
            nextY = tornadoY + moveDir[leftDir].y;
            nextX = tornadoX + moveDir[leftDir].x;
            tornadoDir = leftDir;
        }
        tornadoIdx--;
        tornadoY = nextY;
        tornadoX = nextX;
        
        //토네이도 모래 전파
        int dust = room[nextY][nextX];
        room[nextY][nextX] = 0;
        int leftDust = dust;
        if(dust == 0) continue;
        for(int i=0; i<9; i++) {
            int spreadY = nextY + spreads[tornadoDir][i].y;
            int spreadX = nextX + spreads[tornadoDir][i].x;
            
            int percent = spreads[tornadoDir][i].percent;
            
            int spreadDust = dust * percent / 100;
            leftDust -= spreadDust;
            if(!isInBoundary(spreadY, spreadX)) {
                answer += spreadDust;
                continue;
            }
            room[spreadY][spreadX] += spreadDust;
            
        }
        int alphaY = nextY + moveDir[tornadoDir].y;
        int alphaX = nextX + moveDir[tornadoDir].x;
        if(isInBoundary(alphaY, alphaX)) room[alphaY][alphaX] += leftDust;
        else answer += leftDust;

    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    input();
    cout<<solution()<<"\n";
    return 0;
}
