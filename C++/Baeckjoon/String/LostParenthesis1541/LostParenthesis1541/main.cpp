//
//  main.cpp
//  LostParenthesis1541
//
//  Created by 조윤영 on 2021/03/06.
//

#include <iostream>
#include <vector>
using namespace std;

string word = "";
void input() {
    cin>> word;
}

int solution() {
    int answer = 0;
    int sum = 0;
    bool isMinusExist = false;
    for(int i=0; i<=word.size(); i++) {
        char w = '.';
        if(i<word.size()) w = word[i];
        if(w == '-' || w == '+' || i == word.size() ) {
            if(isMinusExist) answer -= sum;
            else answer += sum;
            
            sum = 0;
            if(w == '-') isMinusExist = true;
        } else {
            sum *= 10;
            sum += w - '0';
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution()<<endl;
    return 0;
}
