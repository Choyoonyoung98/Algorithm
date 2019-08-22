//
//  main.cpp
//  SetMap
//
//  Created by 조윤영 on 26/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
//중복을 허용하는 multiSet과 multiMap

template <typename k>
void print_set(std::multiset<k>& s) {
    for(const auto& elem : s) {
        cout<<elem<<endl;
    }
}
template <typename K,typename V>
void print_map(std::multimap<K,V>& m) {
    for(const auto& kv : m) {
        cout<<kv.first<<" "<<kv.second<<endl;
    }
}

int main(int argc, const char * argv[]) {
    
    /*multiset*/
    std::multiset<std::string> s;
    
    s.insert("d");
    s.insert("d");
    s.insert("c");
    s.insert("b");
    s.insert("a");
    
    print_set(s);
    
    /*multimap*/
    std::multimap<int, string> m;
    m.insert(pair<int,string>(1,"hello"));
    m.insert(std::make_pair(1,"bye"));
    m.insert(std::make_pair(2,"bye2"));
    m.insert(std::make_pair(2,"bye3"));
    //    m[1]="baba"; multimap에서는 되지 않는다.왜? hello를 반환할지, bye를 반환할지 판단할 수 없기 때문.
    
    print_map(m);
    cout<<"========================="<< endl;
    //특정값에 대응되는 값들에 대해서 확인할 경우
    auto range = m.equal_range(1);
    for(auto itr = range.first; itr !=range.second; ++itr) {
        cout << itr->first << " : " <<itr->second << " "<<endl;
    }
    
    
    
    return 0;
}

