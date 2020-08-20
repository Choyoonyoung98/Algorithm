//
//  main.cpp
//  MujiMukBangLive
//
//  Created by 조윤영 on 2020/08/09.
//  Copyright © 2020 조윤영. All rights reserved.
//
// 무지의 먹방 라이브

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>  pq;

int  solution(vector<int> food_times, long long k) {
    for(int i=0; i<food_times.size(); i++) pq.push({food_times[i],  i+1});

    int sum_value = 0;//먹기 위해 사용한 시간
    int previous = 0; //직전에 다 먹은 음식 시간
    int length = food_times.size();
    
    //먹기 위해 사용한 시간 + (현재의 음식 시간 - 이전 음식 시간)* 현재 음식 개수) <= k (제한 시간)
    while(true) {
        if(sum_value + ((pq.top().first - previous) * length) <= k) break;
        int now = pq.top().first;
        sum_value += (now - previous) * length;
        length -= 1;
        previous = now;
        
    }
    

    
    return -1;
}

int  solution2(vector<int> food_times, long long k) {
    long long sum = 0;
    long long before = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i=0; i<food_times.size(); i++) {
        sum += food_times[i]; //걸리는 시간
        pq.push(make_pair(food_times[i], i+1));
    }
    
    if(sum <= k) return -1;
    
    while(true) {
        int time = pq.top().first;
        int index = pq.top().second;

        if((time - before) * pq.size() > k) break;
        
        k  -= (time  - before) * pq.size();
        before = time;
        pq.pop();
    }
    
    vector<pair<int,int>> times;
    while(!pq.empty()) {
        cout<<pq.top().second<<endl;
        times.push_back({pq.top().second, pq.top().first});
        pq.pop();
    }
    
    sort(times.begin(), times.end());

    return times[k % times.size()].first;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> food_times = {3,1,2};
    int K = 5;
    cout<<solution2(food_times, K)<<"\n";
    return 0;
}
