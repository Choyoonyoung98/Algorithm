//
//  main.cpp
//  FindNumber_1920
//
//  Created by 조윤영 on 01/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//이진법
//https://www.acmicpc.net/problem/1920

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 100001

using namespace std;

vector<int> numb_list;
vector<int> q_numb_list;

int N = 0;
int M = 0;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    int numb = 0;
    
    for(int i=0; i<N; i++) {
        cin>>numb;
        numb_list.push_back(numb);
    }
    
    cin>>M;
    
    int qNumb = 0;
    
    for(int i=0; i<M; i++) {
        cin>>qNumb;
        q_numb_list.push_back(qNumb);
    }
    
}
void solution() {
    
    //오름차순 정렬
    sort(numb_list.begin(), numb_list.end());
    
    for(int i=0; i<q_numb_list.size(); i++) {
        int min = 0;
        int max = numb_list.size()-1;

        int mid = (min+max)/2;
        bool find = false;
        
        while(min<=max) {
            mid = (max+min)/2;
//            cout<<"["<<mid<<"]"<<endl;
            if(numb_list[mid]<q_numb_list[i]){
                min = mid +1;
            }else if(numb_list[mid]>q_numb_list[i]) {
                max = mid-1;
            }else{ //mid == q_numb_list[i]
                cout<<1<<" ";
                find = true;
                break;
            }
        }
        
        if(!find)cout<<0<<" ";
    }
    cout<<"\n";
    
}

int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}
