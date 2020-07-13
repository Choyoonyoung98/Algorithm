//
//  main.cpp
//  Truck
//
//  Created by 조윤영 on 26/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42583
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
//큐를 활용할 때 생각해야할 문제
//큐 = 현재 활동하고 있는 여러 개의 상태를 쌓을 때 사용!

//2020/05/19 풀이
int solution2(int bridge_length, int weight, vector<int> truck_weights) {
    struct Truck {
        int index;
        int weight;
        int endTime;
        
        Truck(int _index, int _weight, int _endTime) {
            index = _index;
            weight = _weight;
            endTime = _endTime;
        }
    };
    
    queue<Truck> bridge;
    int weightSum = truck_weights[0];
    int index = 0;
    int time = 1;
    
    bridge.push(Truck(0,truck_weights[index], 1+bridge_length));
    
    index++;

    while(!bridge.empty()) {
        time++;

        if(bridge.front().endTime == time) {
            int truckWeight = bridge.front().weight;
            bridge.pop();

            weightSum -= truckWeight;
        }

        if(index < truck_weights.size()) {

            if(weightSum + truck_weights[index] <= weight)  {

                int nextTime = time +bridge_length;
            
                bridge.push(Truck(index, truck_weights[index], nextTime));
                weightSum += truck_weights[index];
                index++;
            }
        }
    }
    
    return time;
}


//큐를 사용한 효율적인 풀이(*)
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    
    int d = 0; int cnt = 0; int sum=0;
    for(int i=0; i<truck_weights.size(); i++) {
        d = truck_weights[i];
        
        while(true) {
            if (q.size() == bridge_length) { //다리 길이만큼 트럭이 다리에 올라와 있다면,
                sum-=q.front();
                q.pop(); //가장 먼저 오른 트럭 지나가게 하기
                
            }else{
                if(sum +d >weight) {//가능한 무게를 초과할 경우
                    q.push(0);
                    cnt++;
                }else{
                    q.push(d);
                    cnt++;
                    sum+=d;
                    break;
                }
            }
        }
    }
    
    return cnt + bridge_length;
}
int main(int argc, const char * argv[]) {
        vector<int> t_weight{7,4,5,6};
        cout<<solution(2,10,t_weight);

//    vector<int> t_weight{10,10,10,10,10,10,10,10,10,10};
//    cout<<solution3(100,100,t_weight);
//    vector<int> t_weight{10,10,10,10,10,10,10,10,10,10};
//    cout<<solution3(100,100,t_weight);
    return 0;
}
