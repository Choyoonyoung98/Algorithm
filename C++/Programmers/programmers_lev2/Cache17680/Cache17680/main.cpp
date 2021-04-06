//
//  main.cpp
//  Cache17680
//
//  Created by 조윤영 on 2021/04/06.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> cache;

int searchFromCache(string target) {
    for(int i=0; i<cache.size(); i++) {
        if(cache[i] == target) return i;
    }
    return -1;
}

//LRU Least REcently Used 즉, 가장 최근에 사용하지 않은 페이지를 삭제하는 알고리즘
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return 5 * cities.size();
    
    for(string city: cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        int findIdx = searchFromCache(city);
        if(findIdx == -1) {
            answer += 5;
            if(cache.size() == cacheSize) cache.erase(cache.begin());
        } else {
            answer ++;
            cache.erase(cache.begin()+findIdx);
        }
        cache.push_back(city);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    cout<<solution(cacheSize, cities)<<"\n";
    return 0;
}
