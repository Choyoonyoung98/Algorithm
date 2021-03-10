//
//  main.cpp
//  Suffix11656
//
//  Created by 조윤영 on 2021/03/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string S;
void input() {
    cin>> S;
}

void solution() {
    vector<string> answer;
    string temp = "";
    for(int i=S.size()-1; i>=0; i--) {
        temp = S[i] + temp;
        answer.push_back(temp);
    }
    
    sort(answer.begin(), answer.end());
    for(string a: answer)cout<<a<<"\n";
}

int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}
