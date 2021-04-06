//
//  main.cpp
//  PageReplacementAlgorithm
//
//  Created by 조윤영 on 2021/04/06.
//

#define INF 1e9
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
//cahe miss: 5초
//cache hit: 1초
//erase: 해당 인덱스의 데이터를 삭제하고, 그 뒤에 있는 데이터를 남은 자리만큼 앞으로 이동시킨다!

//FIFO: unordered_set & queue
int FIFOPageRelacement(int cacheSize, vector<string> cities) {
    unordered_set<string> s; //정렬되지 않으며 해시 함수를 사용하여 원소를 탐색한다!
    queue<string> q;
    int time = 0;
    
    for(string city: cities) {
        if(s.find(city) == s.end()) {
            //비어있는 공간이 없다면? 가장 처음에 들어간 페이지 OUT (FIFO)
            if(s.size() == cacheSize) {
                string val = q.front();
                q.pop();
                s.erase(val);
            }
            s.insert(city);
            q.push(city);
            time += 5;
            
        } else time++;
    }
    return time;
}

vector<string> cache;
int findInCache(string target) {
    for(int i=0; i<cache.size(); i++) {
        if(cache[i] == target) return i;
    }
    return -1;
}

//LRU: Least Recently Used - 가장 최근에 사용되지 않은 페이지 교체
int LRUPageReplacement(int cacheSize, vector<string> cities) {
    //들어온 순서대로 캐시에 데이터를 저장한다: FIFO queue
    //캐시용량이 다 찼을 경우 처음 들어온 데이터는 나가게 되고 다음 데이터가 들어오게 된다
    //만약 캐시의 데이터가 사용됐다면 제일 뒤로 미뤄져야 한다
    cache.clear();
    int time = 0;
    
    for(string city: cities) {
        int findIdx = findInCache(city);
        if(findIdx == -1) {
            time += 5;
            //비어있는 공간이 없다면? 가장 처음에 들어간 페이지 OUT (FIFO)
            if(cache.size() == cacheSize) cache.erase(cache.begin());
        } else {
            time++;
            cache.erase(cache.begin() + findIdx);
        }
        cache.push_back(city);
    }
    return time;
}

//?
//https://www.geeksforgeeks.org/program-for-least-recently-used-lru-page-replacement-algorithm/
int LRUPageReplacement2(int cacheSize, vector<string> cities) {
    unordered_set<string> s;
    unordered_map<string, int> m;
    int time = 0;
    
    for(int i=0; i<cities.size(); i++) {
        string city = cities[i];
        
        if(s.find(city) == s.end()) {
            if(s.size() >= cacheSize) {
                int LRU = INF;
                string val;
                for(auto iter = s.begin(); iter != s.end(); iter++) {
                    if(m[*iter] < LRU) {
                        LRU = m[*iter];
                        val = *iter;
                    }
                }
                s.erase(val);
            }
            s.insert(city);
            time += 5;
        } else time++;
        
        m[city] = i;
    }
    return time;
}

//LFU
void LFUPageReplacement(int cacheSize, vector<string> cities) {
    cache.clear();
}

//NUR
void NURPageReplacement(int cacheSize, vector<string> cities) {
    cache.clear();
}

int main(int argc, const char * argv[]) {
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    cout<<"[FIFO]:"<<FIFOPageRelacement(cacheSize, cities)<<"\n";
    cout<<"[LRU]:"<<LRUPageReplacement(cacheSize, cities)<<"\n";
    return 0;
}
