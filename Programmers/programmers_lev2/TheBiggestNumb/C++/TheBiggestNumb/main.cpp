//
//  main.cpp
//  TheBiggestNumb
//
//  Created by 조윤영 on 11/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct numb_sort2 {
    bool operator()(const string& a, const string& b) const {
        for(int i=0; i<a.size();i++) {
            //같은 자리의 숫자가 더 클 경우 앞으로
            if(a[i]!='x'&& b[i]!='x'&&(a[i]-'0')>(b[i]-'0')) return a>b;

            //더 작을 경우 뒤로
            else if(a[i]!='x'&& b[i]!='x'&&(a[i]-'0')<(b[i]-'0')) return a>b;
            
            else if(a[i]=='x'&& b[i]!='x'){
                if(b[i] == '0')return a<b;
                else return a>b;
            }
           else if(a[i]!='x'&& b[i]=='x'){
               if(a[i] == '0')return a>b;
               else return a<b;
            }
           else {
               cout<<a<<":"<<a[i]<<"/"<<b<<":"<<b[i]<<endl;
               continue;
           }
        }
        
        return a>b;
    }
};

/*모든 케이스 통과하지 못한 내 풀이*/
string solution2(vector<int> numbers) {
    string answer = "";
    vector<string> s_numbers;
    
    //자릿수가 가장 긴 숫자가 앞으로 오도록 정렬
    sort(numbers.begin(), numbers.end(), greater<int>());
    
    //string으로 전환 후 string vector에 담아준다.
    //왜? string이 각 자리 수 비교하기에 더 편하기 때문에
    for(int i=0; i<numbers.size(); i++) {
        s_numbers.push_back(to_string(numbers[i]));
    }

    int maxLength = s_numbers[0].size();//최대 길이
    
    for(int i=0; i<s_numbers.size(); i++) {
        while(s_numbers[i].size() != maxLength){
            s_numbers[i]+='x';
        }
    }
    sort(s_numbers.begin(), s_numbers.end(), numb_sort2());
    
    
    for(int i=0; i<s_numbers.size(); i++) {
        s_numbers[i].erase(find(s_numbers[i].begin(), s_numbers[i].end(), 'x'));
    }
    
    for(int i=0; i<s_numbers.size(); i++) {
        answer+=s_numbers[i];
    }
    return answer;
}

/*------------------------------------------------*/
/*------------------------------------------------*/
/*------------------------------------------------*/

bool cmp(const string &a, const string &b) {
    return a+b>b+a ? true:false;
}

/*맥 빠지는 다른사람의 짧고 효율적인 풀이*/
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_answer;
    for(int i=0; i<numbers.size(); i++) {
        s_answer.push_back(to_string(numbers[i]));
    }
    sort(s_answer.begin(), s_answer.end(), cmp);
    
    for(string str: s_answer) {
        answer+=str;
    }

    if(answer[0] == '0')return "0";
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {3,30,34,5,9};
    cout<<solution(numbers);
    return 0;
}
