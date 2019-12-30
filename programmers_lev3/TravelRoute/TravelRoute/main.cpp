//
//  main.cpp
//  TravelRoute
//
//  Created by 조윤영 on 29/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include <map>
#define MAX_SIZE 100

using namespace std;
vector <int, string> candidateDestination;
vector<string> answer;
vector<int> visited(MAX_SIZE, false);

void dfs(vector<vector<string>> &tickets, int source) {
    answer.push_back(tickets[source][0]);
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[source][1] == tickets[i][0]) {
            candidateDestination.push_back(i);
        }
    }
    
    int destination = 0;
    for(int i=0; i<candidateDestination.size(); i++) {
        if(i==0)destination = candidateDestination[i];
        else destination = (destination>candidateDestination[i])? candidateDestination[i]: destination;
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    answer.push_back(tickets[0][1]);
    visited[0] = true;
    dfs(tickets, 0);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> tickets = {{"ICN","JFK"}, {"HND","IAD"},{"JFK","HND" }};
    solution(tickets);
    
    return 0;
}
