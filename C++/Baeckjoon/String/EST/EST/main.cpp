//
//  main.cpp
//  EST
//
//  Created by 조윤영 on 2020/11/22.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check1(string cardNumb) {
    int result = 0;
    int cnt = 16;
    for(char c: cardNumb) {
        if(48 <= c && c <= 57) { //숫자라면
            if(cnt %2 == 0) { //짝수라면
                int numb = c - '0';
                numb *= 2;
                
                if(numb >= 10) {
                    int a = numb % 10;
                    int b = numb / 10;
                    
                    result += (a+b);
                } else result += numb;
            }
            cnt--;
        }
    }
    return result;
}

int check2(string cardNumb) {
    int result = 0;
    int cnt = 16;
    for(char c: cardNumb) {
        if(48 <= c && c <= 57) { //숫자라면
            if(cnt %2 != 0) { //짝수라면
                int numb = c - '0';
                result += numb;
            }
            cnt--;
        }
    }
    
    return result;
}

bool checkNumberAvailable(string cardNumb) {
    if((check1(cardNumb) + check2(cardNumb)) % 10 == 0) return true;
    return false;
}

bool checkFormAvailable(string cardNumb) {
    if(cardNumb[4] == '-' && cardNumb.size() == 19) {
        //-로 연결된 형태
        for(int i=0; i<16; i++) {
            int numb = cardNumb[i];
            if(i == 4 || i == 9 || i == 14) {
                if(numb != '-') return false;
            } else {
                if(!(48 <= numb && numb <= 57)) return false;
            }
        }
    } else if(cardNumb.size() == 16) {
        //공백 없이 연결된 형태
        for(int i=0; i<16; i++) {
            int numb = cardNumb[i];
            if(!(48 <= numb && numb <= 57)) return false;
        }
    } else return false;
    return true;
}

vector<int> solution(vector<string> card_numbers) {
    vector<int> answer;
    
    for(int i=0; i<card_numbers.size(); i++) {
        string cardNumb = card_numbers[i];
        int result = 0;
        if(checkFormAvailable(cardNumb) && checkNumberAvailable(cardNumb)) result = 1;
        answer.push_back(result);
        cout<<result<<endl;;
    }

    return answer;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> card_numbers = {"3285-3764-9934-2453", "3285376499342453","3285-3764-99342453","328537649934245", "3285376499342459","3285-3764-9934-2452"};
    solution(card_numbers);
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
