//
//  main.cpp
//  Maze_Line2020_2
//
//  Created by 조윤영 on 2021/02/26.
//

#include <iostream>
#include <vector>
using namespace std;

struct Dir {
    int y;
    int x;
};
Dir moveDir[4] = {{1,0},{0,-1},{-1,0},{0,1}};
Dir leftUpperDir[4] = {{-1,1},{1,1},{1,-1},{-1,-1}};
vector<vector<int>> m;
bool isAvailable(int y, int x) {
    if(0<=y && y < m.size() && 0<= x && x < m.size()) return true;
    return false;
}

bool isWallExist(int y, int x) {
    if(!isAvailable(y, x) || m[y][x] == 1) return true;
    return false;
}

int solution(vector<vector<int>> maze) {
    m = maze;
    int currentDir = 3; //오른쪽 방면을 바라보는 것으로 시작
    int currentY = 0;
    int currentX = 0;
    int answer = 0;
    while(true) {
        if(currentY == m.size()-1 && currentX == m.size()-1) { return answer; }
        int leftHand = (currentDir + 4 - 1) % 4;
        int leftY = currentY + moveDir[leftHand].y;
        int leftX = currentX + moveDir[leftHand].x;
        int leftUpperY = currentY + leftUpperDir[currentDir].y;
        int leftUpperX = currentX + leftUpperDir[currentDir].x;
        
        if(isWallExist(leftY, leftX)) {
            int nextY = currentY + moveDir[currentDir].y;
            int nextX = currentX + moveDir[currentDir].x;
            
            if(isWallExist(nextY, nextX)) currentDir = (currentDir+1) % 4;
            else {
                currentY += moveDir[currentDir].y;
                currentX += moveDir[currentDir].x;
                answer += 1;
            }
        } else if(isWallExist(leftUpperY, leftUpperX)) {
            currentDir = (currentDir + 4 - 1) % 4;
            currentY += moveDir[currentDir].y;
            currentX += moveDir[currentDir].x;
            answer += 1;
        } else currentDir = (currentDir + 4 - 1) % 4;
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> maze = {{0, 0, 0, 0, 0, 0},{1, 1, 1, 0, 1, 1},{0, 0, 0, 0, 0, 0},{1, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0},{1, 1, 0, 1, 1, 0}};
    
//    {{0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 0}};
    
//1:    {{0, 1, 0, 1},{0, 1, 0, 0},{0, 0, 0, 0}, {1, 0, 1, 0}};
//2: {{0, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0}};
//4:    {{0, 0, 0, 0, 0, 0},{1, 1, 1, 0, 1, 1},{0, 0, 0, 0, 0, 0},{1, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0},{1, 1, 0, 1, 1, 0}};
    cout<<solution(maze)<<endl;
    return 0;
}
