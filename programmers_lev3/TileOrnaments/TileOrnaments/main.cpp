//
//  main.cpp
//  TileOrnaments
//
//  Created by 조윤영 on 03/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//문제 이름: 타일 장식물
//https://programmers.co.kr/learn/courses/30/lessons/43104
//접근 방법: Fibonacci
#include <iostream>
#include <string>
#define MAX_SIZE 81

using namespace std;

long long tile[MAX_SIZE];
long long size = 0;

//2차 시도
//당연함. 시간복잡도는 같기 때문에..
void fibonacci(long long tileSize, int index, int n) {
    
    tile[index] = tileSize;
    
    if(index == n){
        size = tile[index]*2;
        return;
    }else{
        tileSize += tile[index-1];
        fibonacii(tileSize, index+1, n);
    }
    
    return;
}
//혹시 재귀로 하면 되려나? ㅎㅎ 그래도 효율성 통과 안함
long long solution(int N) {
    long long answer = 0;
    if(N == 1)return 4;
    tile[0] = 0;
    tile[1] = 1;
    
    fibonacci(1, 2, N+2);
    
    answer = size;
    return answer;
}

//1차 시도
//당연히 이렇게 하면 정확성 O, 효율성 X
//long long solution2(int N) {
//    long long answer = 0;
//
//    vector<int> tile;
//    tile.push_back(1);
//
//    int tileSize = 1;
//    for(int i=1; i<N+1; i++) {
//        cout<<tileSize;
//        tile.push_back(tileSize);
//        tileSize += tile[i-1];
//    }
//
//    answer = tile[tile.size()-1]*2 + tile[tile.size()-2]*2;
//    return answer;
//}

int main(int argc, const char * argv[]) {
    cout<<solution(5);
    return 0;
}
