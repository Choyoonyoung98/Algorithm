//
//  main.cpp
//  String1120
//
//  Created by 조윤영 on 2021/03/09.
//

#define MAX_SIZE 51
#include <iostream>
#include <cmath>
using namespace std;
string A, B;
void input() {
    cin>> A >> B;
}

int calculateDiff(string a, string b) {
    int result = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) result ++;
    }
    return result;
}

int solution() {
    int answer = MAX_SIZE;

    string shorterString = (A.size() > B.size()) ? B : A;
    string longerString = (A.size() > B.size()) ? A : B;
    for(int i=0; i <= longerString.size() - shorterString.size(); i++) {
        string a = longerString.substr(i, shorterString.size());
        answer = min(answer, calculateDiff(a, shorterString));
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}
