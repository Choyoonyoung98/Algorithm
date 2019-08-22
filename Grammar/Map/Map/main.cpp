//
//  main.cpp
//  SetMap
//
//  Created by 조윤영 on 26/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

//Set의 경우에는 *itr가 저장된 원소를 바로 가리켰는데, Map의 경우에는 std::pair객체를 가리키게 되므로 itr->first, itr->second로 해당 원소 값을 알아낼 수 있음.
template <typename K, typename V>
void print_map(std::map<K, V>& m) {
    for(auto itr = m.begin(); itr !=m.end(); ++itr) {
        cout<<itr->first<<" " <<itr->second <<endl;
    }
}

template <typename K, typename V>
void print_map2(const std::map<K,V>& m) {
    for(const auto& kv:m) {
        cout<<kv.first <<" "<<kv.second <<endl;
    }
}

template <typename K, typename V>
void search_and_print(std::map<K,V>& m, K key) {
    auto itr = m.find(key);
    if(itr != m.end()) {
        cout<<itr->second<<endl;
    }else{
        cout<<key<<"은 목록에 없습니다."<<endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::map<std::string, double> pitcher_list;
    
    /*추가방법-1*/
    //<키의 타입, 갑의 타입>
    //pairt은 그냥 단순히 2개의 객체를 멤버로 가지는 객체
    pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("해커", 2.93));
    pitcher_list.insert(std::pair<std::string, double>("피어밴드", 2.93));
    
    //타입을 지정하지 않아도 간단히 std::make_pair 함수로
    // std::pair 객체를 만들 수 도 있습니다.
    /*추가방법-2(추천)*/
    pitcher_list.insert(std::make_pair("차우찬", 3.04));
    pitcher_list.insert(std::make_pair("장원준 ", 3.05));
    pitcher_list.insert(std::make_pair("헥터 ", 3.09));
    pitcher_list.insert(std::make_pair("류현진 ", 3.09));
    
    /*추가방법-3*/
    pitcher_list["니퍼트"] = 3.36;
    pitcher_list["박종훈"]=3.76;
    
    
    
    print_map(pitcher_list);
    print_map2(pitcher_list);
    
    //해당 키값이 없어도 0 반환....
    cout<<"박세웅 방어율은?"<<pitcher_list["박세웅"]<<endl;
    
    //double 의 디폴트 생성자의 경우 그냥 변수를 0 으로 초기화 해버립니다. 따라서 되도록이면 find 함수로 원소가 키가 존재하는지 먼저 확인 후에, 값을 참조하는 것이 좋습니다. 아래는 find 함수를 이용해서 안전한게 키에 대응되는 값을 찾는 방법입니다.
    search_and_print(pitcher_list, string("오승환"));
    
    //map 역시 set과 마찬가지로 중복 허용 X
    
    
    
    return 0;
}
