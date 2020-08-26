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
    int answer = -1;
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

int findStartIndex(int start, int end) {
    if(start > end) return -1;
    int mid = (start + end)/2;
    
    if((mid == 0 || x > list[mid-1]) && list[mid] == x) return mid; //두 번째 조건은 가장 왼쪽에 있는 인덱스를 구하기 위해.
    else if(list[mid]>= x) return findStartIndex(start, mid-1);
    else return findStartIndex(mid+1, end); //list[mid] < x
    return -1;
}

int findEndIndex(int start, int  end) {
    if(start > end) return -1;
    int mid = (start + end) /2;

    if((mid == end || x < list[mid+1]) && list[mid] == x) return mid; //두 번째 조건은 가장 왼쪽에 있는 인덱스를 구하기 위해.
    else if(list[mid]> x) return findStartIndex(start, mid-1);
    else return findEndIndex(mid+1, end); //list[mid] < x
    return -1;
}

int solution2()  {
    int startIndex = findStartIndex(0, N-1);
    if(startIndex == -1) return -1;
    int endIndex = findEndIndex(0, N-1);
    return endIndex - startIndex  + 1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
//    cout<<solution2()<<"\n";
    return 0;
}

/*
7 4
 1 1 2 2 2 2 3
 */
