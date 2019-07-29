//
//  main.cpp
//  Find
//
//  Created by 조윤영 on 29/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    /*find:first 부터 last 까지 쭈르륵 순회하면서 value 와 같은 원소가 있는지 확인하고 있으면 이를 가리키는 반복자를 리턴*/
    //find(InputIt first, InputIt last, const T& value)
    //forward_iterator 면 앞에서 부터 찾고, reverse_iterator 이면 뒤에서 부터 거꾸로 찾게 됩니다.
    auto result = find(vec.begin(), vec.end(), 3);
    
    //distance: 처음부터 특정 위치까지의 거리를 계산
    cout<<"3은"<<distance(vec.begin(), result)+1 <<"번쨰 원소"<<endl;
    
    //특정 값에 대한 모든 원소를 찾고싶다면?
    auto current = vec.begin();
    while (true) {
        current = std::find(current, vec.end(), 3);
        if (current == vec.end()) break;
        //위치 호출 가능
        std::cout << "3 은 " << std::distance(vec.begin(), current) + 1
        << " 번째 원소" << std::endl;
        current++;
    }
    current = vec.begin();
        //특정 조건으로 모든 원소를 찾고싶다면?
        while (true) {
            current = std::find_if(current, vec.end(), [](int i) { return i % 3 == 2; });
            if (current == vec.end()) break;
            //값 호출 가능
            std::cout << "3 으로 나눈 나머지가 2 인 원소는 : " << *current << " 이다 "
            << std::endl;
            current++;
        }
        

    
    return 0;
}
