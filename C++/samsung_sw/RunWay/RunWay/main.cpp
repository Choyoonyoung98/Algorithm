//
//  main.cpp
//  RunWay
//
//  Created by 조윤영 on 19/10/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <cmath> //abs
#define MAX_SIZE 101

using namespace std;

int path[MAX_SIZE][MAX_SIZE];
int cpy_path[MAX_SIZE][MAX_SIZE];
int N,L; // 크기가 NxN인 지도, 길이가 L인 경사로.
int compareColumn ,compareRow;
bool isColumnPath ,isRowPath;
int cnt;
bool isFlat;

typedef struct {
    int y;
    int x;
}Dir;

Dir moveDir[4] = {{-1,0},{0,-1},{1,0},{0,1}};


void check(int row, int path[MAX_SIZE][MAX_SIZE]) {
    bool is_path[MAX_SIZE] = {false}; //해당 행이 모두 true일 경우 지나갈 수 있는 길로 인식하기 위해서
    int temp = path[row][0];
    for(int i=0; i<N; i++) {
        if(path[row][i] != temp) {//높이가 첫번째 열과 같지 않고,
            if(abs(path[row][i] - temp) >1) return;//차이가 1보다 높을 경우 연결할 수 없으므로

            //차이가 1일때,
            if(path[row][i] <temp)  {//내리막길 경사로를 깔아야 할 경우,
               
                int num = -1;
                
                 //이전의 길들이 모두 평평한지 확인해야한다.
                for(int j=0; j<=i+L-1; j++) {//
                    if(j>=N || is_path[j]) return;//경계값을 벗어나거나 해당 길이 true이면 반환,
                    is_path[j] = true;//해당 길 확인할게.
                    
                    if(num == -1) {//처음 접근일 경우,
                        num = path[row][j];//해당 값을 저장
                        continue;
                    }
                    if(num !=-1 && path[row][j] !=num) return;

                }
                i = i+L-1;
                if(i>=N) break;
            }
            else{//오르막길 경사로를 깔아야 할 경우,

            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>> N >> L;

    for(int i=0; i<N;i++) {
        for(int j=0; j<N; j++) {
            cin >> path[i][j];
            cpy_path[i][j]= path[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        check(i,path);
        check(i,cpy_path);
    }
    cout<< cnt;
    return 0;
}
//int main(int argc, const char * argv[]) {
//
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin>> N >> L;
//    cnt = N*2;
//
//    for(int i=0; i<N; i++) {
//        for(int j=0; j<N; j++) {
//            cin>>path[i][j];
//        }
//    }
//
//    //1.경사로를 세우지 않았을 때 지나갈 수 있는 길의 개수 알아보기
//    for(int i=0; i<N; i++) {
//        compareColumn =path[i][0];
//        compareRow = path[0][i];
//
//        isColumnPath = true;
//        isRowPath = true;
//
//        for(int j=0; j<N; j++) {
//            if(path[i][j]!=compareColumn){
//                isColumnPath = false;
//                break;
//            }
//            if(path[j][i] !=compareRow) {
//                isRowPath = false;
//                break;
//            }
//        }
//        if(isColumnPath == false)cnt--;
//        if(isRowPath == false) cnt--;
//    }
//
//    //2.경사로를 세워보자.
//    int nextX, nextY;
//    for(int i=0; i<N;  i++) {
//        for(int j=0; j<N; j++) {
//            int r = path[i][j];
//            for(int k=0; k<4; k++) {
//
//                //연결할 길(L만큼 떨어져 있는 길)
//                nextY = i+L*moveDir[k].y;
//                nextX = j+L*moveDir[k].x;
//
//                int x,y;
//                if(0<=nextX&& nextX <N && 0<=nextY&& nextY <N) {
//
//                    if(abs(r -path[nextY][nextX]) == 1 ) {//연결할 길이 서로 1만큼 높이가 차이가 날때
//                        cout<<nextY<<","<<nextX<<endl;
//                        isFlat = true;
//                        for(int l=1; l<L; l++ ) {
//                            x = r+l*moveDir[k].x;
//                            y = r+l*moveDir[k].y;
//
//                            if(path[nextY][nextX] !=path[y][x]){
//                                isFlat = false;
//                                break;
//                            }
//                        }
//                        if(isFlat == true) {
//                            cout<<"hi";
//                            //일단 경사로 길이만큼 평평
//                            //그럼 낮은 경로를 모두 +1씩 증가
//                            int m = max(r, path[nextY][nextX]);
//
//                            for(int l=0; l<L+1; l++ ) {
//                                x = r+l*moveDir[k].x;
//                                y = r+l*moveDir[k].y;
//                                path[y][x] =m;
//
//                        }
//                    }
//                }
//
//            }
//
//        }
//    }
//}
//    for(int i=0; i<N; i++) {
//        compareColumn =path[i][0];
//        compareRow = path[0][i];
//
//        isColumnPath = true;
//        isRowPath = true;
//
//        for(int j=0; j<N; j++) {
//            if(path[i][j]!=compareColumn){
//                isColumnPath = false;
//                break;
//            }
//            if(path[j][i] !=compareRow) {
//                isRowPath = false;
//                break;
//            }
//        }
//        if(isColumnPath != false)cnt++;
//        if(isRowPath != false) cnt++;
//    }
//
//
//    cout<<"***************"<<endl;
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++) {
//            cout<<path[i][j];
//        }
//        cout<<endl;
//    }
//    cout<<cnt;
//
//    return 0;
//}
