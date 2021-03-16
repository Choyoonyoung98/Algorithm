//
//  main.cpp
//  OpenChattingRoom
//
//  Created by 조윤영 on 21/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct Log {
    string action;
    string id;
    Log(string _action, string _id) {
        action = _action;
        id = _id;
    };
};
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<Log> vec;
    map<string, string> m;
    
    for(string log: record) {
        vector<string> data;
        string temp = "";
        for(char c: log) {
            if(c == ' ') {
                data.push_back(temp);
                temp = "";
            } else temp += c;
        }
        data.push_back(temp);
        
        string action = data[0];
        string id = data[1];
        string name = (data.size() == 3) ? data[2] : "";
        if(action != "Leave") m[id] = name;
        if(action != "Change") vec.push_back(Log(action, id));
    }
   
   for(int i=0; i<vec.size(); i++) {
       string action = vec[i].action;
       string id = vec[i].id;
       if(action == "Enter") answer.push_back(m[id] + "님이 들어왔습니다.");
       else  answer.push_back(m[id] + "님이 나갔습니다.");
   }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    solution(record);
    return 0;
}
