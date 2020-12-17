//
//  main.cpp
//  OperatingTelescoping
//
//  Created by 조윤영 on 2020/08/23.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/14888
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 100000000
using namespace std;

int N = 0;
vector<int> numbs;
vector<int> operator_cnt(4, 0);
int maxAnswer = -MAX_SIZE;
int minAnswer = MAX_SIZE;

void input()  {
    cin>> N;
    for(int i=0; i<N; i++)  {
        int A = 0;
        cin>> A;
        numbs.push_back(A);
    }
    for(int i=0; i<4; i++) {
        cin>>operator_cnt[i];
    }
}

int calculate(int sum, int operator_type, int operand_index)  {
    switch(operator_type)  {
        case 0:
            sum += numbs[operand_index];
            break;
        case 1:
            sum -= numbs[operand_index];
            break;
        case 2:
            sum *= numbs[operand_index];
            break;
        case 3:
            sum /= numbs[operand_index];
            break;
        default:
            break;
    }
    return sum;
}

void DFS(int index, int sum) {
    if(index == numbs.size()) {
        maxAnswer = max(maxAnswer, sum);
        minAnswer = min(minAnswer, sum);
    }
    
    for(int i=0; i<4; i++) {
        if(operator_cnt[i] != 0) {
            operator_cnt[i]--;
            DFS(index+1, calculate(sum, i, index));
            operator_cnt[i]++;
        }
    }
}

//DFS
void solution() {
    DFS(1,numbs[0]);
    
    cout<<maxAnswer<<"\n";
    cout<<minAnswer<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    input();
    solution();
    return 0;
}
