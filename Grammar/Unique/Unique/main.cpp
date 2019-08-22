//
//  main.cpp
//  Unique
//
//  Created by 조윤영 on 10/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    
    cout<<endl;
}




int main()
{
    vector<int>vec {1,2,1,3,1,2};
    
    /*정렬되지 않은 벡터배열*/
    print(vec.begin(), vec.end());
    
    /*정렬*/
    sort(vec.begin(), vec.end());
    print(vec.begin(), vec.end());
    
    
    /*중복 제거*/
    vec.erase(unique(vec.begin(),vec.end()),vec.end());//여기!!
    print(vec.begin(), vec.end());
}
