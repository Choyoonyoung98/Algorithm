//
//  main.cpp
//  Remove
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
struct is_odd {
    int num_delete;
    
    is_odd(): num_delete(0){}
    
    bool operator()(const int& i) {
        if(num_delete >=2)return false;
        
        if(i%2==1) {
            num_delete++;
            return true;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    print(vec.begin(), vec.end());
    
    /*remove는 벡터 뿐만 아니라 리스트, set, map 등에서 모두 사용 가능하다.*/
    /*특정 값을 모두 삭제하려면*/
    vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
    print(vec.begin(), vec.end());
    
    /*특정 조건의 원소들을 모두 삭제하려면*/
    //람다함수의 꼴: [](int i) -> bool { return i % 2 == 1; }
    //[capture list] (받는 인자) -> 리턴 타입 { 함수 본체 }
    //[capture list] ( 받는 인자) {함수 본체}:리턴타입이 bool
    
    int num_erased = 0;
    vec.erase(remove_if(vec.begin(), vec.end(),
                        [&num_erased](int i){
                            if(num_erased >=2) {
                                return false;
                                
                            }else if(i %2 == 1){
                                num_erased++;
                                return true;
                            }
                            return false;
                        }),
              vec.end());
    print(vec.begin(), vec.end());
    
    /*원소들의 수정*/
    //각 원소들을 모두 1씩 더한다.
    //transform (시작 반복자, 끝 반복자, 결과를 저장할 컨테이너의 시작 반복자, Pred)
    std::transform(vec.begin(), vec.end(), vec.begin(),
                   [](int i){return i+1;});
    print(vec.begin(), vec.end());
    
    /*vec전체에 1 더한 결과를 vec2에 저장.*/
    std::vector<int> vec2(6,0);//6개의 공간을 만들어 0으로 초기화
    print(vec2.begin(), vec2.end());
    
    std::transform(vec.begin(), vec.end(), vec2.begin(),
                   [](int i){return i+1;});
    cout<<"vec2:";    print(vec2.begin(), vec2.end());

    
    //
    
    return 0;
}
