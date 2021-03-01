//
//  main.cpp
//  FixRoad_Line2020_1
//
//  Created by 조윤영 on 2021/02/28.
//

#include <iostream>
#include <queue>
using namespace std;

//투포인터
int solution1(string road, int n) {
    int answer = 0;
    int i = 0;
    int j = 0;
    int cnt = 0;
    queue<int> q;
    while(j < road.size()) {
        while(cnt <= n && j < road.size()) {
            while(road[j] != '0' &&  j < road.size()) j++;
            if(cnt < n) {
                cnt++;
                road[j] = '1';
                q.push(j);
            } else break;
        }

        answer = max(answer, j-i);
        
        i = q.front();
        q.pop();
        cnt --;
        road[i++] = '0';
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    string road = "111011110011111011111100011111";
    int n = 3;
    cout<<solution1(road, n)<<endl;
    return 0;
}
