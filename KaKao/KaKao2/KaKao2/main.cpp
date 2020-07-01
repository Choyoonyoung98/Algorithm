//
//  main.cpp
//  KaKao2
//
//  Created by 조윤영 on 09/05/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int operators[3] = {'*','+','-'};

vector<int> myOperands;
vector<string> myOperators;
vector<int> combinations;
vector<string> orders;


void makeCombination(int n, int maxDepth, int depth) {
    if(depth == maxDepth) {
        string temp;
        for(int i=0; i<combinations.size(); i++) {
            temp += to_string(combinations[i]);
        }
        orders.push_back(temp);
        return;
        
    }
    
    for(int i=depth; i<n; i++) {
        swap(combinations[i], combinations[depth]);
        makeCombination(n, maxDepth, depth+1);
        swap(combinations[i], combinations[depth]);
    }
    
    return;
}

void seperateExpression(string expression) {
    string s_numb;
    for(char c: expression) {
        if(c == '*' || c == '+' || c == '-') {
            int i_numb = stoi(s_numb);
            myOperands.push_back(i_numb);
            string s_c;
            s_c.push_back(c);
            myOperators.push_back(s_c);
            s_numb = "";
        }else{
            s_numb += c;
        }
    }
}
long long solution(string expression) {
    long long answer = 0;
    
    seperateExpression(expression);
    
    myOperators.erase(unique(myOperators.begin(), myOperators.end()), myOperators.end());
    int operatorSize = myOperators.size();
    for(int i=0; i<myOperators.size(); i++) {
        
    }
    for(int i=0; i<operatorSize; i++) {
        combinations.push_back(i);
    }
    makeCombination(operatorSize,operatorSize, 0);
    
    for(int i=0; i<orders.size(); i++) {
        cout<<orders[i]<<endl;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    string expression = "100-200*300-500+20";
    solution(expression);
    return 0;
}

//100 - 200 * 300 - 500 + 20
//100 - 200 * 300 - 520
//-100 * -220
//22000
