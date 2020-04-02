//
//  main.cpp
//  TravelRoute
//
//  Created by 조윤영 on 29/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& travel_route, int cnt) {

    travel_route.push_back(from);

    if (cnt == tickets.size()) {
        answer = travel_route;
        return true;
    }

    for (int i=0 ; i<tickets.size() ; i++) {
        if (tickets[i][0] == from && visited[i] == false) {
            visited[i] = true;

            bool success = dfs(tickets[i][1], tickets, visited, travel_route, cnt+1);
            
            if (success)
                return true;
            
            visited[i] = false;
        }
    }
    travel_route.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> temp;
    vector<bool> visit(tickets.size(), false);

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, visit, temp, 0);

    return answer;
}


int main() {
    vector<vector<string>> tickets = {{"ICN", "COO"},{"ICN","BOO"},{"COO","ICN"},{"BOO","DOO"}};
    
    solution(tickets);
    
    return 0;
}






/*-----------------------------------*/
//모든 항공을 방문하지 않는 solution
/*-----------------------------------*/
vector<string> answer2;
int visited[MAX_SIZE] = {false};

vector<int> sourceCandidateIndex;
int sourceIndex = 0;
string lastDestination;

void dfs(vector<vector<string>> tickets, int index) {
    

    string currentIndex = tickets[index][0];
    lastDestination = tickets[index][1];
    visited[index] = true;
    answer2.push_back(currentIndex);
    
    string targetIndex = tickets[index][1];
        
    //출발점 후보들을 모색하고,
    for(int i=0; i<tickets.size(); i++) {
        string source = tickets[i][0];
        if( (source == targetIndex) && visited[i] !=true) sourceCandidateIndex.push_back(i);
    }
        
    if(sourceCandidateIndex.empty())return;
    else if(sourceCandidateIndex.size()==1)sourceIndex = sourceCandidateIndex[0];
    else{
        sourceIndex = sourceCandidateIndex[0];
        //후보들 중에 알파벳 순서가 앞서는 경로를 출발점을 선택한다.
        for(int i=1; i<sourceCandidateIndex.size(); i++){
            int idx = sourceCandidateIndex[i];
            if(tickets[idx][1] < tickets[sourceIndex][1]) {
                sourceIndex = index;
            }
        }
    }

    sourceCandidateIndex.clear();
    dfs(tickets, sourceIndex);
    return;
    
}

vector<string> solution2(vector<vector<string>> tickets) {
    
    
    //출발점 후보들을 모색하고,
    for(int i=0; i<tickets.size(); i++) {
        string source = tickets[i][0];
        if( source == "ICN") sourceCandidateIndex.push_back(i);
    }
    
    //후보들 중에 알파벳 순서가 앞서는 경로를 출발점을 선택한다.
    for(int i=1; i<sourceCandidateIndex.size(); i++){
        int pos = sourceCandidateIndex[i];
        if(tickets[pos][1] <tickets[sourceIndex][1]) sourceIndex = pos;
    }
    
    sourceCandidateIndex.clear();
    dfs(tickets, sourceIndex);
    answer2.push_back(lastDestination);
    return answer2;
}

