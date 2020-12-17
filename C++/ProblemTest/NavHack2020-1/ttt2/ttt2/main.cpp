//
//  main.cpp
//  ttt2
//
//  Created by 조윤영 on 11/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> id_list, int k) {
    int answer = 0;
    
    map<string,int> member_map;

    for(int i=0; i<id_list.size(); i++) {
        
        string members = id_list[i];
        string member;
        map<string,bool> member_visited;//조건:하루에 최대 1장씩 발급 - 해당 날짜에 중복 방문했는지 확인
        
        for(int j=0; j<=members.size(); j++) {
            
            //공백 기준으로 자른다.
            if(members[j] == 32 || (j == members.size())) {
                
                if(!member_visited[member] && member_map[member] <k) {//해당 멤버가 가지고 있는 쿠폰의 수가 K개보다 작다면
                    member_map[member]++;
                    member_visited[member] = true;
                    answer++;
                }
                member = ""; //초기화
                
            }else{
                member+=members[j];
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<string> id_list = {"A B C D", "A D", "A B D", "B D"};
    solution(id_list, 2);
    
    return 0;
}
