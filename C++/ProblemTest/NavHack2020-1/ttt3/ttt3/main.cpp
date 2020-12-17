//
//  main.cpp
//  ttt3
//
//  Created by 조윤영 on 11/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

int slope = 0;
int entireWidth = 0;
int slopeWidth = 0;

//BFS로 바꿔야 실행시간 단축시킬 수 있음....

//해당 위치, 스키슬로프/스노우보드슬로프의 갯수, 스키슬로프의 전체 너비, 스노우보드의 전체 너비, 해당 슬로프의 너비, 스키 슬로프/스노보드 슬로프 판단
void dfs(int index, int slopeCnt,int skiSlopeWidth, int snowSlopeWidth, int width, bool isSkiSlope) {

    //해당 위치가 끝이라면?
    if(index == entireWidth) {

        if((skiSlopeWidth == entireWidth/2) && (snowSlopeWidth == entireWidth/2) && slopeCnt==slope) {
            
            //스키 슬로프와 스노보드 슬로프의 너비를 각각 더했을 때, 동일한지 확인
            answer++;
            answer%=1000000007;
        }
        return;
    }
    

    //해당 슬로프의 너비 width가 최대 너비인 slopeWidth를 안넘는지 확인
    if(width == slopeWidth) {
        
        //해당 슬로프가 최대 너비에 도달했을 경우 새로운 슬로프로 전환
        if(isSkiSlope) {
            
            dfs(index+1, slopeCnt+1,skiSlopeWidth, snowSlopeWidth+1, 1, false);
        }else{
            dfs(index+1, slopeCnt+1,skiSlopeWidth+1, snowSlopeWidth, 1, true);
        }
        
    }else{//최대 너비르 넘지않는다면 2가지의 선택지
        
        
        //다른 슬로프로 전환하기
        if(isSkiSlope) {
            dfs(index+1, slopeCnt+1, skiSlopeWidth, snowSlopeWidth+1, 1, false);
        }else{
           dfs(index+1, slopeCnt+1, skiSlopeWidth+1, snowSlopeWidth, 1, true);
        }
        
        
        //해당 슬로프의 너비를 늘리거나
        if(isSkiSlope) {
            dfs(index+1, slopeCnt, skiSlopeWidth+1, snowSlopeWidth, width+1, true);
        }else{
           dfs(index+1, slopeCnt, skiSlopeWidth, snowSlopeWidth+1, width+1, false);
        }
        
        
    }
    
    
}
int solution(int n, int m, int k) {
    slope = n;
    entireWidth = m;
    slopeWidth = k;
    
    dfs(1,1,1,0,1,true);//스키로 시작
    dfs(1,1,0,1,1,false);//스노우보드로 시작
    
    
    cout<<answer;
    return answer;
}


int main(int argc, const char * argv[]) {
    solution(50,150,20);
    return 0;
}
