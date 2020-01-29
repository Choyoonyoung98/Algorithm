//
//  main.cpp
//  OpenChattingRoom
//
//  Created by 조윤영 on 21/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
/*
 istringstream를 이용하면 공백을 token으로 분리할 수 있습니다.
 istringstream iss(record[i]);
 iss >> log[i][0];
 iss >> log[i][1];
 iss >> log[i][2];
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> log(record.size(), vector<string>(3));
    //{{"","",""},{},{}}
    map<string,string> user;
    
    for(int i=0; i<record.size(); i++) {
        
        //istringstream를 이용하면 공백을 token으로 분리할 수 있습니다.
        istringstream iss(record[i]);
        iss >> log[i][0];
        iss >> log[i][1];
        iss >> log[i][2];
        
        string status = log[i][0];
        string userId = log[i][1];
        string userName = log[i][2];
        
        if(status == "Enter" || status =="Change") {
            user[userId] = userName;
        }
    }
    
    for(int i=0; i<log.size(); i++) {
        
        string status = log[i][0];
        string userId = log[i][1];
        string userName = log[i][2];
        
        if(log[i][0] == "Enter")answer.push_back(user[userId] +"님이 들어왔습니다.");
        else if (log[i][0] == "Leave")answer.push_back(user[userId] + "님이 나갔습니다.");

    }
    
    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i];
    }
    return answer;
}










//나의 풀이, 하지만 무언가 문제가 있는지 프로그래머스에서는 돌아가지 않음
vector<vector<string>> seperateRecord;

void seperateSentence(vector<string> &record) {
    
    for(int i=0; i<record.size(); i++) {
        string word;

        for(int j=0; j<record[i].size(); j++) {
            
            if(record[i][j] == ' '){
                seperateRecord[i].push_back(word);
                word="";
            }else{
                word += record[i][j];
                if(j == record[i].size()-1)seperateRecord[i].push_back(word);
            }
        }
    }
    
}

vector<string> solution2(vector<string> record) {
    vector<string> answer;
    vector<string> temp;
    
    seperateRecord.assign(record.size(), {});
    seperateSentence(record);
    
    string tempSentence;
    for(int i=0; i<seperateRecord.size(); i++) {
        string status = seperateRecord[i][0];
        string userId = seperateRecord[i][1];
        string userName = seperateRecord[i][2];
        
        if(status == "Change") {
            for(int j = 0; j<i; j++) {
                if(seperateRecord[j][1] == userId){
                    seperateRecord[j][2] = userName;
                }
            }
        }else if(status == "Leave") {
            for(int j = i-1; j>=0; j--) {
                if(seperateRecord[j][1] == userId){
                    seperateRecord[i].push_back(seperateRecord[j][2]);
                    break;
                }
            }
        }else{//Enter
            for(int j = i-1; j>=0; j--) {
               if(seperateRecord[j][0] == "Enter" || seperateRecord[j][0] == "Leave")
                   if(seperateRecord[j][1] == userId){
                   seperateRecord[j][2] = userName;
               }
            }
        }
    }
    
    for(int i=0; i<seperateRecord.size(); i++) {
        string status = seperateRecord[i][0];
        string userId = seperateRecord[i][1];
        string userName = seperateRecord[i][2];
        
        if(status == "Change")continue;
        else if(status == "Enter") answer.push_back(userName + "님이 들어왔습니다.");
        else if(status == "Leave") answer.push_back(userName + "님이 나갔습니다.");
        else {}
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    solution(record);
    return 0;
}
