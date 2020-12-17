//
//  main.cpp
//  FindArchorPoint
//
//  Created by 조윤영 on 2020/08/26.
//  Copyright © 2020 조윤영. All rights reserved.
//
//고정점 찾기
//

#include <iostream>
#include <vector>
using namespace std;

int N = 0;
vector<int> list;
void input() {
    cin>> N;
    list.assign(N, 0);
    for(int i=0; i<N; i++) cin>> list[i];
}

int solution() {
    int i = 0;
    int j = N-1;
    int mid = (i+j)/2;
    
    while(i<=j)  {
        mid = (i+j)/2;
        if(mid == list[mid]) return mid;
        else if(mid > list[mid]) {
            i = mid +1;
            continue;
        } else { //mid < list[mid]
            j = mid -1;
            continue;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution()<<"\n";
    return 0;
}
