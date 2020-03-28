//
//  main.cpp
//  CatchMeIfYouCan
//
//  Created by 조윤영 on 28/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>


#define MAX_SIZE 200000

using namespace std;

int C = 0;
int B = 0;

struct Position {
    int cony;
    int brown;
    int time;
    
    Position(int _cony, int _brown, int _time) {
        cony = _cony;
        brown = _brown;
        time = _time;
    }
};

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>> C >> B;
}

void solution() {
    //코니
    //1,2,3,4,5
    //C +1, C+1+2, C+1+2+3, ....
    //코니의 위치 이동: 이전 위치  + (이전 이동거리 + 1)
    
    //브라운
    //B-1, B+1, 2*B
    
    //코니,브라운 위치 초기화
    queue<Position> q;
    
    q.push(Position(C,B,0));
    
    int cony = 0;
    int brown = 0;
    int cnt = 0;
    
    int minAnswer = 0;
    
    while(cony <=MAX_SIZE && brown <=MAX_SIZE) {
        cnt++;
        
        int qSize = q.size();
        
        for(int i=0; i<qSize; i++) {
            cony = q.front().cony;
            brown = q.front().brown;
            int time = q.front().time;
            
            q.pop();
            
            
            if(cony == brown){
                cout<<time<<"\n";
                return;
            }
            
            cony += cnt;
            
            q.push(Position(cony,brown-1,time+1));
            q.push(Position(cony,brown+1,time+1));
            q.push(Position(cony,brown*2, time+1));
        }

    }
    cout<<-1<<"\n";

}

int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}




//라인 공식 정답코드
/*
 t 초에서 위치가 p라고 가정할 때, t + 1초에서 위치는 p일 수 없습니다. 하지만 t + 2초에서는 위치가 p일 수 있습니다(t → t – 1 → t 혹은 t → t + 1 → t). 위 사실을 토대로 방문 시간을 홀수, 짝수로 나눠서 고려해야 한다는 것을 알 수 있습니다. 아래 solve 함수는 t 값을 증가시키면서 ‘코니가 t 초 후에 p 위치에 도착했을 때, 브라운이 p 위치에 t – 2k(단, k >= 0인 정수) 시간에 도착했는지 여부’를 판단하여 해당 조건을 만족하는 t를 찾는 알고리즘입니다.
 */
int solve(int conyPosition, int brownPosition) {
    int time = 0;
    bool visit[200001][2];
    queue<pair<int, int> > queue;
    memset(visit, 0, sizeof(visit));
    queue.push(make_pair(brownPosition, 0));
    while (1) {
      conyPosition += time;
        if (conyPosition > 200000)
            return -1;
        if (visit[conyPosition][time % 2])
            return time;
        for (int i = 0, size = queue.size(); i < size; i++) {
            int currentPosition = queue.front().first;
            int newTime = (queue.front().second + 1) % 2;
            int newPosition;
            queue.pop();
            newPosition = currentPosition - 1;
            if (newPosition >= 0 && !visit[newPosition][newTime]) {
                visit[newPosition][newTime] = true;
                queue.push(make_pair(newPosition, newTime));
            }
            newPosition = currentPosition + 1;
            if (newPosition < 200001 && !visit[newPosition][newTime]) {
                visit[newPosition][newTime] = true;
                queue.push(make_pair(newPosition, newTime));
            }
            newPosition = currentPosition * 2;
            if (newPosition < 200001 && !visit[newPosition][newTime]) {
                visit[newPosition][newTime] = true;
                queue.push(make_pair(newPosition, newTime));
            }
        }
        time++;
    }
}

