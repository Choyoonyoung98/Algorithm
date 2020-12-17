//
//  main.cpp
//  RollDice_14499
//
//  Created by 조윤영 on 2020/11/27.
//
//https://www.acmicpc.net/problem/14499
//때로는 규칙을 찾기보다는 무식한 방법이 정답일 때가 있다....
//주사위 굴리기

#define MAX_SIZE 21
#include <iostream>
#include <vector>
using namespace std;

int N, M,  Y, X, K = 0;
int map[MAX_SIZE][MAX_SIZE];
vector<int> instruction;
vector<int> dice(6, 0);

struct Dir {
    int row;
    int column;
};
Dir moveDir[5] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}}; //동 서 북 남

int changeDiceIndex(int diceIndex, int dir) {
    int result = 0;
    switch(dir) {
        case 1: //동
            if(diceIndex == 1 || diceIndex == 2 || diceIndex == 5 || diceIndex == 6) result = 4;
            else if(diceIndex == 3) result = 1;
            else if(diceIndex == 4) result = 3;
            break;
        case 2: //서
            if(diceIndex == 1 || diceIndex == 2 || diceIndex == 5 || diceIndex == 6) result = 3;
            else if(diceIndex == 3) result = 6;
            else if(diceIndex == 4) result = 1;
            break;
        case 3: //북
            if(diceIndex == 1) result = 5;
            else if(diceIndex == 5) result = 6;
            else if(diceIndex == 6) result = 3;
            else if(diceIndex == 2) result = 1;
            else if(diceIndex == 4) result = 5;
            else if(diceIndex == 3) result = 5;
            break;
        case 4: //남
            if(diceIndex == 1) result = 2;
            else if(diceIndex == 5) result = 1;
            else if(diceIndex == 6) result = 5;
            else if(diceIndex == 2) result = 6;
            else if(diceIndex == 4) result = 2;
            else if(diceIndex == 3) result = 2;
            break;
        default:
            break;
    }
    return result;
}

void input() {
    cin>> N >>M >> X >> Y >> K ;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin>>map[i][j];
    }
    instruction.assign(K, 0);

    for(int i=0; i<K; i++) {
        cin>> instruction[i];
    }
}

bool isAvailable(int y, int x) {
    if(0<= y && y < N && 0<= x && x <M) return true;
    return false;
}

void solution() {
    int currentY = Y;
    int currentX = X;
    int diceIndex = 0;
    
    for(int i=0; i<instruction.size(); i++) {
        int moveRow =  moveDir[instruction[i]].row;
        int moveColumn = moveDir[instruction[i]].column;
        
        int nextY = currentY + moveRow;
        int nextX = currentX + moveColumn;
        
        if(isAvailable(nextY, nextX)) {
            cout<<"이동한 맵의 위치:"<<nextY<<","<<nextX<<":"<<map[nextY][nextX]<<endl;
            int nextDiceIndex = changeDiceIndex(diceIndex+1, instruction[i])-1;
            cout<<"이동한 주사위의 위치:"<<nextDiceIndex+1<<":"<<dice[nextDiceIndex]<<endl;
            int diceUnderIndex = 5 - nextDiceIndex;
            cout<<"주사위 밑바닥:"<<diceUnderIndex+1<<":"<<dice[diceUnderIndex]<<endl;;
            //지도 내의 범위로 이동한 경우
            if(map[nextY][nextX] == 0) {
                //이동한 칸에 쓰여있는 수가 0이면
                //주사위 바닥에 쓰여있는 수가 칸에 복사된다
                cout<<diceUnderIndex+1<<"값을"<<nextY<<","<<nextX<<"에"<<endl;
                map[nextY][nextX] = dice[diceUnderIndex];
            } else {
                //이동한 칸에 쓰여있는 수가 0이 아니라면
                cout<<map[nextY][nextX]<<"값을"<<diceUnderIndex+1<<endl;
                dice[diceUnderIndex] = map[nextY][nextX];
                
            }
            
            currentY = nextY;
            currentX = nextX;
            diceIndex = nextDiceIndex;
            
            cout<<"=========================="<<endl;
            cout<<diceIndex+1<<":"<<dice[diceIndex]<<"\n";
            cout<<"=========================="<<endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}
