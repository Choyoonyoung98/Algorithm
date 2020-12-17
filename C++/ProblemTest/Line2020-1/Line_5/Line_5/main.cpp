//
//  main.cpp
//  Line_5
//
//  Created by 조윤영 on 06/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;


vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    vector<string> answer;
    map<string,int> m;
    map<int,string> m_cnt;
    
    
    for(int i=0; i<tags.size(); i++) {
        string tag = tags[i];
        for(int j=0; j<dataSource.size(); j++) {
            string docName = dataSource[j][0];
            for(int h=0; h<dataSource[j].size(); h++) {
                if(dataSource[j][h] == tags[i])m[docName]++;
            }
            m_cnt[m[docName]] = docName;
        }
    }
    
    vector<vector<string>> temp;
    temp.assign(100, {});
    
    
    for(int i=0; i<dataSource.size(); i++) {
        string docName = dataSource[i][0];
        temp[m[docName]].push_back(docName);
    }
    

    for(int i=temp.size()-1; i>0; i—) {
        for(int j=0; j<temp[i].size(); j++) {
            answer.push_back(temp[i][j]);
        }
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
