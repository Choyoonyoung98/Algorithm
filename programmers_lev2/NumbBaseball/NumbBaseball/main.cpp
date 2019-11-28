/*
 질문한 세 자리의 수, 스트라이크의 수, 볼의 수를 담은 2차원 배열 baseball이 매개변수로 주어질 때, 가능한 답의 개수를 return 하도록 solution 함수를 작성해주세요.
 
 baseball :[[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]
 return 2 : (324, 328)
 
 ***숫자 야구의 주요 법칙 중 하나: 같은 숫자가 나오면 안되고, 0을 포함해서도 안된다***
 */
#include <string>
#include <vector>
#include <iostream>

bool isStrike(int i, int numb, int cnt);
bool isBall(int i, int numb, int cnt);
using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for(int i=123; i<=987; i++) {
        string temp = to_string(i);
        //제1규칙: 추리해야하는 숫자가 0을 포함해서는 안된다.
        if(temp.at(0) == '0' || temp.at(1) == '0' || temp.at(2) == '0') {
            continue;
        }
        
        //제2규칙: 같은 숫자가 나오면 안된다.
        if(temp.at(0) == temp.at(1) || temp.at(1) == temp.at(2) || temp.at(0) == temp.at(2)) {
            continue;
        }
        
        int check = 1; //Check 초기화
        
        for(int j=0; j<baseball.size(); j++) {
            if((!isStrike(i, baseball[j][0], baseball[j][1])) || (!isBall(i, baseball[j][0], baseball[j][2]))) {
                check =0;
            }
        }
        
        if(check !=0) answer++;
    }

        return answer;
}

bool isStrike(int i, int numb, int strike) {
    int num = 0;
    string si = to_string(i);
    string sNumb = to_string(numb);
    
    for(int j=0; j<si.size(); j++) {
        if(si[j] == sNumb[j]) num++;
    }
    if(num == strike)return true;
    else return false;
}

bool isBall(int i, int numb, int ball) {
    int num = 0;
    string si = to_string(i);
    string sNumb = to_string(numb);
    
    for(int j=0; j<si.size(); j++) {
        for(int k=0; k<sNumb.size(); k++) {
            if((j!=k)&&(si[j] == sNumb[k]))num++;
        }
    }
    
    if(num == ball)return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> vec{{123,1,1},{356,1,0},{327,2,0},{489,0,1}};
    cout<<solution(vec);
    return 0;
}
