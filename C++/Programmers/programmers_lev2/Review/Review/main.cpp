//
//  main.cpp
//  Review
//
//  Created by 조윤영 on 2020/05/17.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42583
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
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


int main(int argc, const char * argv[]) {
    
    int bridge_length = 100;
    int weight = 100;
    vector<int> priorities = {10,10,10,10,10,10,10,10,10,10};
    
    cout<<solution(bridge_length, weight, priorities);
    
    return 0;
}
