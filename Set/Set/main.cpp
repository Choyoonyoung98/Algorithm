//
//  main.cpp
//  SetMap
//
//  Created by 조윤영 on 26/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

template <typename T>
void print_set(std::set<T>& s) {
    cout<<"[";
    for(typename std::set<T>::iterator itr = s.begin(); itr !=s.end(); ++itr) {
        cout<<*itr <<"";
    }
    cout<<"]"<<endl;
}

template <typename T, typename C>
void print_set2(std::set<T, C>& s) {
    // 셋의 모든 원소들을 출력하기
    for (const auto& elem : s) {
        std::cout << elem << " " << std::endl;
    }
}

class Todo {
    int priority;
    std::string job_desc;
    
public:
    Todo(int priority, std::string job_desc)
    : priority(priority), job_desc(job_desc) {}
    
    friend struct TodoCmp;
    
    friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};
struct TodoCmp {
    bool operator()(const Todo& t1, const Todo& t2) const {
        if (t1.priority == t2.priority) {
            return t1.job_desc < t2.job_desc; //사전 상 먼저 오는 것이 먼저 나오게 된다.
        }
        return t1.priority > t2.priority;
    }
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
    o << "[ 중요도: " << td.priority << "] " << td.job_desc;
    return o;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::set<int> s;
    s.insert(20);
    s.insert(20);
    s.insert(50);
    s.insert(10);
    s.insert(40);
    
    cout<<"순서대로 정렬되서 나온다, 중복된 원소를 허용하지 않는다."<<endl;
    print_set(s);
    
    cout<<"20이 s의 원소인가요?";
    auto itr = s.find(20);
    if(itr !=s.end()){//원소가 없다면 s.end() 리턴
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    cout<<"25가 s의 원소인가요?";
    itr = s.find(25);
    if(itr != s.end()) {
        cout<<"Yes";
    }else{
        cout<<"No"<<endl;
    }
    
    set<Todo, TodoCmp> todos;
    todos.insert(Todo(1,"농구하기"));
    todos.insert(Todo(2,"숙제하기"));
    todos.insert(Todo(3,"프로그래밍 하기"));
    todos.insert(Todo(4,"영화 보기"));
    print_set2(todos);
    
    cout<<endl;
    
    todos.erase(todos.find(Todo(2,"숙제하기")));
    print_set2(todos);
    
    return 0;
}
