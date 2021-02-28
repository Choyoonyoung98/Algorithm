//
//  main.cpp
//  CheatingChecker_Line2020_1
//
//  Created by 조윤영 on 2021/02/26.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(string answer_sheet, vector<string> sheets) {
    int answer = 0;
    int N = answer_sheet.size();
    for(int i=0; i<sheets.size()-1; i++) {
        for(int j=1; j<sheets.size(); j++) {

            int cnt = 0;
            int maxLength = 0;
            int length = 0;
            if(i == j) continue;
            for(int k=0; k<N; k++) {
                int a = sheets[i][k] - '0';
                int b = sheets[j][k] - '0';
                if(a == b && a != answer_sheet[k] - '0') {
                    cout<<a<<endl;
                    cnt ++;
                    maxLength = max(maxLength, ++length);
                } else {
                    length = 0;
                }
            }
            int result = cnt + pow(maxLength, 2);
            answer = max(answer, result);
        }
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    string answer_sheet = "24551";
    vector<string> sheets = {"24553", "24553", "24553", "24553"};
    cout<<solution(answer_sheet, sheets)<<endl;
    return 0;
}
