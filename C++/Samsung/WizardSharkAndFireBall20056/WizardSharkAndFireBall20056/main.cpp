//
//  main.cpp
//  WizardSharkAndFireBall20056
//
//  Created by 조윤영 on 2021/04/01.
//
//충격적인문제!!
#define MAX_SIZE 51
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N, M, K;
struct Dir {
    int y;
    int x;
    Dir(int _y, int _x) {
        y = _y;
        x = _x;
    };
};

struct FireBall {
    int y;
    int x;
    int m;
    int s;
    int d;
    int cnt;
    FireBall(int _y, int _x, int _m, int _s,  int _d) {
        y = _y;
        x = _x;
        m = _m;
        s = _s;
        d = _d;
        cnt = 0;
    };
    FireBall(int _y, int _x, int _m, int _s,  int _d, int _cnt) {
        y = _y;
        x = _x;
        m = _m;
        s = _s;
        d = _d;
        cnt = _cnt;
    };
};

Dir moveDir[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

queue<FireBall> q;
map<pair<int, int>, FireBall> m;
vector<vector<queue<FireBall>>> room_info;
void input() {
    cin>> N >> M >> K;
    int r, c, m, s, d;
    //y, x, 질량, 방향, 속력
    for(int i=0; i<M; i++) {
        cin>> r >> c >> m >> s >> d;
        q.push(FireBall(r-1, c-1, m, s, d));
    }
}

bool isAvailable(int y, int x) {
    if(0<= y && y < N && 0<= x && x < N) return true;
    return false;
}

//(2)
int applyBoundLimit2(int n) {
    int result = n;
    
    //jump size가 매우 클 수 있기 때문에 범위에 들어올 때까지 while문을 돌려야 한다!
    //******************************//
    while(result < 1) result += N;
    while(result > N) result -= N;
    //******************************//
    return result;
}

int applyBoundLimit(int n) {
    int result = n;
    if(result < 1) result += N;
    if(result > N) result -= N;
    return result;
}

int solution() {
    int answer = 0;
    for(int i=0; i<K; i++) {
        //파이어볼 이동
        vector<vector<vector<FireBall>>> ball_list;
        ball_list.assign(N+1, vector<vector<FireBall>>(N+1, {{}}));
        map<pair<int,int>, int> m;
//        cout<<"["<<q.size()<<"]"<<endl;
        while(!q.empty()) {
            int ballY = q.front().y;
            int ballX = q.front().x;
//            cout<<"["<<ballY<<","<<ballX<<"]";
            int ballMass = q.front().m;
            int ballSpeed = q.front().s;
            int ballDrection = q.front().d;
            q.pop();
            
            int nextSpeed = ballSpeed % N;
            //(1)
            int nextY = ballY + moveDir[ballDrection].y * nextSpeed;
            int nextX = ballX + moveDir[ballDrection].x * nextSpeed;
            nextY = applyBoundLimit(nextY);
            nextX = applyBoundLimit(nextX);
//            cout<<"=>"<<nextY<<","<<nextX<<":"<<ballMass<<endl;
            ball_list[nextY][nextX].push_back(FireBall(nextY, nextX, ballMass, ballSpeed, ballDrection));
            m[{nextY, nextX}]++;
        }
    
        for(auto iter = m.begin(); iter != m.end(); iter++) {
            int y = iter->first.first;
            int x = iter->first.second;
            if(iter->second >= 2) {
                int cnt = iter->second;
                int mass = 0;
                int speed = 0;
                bool isEven = true;
                bool isOdd = true;
                for(int k=0; k<ball_list[y][x].size(); k++) {
                    mass += ball_list[y][x][k].m;
                    speed += ball_list[y][x][k].s;
                    if(ball_list[y][x][k].d %2 == 0) isOdd = false;
                    else isEven = false;
                }
                
                mass /= 5;
                speed /= cnt;
                if(mass == 0) continue;
                
                int dir = 0;
                if(!(isEven || isOdd)) dir++;
                for(int d=0; d<4; d++) q.push(FireBall(y, x, mass, speed, dir + 2*d));
            } else q.push(FireBall(y, x, ball_list[y][x][0].m, ball_list[y][x][0].s, ball_list[y][x][0].d));
        }
//        cout<<"--------"<<endl;
    }
    
    while(!q.empty()) {
        answer += q.front().m;
        q.pop();
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    input();
    cout<<solution()<<"\n";
    return 0;
}
