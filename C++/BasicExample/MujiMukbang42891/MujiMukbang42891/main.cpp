//
//  main.cpp
//  MujiMukbang42891
//
//  Created by 조윤영 on 2020/12/27.
//
#define MAX_SIZE 100000000
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution2(vector<int> food_times, long long k) {
    int time = 0;
    
    while(true) {
        bool foodLeft = false;
        for(int i=0; i<food_times.size(); i++) {
            if(food_times[i] > 0) {
                if(time >= k ) return i+1;
                
                foodLeft = true;
                food_times[i]--;
                time++;
            }
        }
        if(!foodLeft) break;
    }
    return -1;
}

int solution(vector<int> food_times, long long k) {
    long long sum = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<food_times.size(); i++) {
        pq.push({food_times[i], i});
        sum += food_times[i];
    }

    if(sum<= k) return -1;
    
    int passedTime = 0;
    
    while(true) {
        if((pq.top().first - passedTime) * pq.size() > k) break;
        k -=  (pq.top().first - passedTime) * pq.size();
        passedTime = pq.top().first;
        pq.pop();
    }
    
    vector<pair<int,int>> temp;
    while(!pq.empty()) {
        temp.push_back({pq.top().second, pq.top().first});
        pq.pop();
    }
    sort(temp.begin(), temp.end());
    return temp[k % temp.size()].first + 1;
}

int main(int argc, const char * argv[]) {
    vector<int> food_times = {4, 3, 1, 2};
    int K = 5;
    cout<<solution(food_times, K)<<"\n";
    return 0;
}
