//
//  main.cpp
//  UnfinishedPlayer
//
//  Created by 조윤영 on 31/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
 
 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.*/

using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    for(typename vector<T> ::iterator itr = vec.begin(); itr!=vec.end(); itr++) {
        cout<<*itr<<endl;
    }
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<int> visit(completion.size(), 0);//완주한 선수에 대해서 매칭을 이미 했는지 여부를 1,0으로 저장

    for(vector<int>::size_type i=0; i<participant.size(); i++) {

        auto currentR = completion.begin();
        auto findResult =  find(currentR, completion.end(), participant[i]);
        if(findResult !=completion.end()){ //competion에 participant에 있는 선수가 존재한다면,
            
            /*동명이인의 선수가 참여하였을 경우,*/
            if(visit[distance(currentR, findResult)] ==1){//그리고 그 competion이 paricipant에 있는 선수와 매칭되어 확인된 적이 있다면,
                cout<<participant[i];
                answer = participant[i];
                break;
            }
            else{//그리고 그 competion이 paricipant에 있는 선수와 매칭되어 확인된 적이 없다면,
                visit[distance(currentR, findResult)]=1;
            }

        }else{//competion에 participant에 있는 선수가 존재하지 않는다면,
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}

string solution2(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    for(int i = 0, max = completion.size(); i < max; i++){
        
        if(participant[i] != completion[i])
            return participant[i];
    }
    
    return participant[participant.size() - 1];
}

int main(int argc, const char * argv[]) {
    
    vector<string> participant;
    participant.push_back("leo");
     participant.push_back("kiki");
     participant.push_back("eden");

    vector<string> completion;
    completion.push_back("eden");
    completion.push_back("kiki");

    /*vector로 알고리즘 짜기(비효율적 코드)*/
    cout<<solution(participant, completion)<<endl;;
    
    //비효율의 끝판왕을 경험하고
    /*vector로 알고리즘 짜기(효율적 코드)*/
    cout<<solution2(participant, completion)<<endl;
    
    
    return 0;
}
