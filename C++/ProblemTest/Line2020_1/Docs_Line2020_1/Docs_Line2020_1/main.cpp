//
//  main.cpp
//  Docs_Line2020_1
//
//  Created by 조윤영 on 2021/03/01.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool compare(pair<int, string> &a, pair<int, string> &b) {
    if(a.first == b.first) return a.second < b.second;
    
    return a.first > b.first;
}
vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    vector<string> answer;
    vector<pair<int, string>> tag_info;
    map<string, bool> m;
    for(string tag: tags) {
        m[tag] = true;
    }
    
    for(vector<string> data: dataSource) {
        string index = data[0];
        int cnt = 0;
        for(int i=1; i<data.size(); i++) {
            if(m[data[i]] != NULL ) cnt++;
        }
        if(cnt != 0) tag_info.push_back({cnt, index});
    }
    
    sort(tag_info.begin(), tag_info.end(), compare);
    int end = (tag_info.size() > 10) ? 10 : tag_info.size()-1;
    for(int i=0; i<=end; i++) answer.push_back(tag_info[i].second);

    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> dataSource = {{"doc1", "t1", "t2", "t3"}, {"doc2", "t0", "t2", "t3"}, {"doc3", "t1", "t6", "t7"}, {"doc4", "t1", "t2", "t4"}, {"doc5", "t6", "t100", "t8"}};
    vector<string> tags = {"t1", "t2", "t3"};
    solution(dataSource, tags);
    return 0;
}
