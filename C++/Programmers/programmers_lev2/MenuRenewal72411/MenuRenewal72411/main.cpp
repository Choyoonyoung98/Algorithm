//
//  main.cpp
//  MenuRenewal72411
//
//  Created by 조윤영 on 2021/02/02.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
vector<pair<int,string>> candidate;
void DFS(string set, string order, int index, int cnt) {
    if(set.size() == cnt) {
        m[set]++;
        if(m[set] >= 2) candidate.push_back({m[set], set});
        return;
    }
    for(int i=index; i<order.size(); i++) {
        string newSet  = set + order[i];
        DFS(newSet, order, i+1, cnt);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int c: course) {
        for(string order: orders) {
            sort(order.begin(), order.end());
            DFS("", order, 0, c);
        }

        sort(candidate.begin(), candidate.end(), greater<pair<int, string>>());
        int maxCandidate = 0;
        for(int i=0; i<candidate.size(); i++) {
            if(maxCandidate <= candidate[i].first) {
                maxCandidate = candidate[i].first;
                answer.push_back(candidate[i].second);
            }
            else { break; }
        }
        candidate.clear();
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> orders = {"XYZ", "XWY", "WXA"};
    vector<int> course = {2, 3, 4};
    solution(orders, course);
    return 0;
}
