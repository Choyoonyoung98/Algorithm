//
//  main.cpp
//  ColoringBook
//
//  Created by 조윤영 on 14/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <vector>
#include <cmath>
#include <iostream>
#define MAX_SIZE 100
using namespace std;

int visited[MAX_SIZE][MAX_SIZE] = {false};

struct Dir{
    int y;
    int x;
};
vector<int> land;
int number_of_area = 0;
int max_size_of_one_area = 0;
int size_of_area = 0;

Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

bool checkPositionCondition(int m, int n, int posY, int posX, vector<vector<int>> &picture) {
    
    if(0<=posY && posY <=m && 0<=posX && posX <=n){
        if(visited[posY][posX] != true && picture[posY][posX]!=0 ) return true;
    }
       
    return false;
}

bool checkLandTypeEqual(int m, int n, int& posY, int& posX, vector<vector<int>>& picture, int targetLand) {
    if(0<= posY && posY <m && 0<= posX && posX < n) {
        if(visited[posY][posX] !=true && picture[posY][posX] == targetLand) {
            cout<<"("<<posY<<","<<posX<<","<<picture[posY][posX]<<","<<targetLand<<")";
            return true;
        }
    }

    return false;
}

void dfs(int m, int n, vector<vector<int>> &picture, int posY, int posX, int targetLand) {
    int currentY = posY;
    int currentX = posX;
    int nextY = 0;
    int nextX = 0;

    visited[currentY][currentX] = true;
    size_of_area++;

    for(int i=0; i<4; i++) {
        nextY = currentY + moveDir[i].y;
        nextX = currentX + moveDir[i].x;
    cout<<"current"<<"["<<currentY<<"]["<<currentX<<"]"<<i<<"["<<nextY<<"]["<<nextX<<"]?";

        if(checkLandTypeEqual(m, n, nextY, nextX, picture, targetLand) == true) {
            cout<<"current"<<"["<<currentY<<"]["<<currentX<<"]"<<i;
            cout<<"->["<<nextY<<"]["<<nextX<<"]"<<":<<targetLand:"<<targetLand<<endl;
            dfs(m, n, picture, nextY, nextX, targetLand);
        }else{
            cout<<"x"<<endl;
        }

    }
    return;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    //변수 선언
    number_of_area = 0;
    max_size_of_one_area = 0;
    land = {};
    int targetLand = 0;
    vector<int> answer(2);
    
    //코딩 시작
    //어떤 영역을 찾으면 탐색하도록 dfs 부르는 것이 더 합리적
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(checkPositionCondition(m, n, i, j, picture)== true) {
                number_of_area++;
                targetLand = picture[i][j];
                cout<<endl;
                cout<<"******************************"<<endl;
                cout<<number_of_area<<endl;
                cout<<"******************************"<<endl;
                dfs(m,n,picture,i, j, targetLand);
                cout<<"size:"<<size_of_area;
                
                max_size_of_one_area = (max_size_of_one_area<size_of_area)?size_of_area:max_size_of_one_area;
                
                size_of_area = 0;
        
            }
        }
        
    }
    
    //반환
    cout<<"number_of_area:"<<number_of_area;
    cout<<"max_size_of_one_area"<<max_size_of_one_area;
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(int argc, const char * argv[]) {
    int m = 13;
    int n = 16;
    vector<vector<int>> picture = {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},{0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0},{0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0},{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},{0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0},{0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0},{0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0},{0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0},{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}};
    
    solution(m,n,picture);
    
    return 0;
}

//1 1 1 0
//1 2 2 0
//1 0 0 1
//0 0 0 1
//0 0 0 3
//0 0 0 3


//testcase 2
//13, 16, [[0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0], [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0], [0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0], [0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0], [0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], [0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0], [0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0], [0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0], [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0], [0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0]]
//답은 12,120입니다.
