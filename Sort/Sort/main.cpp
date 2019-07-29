//
//  main.cpp
//  Sort
//
//  Created by 조윤영 on 29/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
/*sort함수는 오직 벡터와 데크에서만 가능하다.*/
template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout <<*begin << " " ;
        begin++;
    }
    cout<<endl;
}
struct int_compare {
    bool operator()(const int& a, const int& b) const { return a > b; }
};
int main(int argc, const char * argv[]) {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(2);

    /*default*/
    print(vec.begin(), vec.end());
    
    /*오름차순*/
    std::sort(vec.begin(), vec.end());
    print(vec.begin(), vec.end());
    
    /*내림차순1*/
    std::sort(vec.begin(), vec.end(), int_compare());
    print(vec.begin(), vec.end());
    /*내림차순2: 사실 따로 함수를 만들 필요는 없다.*/
    std::sort(vec.begin(), vec.end(), greater<int>());
    print(vec.begin(), vec.end());
    
    /*partial_sort :부분 정렬*/
    //std::partial_sort(start, middle, end)
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());//3번째까지 가장 작은 애들만 순서대로 저장하고 나머지 위치는 상관없다!
    print(vec.begin(), vec.end());
    
    
    return 0;
}
