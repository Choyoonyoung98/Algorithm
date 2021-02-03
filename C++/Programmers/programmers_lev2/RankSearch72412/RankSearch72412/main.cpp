//
//  main.cpp
//  RankSearch72412
//
//  Created by 조윤영 on 2021/02/02.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

const string ALL = "-";
unordered_map<string, vector<int>> m;
//for(int i=0; i<16; i++) insert(key, i, score);
//mask는 0부터 15까지 존재한다
void insert(string* key, int mask, int point) {
    string s = "";
    for(int i=0; i<4; i++) {
        //x&y: x와 y 비트 모두를 일컫는다
        //<<: 1의 비트를 i자리만큼 이동시킨다
        //(mask & (1 << i)): i번째 요소를 검사한다 -> 존재하면 양수, 존재하지 않으면 음수
        /*
    0000 & 0, 1, 2, 3 << 0 -> java+backend+junior+pizza
    0001 & 0, 1, 2, 3 -> - + backend + junoir + pizza
    0010 & 0, 1, 2, 3 -> java + - + junior + pizza
    0011 & -> - + - + junior + pizza
    4
    */
        s += (mask & (1 << i)) ? ALL : key[i];
        m[s].push_back(point);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string key[4], temp; // 4가지 항목
    int score; // 점수
    
    for(auto& inf: info) { //(*) auto&
        istringstream iss(inf);
        iss >> key[0] >> key[1] >> key[2] >> key[3] >> score;
        for(int i=0; i<16; i++) insert(key, i, score);
    }
    
    for(auto& a: m) sort(a.second.begin(), a.second.end());
    
    for(auto& q: query) {
        istringstream iss(q);
        //istringstream: 공백 기준으로 split
        //iss >>
        //"java >> and >> backend >> and >> junior >> and >> pizza >> 100"
        iss >> key[0] >> temp >> key[1] >> temp >> key[2] >> temp >> key[3] >> score;
        string s = key[0] + key[1] + key[2] + key[3];
        vector<int>& v = m[s];
        //lower_bound: 이분 탐색을 통해 해당 점수보다 "같거나" 높은 점수가 처음으로 등장하는 위치를 찾아준다
        //upper_bound: 이분 탐색을 통해 해당 점수보다 큰 수가 처음으로 등장하는 위치를 찾아준다
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), score));
    }
    return answer;
}


//(2) 시간 초과한 풀이
vector<vector<string>> info_list;
vector<vector<string>> search_list;

vector<vector<string>> split(vector<string> list) {
    vector<vector<string>> split_list;
    for(string l: list)  {
        vector<string> vec;
        string temp = "";
        for(int i=0; i<l.size(); i++) {
            if(l.substr(i, 5) != " and " && l.substr(i, 1) == " ") {
                vec.push_back(temp);
                temp = "";
            } else if(l.substr(i, 5) == " and ") {
                vec.push_back(temp);
                temp = "";
                i += 4;
            } else {
                temp += l[i];
            }
        }
        vec.push_back(temp);
        split_list.push_back(vec);
    }

    return split_list;
}

bool compare(vector<string> &a, vector<string> &b) {
    return stoi(a[4]) < stoi(b[4]);
}
vector<int> solution2(vector<string> info, vector<string> query) {
    vector<int> answer;
    info_list = split(info);
    search_list = split(query);
    sort(info_list.begin(), info_list.end(), compare);

    for(vector<string> searchInfo: search_list) {
        int cnt = 0;
        string language = searchInfo[0];
        string position = searchInfo[1];
        string career = searchInfo[2];
        string food = searchInfo[3];
        int score = stoi(searchInfo[4]);

        int left = 0;
        int right = info_list.size() - 1;
        int mid = 0;
        while(left <= right) {
            mid = (left + right) / 2;
            if(stoi(info_list[mid][4]) < score) { left = mid + 1; }
            else { right = mid - 1; }
        }

        for(int i=mid; i<info_list.size(); i++) {
            vector<string> info = info_list[i];
            bool isMatch = true;
            if (language != "-" && language != info[0]) isMatch = false;
            if (position != "-" && position != info[1]) isMatch = false;
            if (career != "-" && career != info[2]) isMatch = false;
            if (food != "-" && food != info[3]) isMatch = false;
            if(score > stoi(info[4])) isMatch = false;

            if(isMatch) cnt ++;
        }


        answer.push_back(cnt);

    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string > query =  {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    solution(info, query);

    return 0;
}
