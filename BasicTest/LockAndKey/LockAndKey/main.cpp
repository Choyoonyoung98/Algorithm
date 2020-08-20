//
//  main.cpp
//  LockAndKey
//
//  Created by 조윤영 on 2020/08/13.
//  Copyright © 2020 조윤영. All rights reserved.
//
//자물쇠와 열쇠
//엥 설마 완전 탐색인가? 할때는 그냥 완탐해버리기.. 고민할 시간이 없다

#include <string>
#include <vector>
#include <iostream>

#define MAX_SIZE 20
using namespace std;
//
//int lock_extension[MAX_SIZE][MAX_SIZE];
//vector<vector<int>> rotateKey(vector<vector<int>> key, int M);
//bool compareKeyAndLocker(vector<vector<int>> key, vector<vector<int>> locker_extension, int startY, int startX, int M, int N);
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//    bool answer = false;
//    int N = lock.size();
//    int M = key.size();
//
//    vector<vector<int>> locker_extension(2*M + N - 2, vector<int>(2*M + N - 2, 0)); //이차원 벡처 초기화는 이렇게!
//
//    for(int i=0; i<N; i++) {
//        for(int j=0; j<N; j++) locker_extension[i+N-1][j+N-1] = lock[i][j];
//    }
//
//    int L = locker_extension.size();
//    for(int r=0; r<3; r++) {
//        for(int i=0; i<L-M+1; i++) {
//            for(int j=0; j<L-M+1; j++) {
//                if(compareKeyAndLocker(key, locker_extension, i, j, M, N)) return true;
//            }
//        }
//        key = rotateKey(key, M);
//    }
//    return answer;
//}
//
//bool compareKeyAndLocker(vector<vector<int>> key, vector<vector<int>> locker_extension, int startY, int startX, int M, int N) {
//    for(int i=0; i<M; i++) {
//        for(int j=0; j<M; j++) {
//            if(startY+i <= N+1 &&  startX+i <= N+1) {
//                if(key[i][j] + locker_extension[startY+i][startX+j] != 1) return false;
//            }
//        }
//    }
//    return true;
//}
//
//vector<vector<int>> rotateKey(vector<vector<int>> key, int M) {
//    vector<vector<int>> rotated_key(M, vector<int>(M, 0));
//
//    for(int i=0; i<M; i++) {
//        for(int j=0; j<M; j++) rotated_key[i][j] = key[M-j-1][i];
//    }
//    return rotated_key;
//}

bool compare(int y, int  x,  vector<vector<int>> board, vector<vector<int>> key);
int N = 0;
int M = 0;
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    N = lock.size();
    M = key.size();
    vector<vector<int>> board(N+M*2-2);
    
    //확장 보드에 자물쇠 추가
    for(int nY = M-1,  y = 0; nY < M-1 + N; nY++, y++) {
        for(int nX = M-1, x = 0; nX < M-1 + N; nX++, x++) {
            board[nY][nX] = lock[y][x];
        }
    }
    
    //자물쇠에 키와 비교해보기
    for(int i = 0; i < M+N-1; i++) {
        for(int j = 0; j< M+N-1; j++) {
            for(int r = 0; r< 4; r++) {
                if(compare(i, j, board, key)) return true;
            }
        }
    }
    
    
    
    
}

bool compare(int y, int  x, vector<vector<int>> board, vector<vector<int>> key) {
    for(int nY = y, i = 0; nY < y + M; nY++, i++) {
        for(int nX = x, j = 0; nX < x + M; nX++, y++) {
            
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> key = {{0,0,0}, {1,0,0}, {0,1,1}};
    vector<vector<int>> lock =  {{1,1,1},{1,1,0},{1,0,1}};
    if(solution(key, lock)) cout<<"TRUE";
    else cout<<"FALSE";
    return 0;
}

//0 0 0  각 항목의 0번째 인덱스를 0번째 항목에 집어넣고
//1 0 0. 각 항목의 1번째 인덱스를 1번째 항목에 집어넣고... 를 반복하면 시계방향 90도 회전 가능
//0 1 1
