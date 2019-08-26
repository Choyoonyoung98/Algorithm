//
//  main.cpp
//  Truck
//
//  Created by 조윤영 on 26/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//큐를 사용한 효율적인 풀이
int solution2(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    
    int sum, count; sum = count = 0;
    
    for(int i=0; i<truck_weights.size(); i++) {
        int d = truck_weights[i];//7
        //stack:(7)
        //count:2
        //sum:7
        
        while (true) {
            
            if (q.empty()) {//맞아 안에 아무것도 없어
                q.push(d);//7 집어넣음
                count++;//cnt++
                sum += d;//7
                break;
            }
            else if (q.size() == bridge_length) { //맞아
                sum -= q.front(); q.pop();//sum: 0
            }
            else {
                
                if (sum + d > weight) {//7+4 > 10
                    q.push(0); //0집어넣어
                    count++;
                }
                else {
                    q.push(d);
                    count++;
                    sum += d;
                    break;
                }
            }
        }
    }
    
    return count + bridge_length;
}


//윤영의 엉망진창 풀이
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    stack<int> s;
    vector<int> vec;
    int sum =0;
    int t=0;
    
    for(int i=0; i<truck_weights.size(); i++) {
        
        sum+=truck_weights[i];
        t+=1;

        if(sum>weight){
            s.push(t-1);
            sum = truck_weights[i];
            t=1;
            if(i==(truck_weights.size()-1) && sum !=0) {
                s.push(t);
            }
            continue;
        }
        if(sum == weight) {
            s.push(t);
            sum =0;
            t=0;
            continue;
        }
        
        if(i==(truck_weights.size()-1) && sum !=0) {
            s.push(t);
        }
    }
    while(!s.empty()) {
        cout<<s.top();
        if(s.top() !=1){
                answer += bridge_length+s.top()-1;
        }else{
            answer+=bridge_length;
        }
        s.pop();
    }
    answer+=1;
    cout<<endl;
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> t_weight{10,10,10,10,10,10,10,10,10,10};
    cout<<solution(100,100,t_weight);
    return 0;
}
