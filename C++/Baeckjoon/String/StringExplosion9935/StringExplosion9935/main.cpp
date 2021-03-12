//
//  main.cpp
//  StringExplosion9935
//
//  Created by 조윤영 on 2021/03/12.
//

#include <iostream>
using namespace std;
string solution(string word, string bomb);
void input() {
    string N, M;
    cin>> N;
    cin>> M;
    cout<<solution(N, M)<<"\n";
}

string solution(string word, string bomb) {
    string answer = "";
    string temp = word;
    
    for(int i=0; i<temp.size(); i++) {
        answer += temp[i];
        if(answer[answer.length() - 1] == bomb[bomb.length() - 1]) {
            if(answer.length() < bomb.length()) continue;

            if(answer.substr(answer.length()-bomb.length(), bomb.length()) == bomb) {
                for(int b=0; b<bomb.length(); b++) answer.pop_back();
                //string도 pop_back, push_back이 된다
            }
        }
    }
    if(answer.empty()) return "FRULA";
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}
