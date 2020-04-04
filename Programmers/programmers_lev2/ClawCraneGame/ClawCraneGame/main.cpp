//
//  main.cpp
//  ClawCraneGame
//
//  Created by 조윤영 on 04/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> basket;
    
    for(int i=0; i<moves.size(); i++) {
        
        int position = moves[i]-1;
        
        for(int j=0; j<board.size(); j++) {
            if(board[j][position]!=0) {
                //비어있지않다면,
                int doll = board[j][position];
                
                if(!basket.empty() && (basket.top() == doll)){
                    basket.pop();
                    answer+=2;
                }else{
                    basket.push(doll);
                }
                
                board[j][position] = 0;
                break;
                
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    /*
     0,0,0,0,0
     0,0,1,0,0
     0,2,5,0,1
     0,2,4,4,2
     3,5,1,3,1
     */
    
    cout<<solution(board, moves);
    return 0;
}

