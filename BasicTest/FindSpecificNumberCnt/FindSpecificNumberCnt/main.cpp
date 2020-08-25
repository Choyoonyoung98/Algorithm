//
//  main.cpp
//  FindSpecificNumberCnt
//
//  Created by 조윤영 on 2020/08/25.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int N = 0;
int x = 0;
vector<int> list;
void input() {
    cin>> N >> x;
    int numb = 0;
    for(int i=0; i<N; i++) {
        cin>> numb;
        list.push_back(numb);
    }
}

int solution() {
    int answer = 0;
    int left = 0;
    int right = N-1;
    int mid = (left + right) / 2;
    
    while(left <= right) {
        mid = (left + right) / 2;
        if (list[mid] < x) left = mid + 1;
        else if(list[mid] > x) right = mid - 1;
        else { //list[mid] == x
            answer++;
            int i  = mid - 1;
            int j = mid + 1;
            while(list[i] == x) {
                i--;
                answer++;
            }
            while(list[j] == x) {
                j++;
                answer++;
            }
            break;
        }
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
