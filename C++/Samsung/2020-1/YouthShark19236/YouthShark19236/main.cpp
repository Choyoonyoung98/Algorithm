//
//  main.cpp
//  YouthShark19236
//
//  Created by 조윤영 on 2021/03/26.
//
//4X4로 공간 고정
//물고기: 번호(1~16), 방향(상, 상좌, 좌, 하좌, 하, 하우, 우, 상우)
//상어의 출발점: 0,0
//번호가 작은 물고기부터 순서대로 이동 -> input 받을 때부터 물고기 번호에 맞게 물고기 정보를 담고 있어야겠다(위치 정보)

//상어가 물고기를 먹고
//물고기가 이동하고
//상어가 이동한다

//물고기는 한칸을 이동할 수 있는데, 빈칸, 다른 물고기 있는 칸으로 이동할 수 있고
//상어가 있거나 공간의 경계를 넘을 경우 이동할 수 없다
//방향이 이동할 수 있는 칸을 향할때까지 반시계방향으로 전환
//이동할 수 없으면 이동하지 않는다.
//물고기 있는 칸이라면, 서로의 위치를 바꾼다

//상어는 한 번에 여러 개의 칸을 이동할 수 있다(최대 3칸까지 이동할 수 있는 것)

//위 과정이 반복

//이게 queue로 구현이 가능한가? BFS인가 DFS인가? queue에 visited 배열을 가지고 다녀야하는 상황이므로 DFS가 더 바람직
//GO!
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
struct Dir {
    int y;
    int x;
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

struct Fish {
    int y;
    int x;
    bool isAlive;
    int dir;
    Fish(int _y, int _x, bool _isAlive, int _dir) {
        y = _y;
        x = _x;
        isAlive = _isAlive;
        dir = _dir;
    };
};

Dir moveDir[8] = {{-1, 0},{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}}; //반시계 방향으로 방향정렬
int room[4][4];
vector<Fish> fishes(17, Fish(0, 0, 0, true)); //물고기 번호 index에 물고기 위치를 담는다
int answer = 0;
void input() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            int a, b;
            cin>>a >> b;
            room[i][j] = a;
            fishes[a] = Fish(i, j, true, b-1);
        }
    }
}

//경계값 벗어나는지 확인하는 함수
bool isAvailable(int y, int x) {
    if(0 <= y && y < 4 && 0<= x && x< 4) return true;
    return false;
}

void DFS(int map[4][4], vector<Fish> fishes, int y, int x, int sum) {
    
    //인자에 있는 변수값을 그대로 사용하는 것은 위험한 방식이기 때문에
    //임시 변수값을 만들고 값을 담아준다
    /*******************************************************************************************/
    int cpy_map[4][4];
    memcpy(cpy_map, map, sizeof(cpy_map));
    vector<Fish> cpy_fishes;
    for(int i=0; i<fishes.size(); i++) cpy_fishes.push_back(fishes[i]);
    /*******************************************************************************************/
    
    /*1: 잡아먹자!*/
    int currentIdx = cpy_map[y][x];
    cpy_map[y][x] = 0;
    cpy_fishes[currentIdx].isAlive = false;
    int sharkDir = cpy_fishes[currentIdx].dir;
    
    sum += currentIdx;
    answer = max(answer, sum);

    /*2: 물고기의 이동*/
    for(int i=1; i<=16; i++) {
        Fish fish = cpy_fishes[i];
        if(!fish.isAlive) continue;

        for(int d=0; d<8; d++) { //나아갈 수 있는 방향이 나올 때까지 회전하면서 확인
            int nextDir = (fish.dir + d) % 8;
            int nextY = fish.y + moveDir[nextDir].y;
            int nextX = fish.x + moveDir[nextDir].x;
            if(isAvailable(nextY, nextX) && !(nextY == y && nextX == x)) {
                //이동할 수 있는 칸: 경계 범위 안이며, 상어가 없어야하며
                //다른 물고기가 존재하거나 빈칸인 경우 이동할 수 있다
                if(cpy_map[nextY][nextX] != 0) {//다른 물고기가 있다면?
                    //바꾸자
                    //상대 물고기 위치 갱신
                    int nextIdx = cpy_map[nextY][nextX];
                    Fish nextFish = cpy_fishes[nextIdx];
                    cpy_fishes[nextIdx] = Fish(fish.y, fish.x, true, nextFish.dir);
                    cpy_map[nextY][nextX] = i;
                    
                    //현재 위치에 다른 물고기를 정보를 넣어준다
                    cpy_fishes[i] = Fish(nextY, nextX, true, nextDir);
                    cpy_map[fish.y][fish.x] = nextIdx;
                } else { //빈칸이라면
                    cpy_map[fish.y][fish.x] = 0;
                    cpy_map[nextY][nextX] = i;
                    cpy_fishes[i] = Fish(nextY, nextX, true, nextDir);
                }
                break;
            }
        }
    }

    /*3: 상어 이동*/
    for(int cnt = 1; cnt <= 3; cnt++) {
        int nextY = y + moveDir[sharkDir].y * cnt;
        int nextX = x + moveDir[sharkDir].x * cnt;
        if(isAvailable(nextY, nextX)){
            if(cpy_map[nextY][nextX] != 0) {
                DFS(cpy_map, cpy_fishes, nextY, nextX, sum);
            }
        } else break;
    }
}

int main(int argc, const char * argv[]) {
    input();
    DFS(room, fishes, 0, 0, 0);
    cout<<answer<<endl;
    return 0;
}
