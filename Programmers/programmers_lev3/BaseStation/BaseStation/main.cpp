//
//  main.cpp
//  BaseStation
//
//  Created by 조윤영 on 12/02/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/12979#qna

//1번 아파트부터 기지국을 설치해 나간다.
//만약 현재 설치하는 아파트에 이미 설치되어 있던 기지국 전파가 들어온다면,
//기지국 전파가 들어오는 범위에 아파트는 건너뛰고 다시 설치해 나간다.

#include <iostream>
#include <vector>
#define MAX_SIZE 200000000

using namespace std;
int visited[MAX_SIZE] = {false};

//정확도 통과 O / 효율성 통과 O
int solution(int n, vector<int> stations, int w) {
    int answer = 0;//기지국의 개수
    int c = 0;
    int i =1;//첫 번째 기지국부터 설치 시작한다.
    
    
    while(i<= n) {
        if( i >= stations[c] - w && i <= stations[c] + w) {
            //현재 설치되어 있는 기지국 영향 범위 안에 들어있다면,
            i = stations[c] + w;
            if(c+1 <stations.size())c++;
            
        }else {
            i += 2 * w;//현재 위치에 기지국을 설치하고, 설치한다고 생각했을 때의 범위에서 벗어나기
            //영향 범위의 두배는 해야지 완전히 벗어날 수 있음.
            answer++; //범위 밖이므로 기지국 설치
        }
        i++;
    }
    
    
    return answer;
}

//정확도 통과 O / 효율성 통과 X - stations 만큼 for문 돌아야 통과된다고 함.. 빡세네..
//bool isInBoundary(int pos, int n) {
//
//    if(0< pos && pos <=n && visited[pos] != true) return true;
//
//    return false;
//}
//
//int findBestPosition(int n, int w) {
//
//    int sumSpread = 0;
//    int spreadCnt = 0;
//
//    while(true) {
//
//        int maxSpread = -1;
//        int index = 0;
//
//        for(int i=1; i<=n; i++) {
//
//            int pos = i;
//            int spread = 0;
//
//            if(visited[pos] == true) continue;
//
//            for(int j=0; j<=w; j++) {
//
//                if(isInBoundary(pos-j, n)) {
//                    spread++;
//                }
//                if(isInBoundary(pos+j, n)) {
//                    spread++;
//                }
//            }
//
//            if(maxSpread < spread){
//                maxSpread = spread;
//                index = pos;
//            }
//
//        }
//
//        for(int i=0; i<=w; i++ ) {
//            if(isInBoundary(index-i,n)) visited[index-i] = true;
//            if(isInBoundary(index+i,n)) visited[index+i] = true;
//        }
//
//        sumSpread += maxSpread;
//
//        if(index == 0)break;
//        spreadCnt++;
//
//    }
//
//    return spreadCnt;
//}
//
//int solution(int n, vector<int> stations, int w)
//{
//
//    visited[0] = true; //사용하지 않는 공간
//    int answer = 0;
//
//    for(int i=0; i<stations.size(); i++) {
//        int pos = stations[i];
//
//       for(int j=0; j<=w; j++) {
//
//           //오른쪽으로 전파(범위를 벗어나지 않고, 전파되지 않은 아파트라면 전파)
//           if(isInBoundary(pos+j,n))visited[pos+j] = true;
//
//           //왼쪽으로 전파(범위를 벗어나지 않고, 전파되지 않은 아파트라면 전파)
//           if(isInBoundary(pos-j, n ))visited[pos-j] = true;
//
//       }
//    }
//
//    answer = findBestPosition(n, w);
//
//    return answer;
//}


int main(int argc, const char * argv[]) {
    int N = 11;
    vector<int> station = {4,11};
    int W = 1;

    cout<<solution(N, station, W);
    
    return 0;
}
