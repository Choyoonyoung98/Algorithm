//
//  main.cpp
//  Vector_2
//
//  Created by 조윤영 on 31/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T>&  vec) {
    for(typename std::vector<T>::iterator itr = vec.begin(); itr !=vec.end(); ++itr) {
        cout<<*itr<<endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
    for(const auto& elem:vec) {
        cout<<elem <<endl;
    }
}


int main(int argc, const char * argv[]) {

    vector<int> vec;
    
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
     vec.push_back(40);
    
    for(vector<int>::size_type i=0; i<vec.size(); i++) {
        cout<<"vec의 "<<i+1<<"번째 원소:"<<vec[i] <<endl;
    }
    vector<int>::iterator itr = vec.begin() +2;
    cout<<"3 번재 원소:: "<<*itr <<endl;
    
    cout<<"============================"<<endl;
    print_vector(vec);
    vec.insert(vec.begin()+2, 15);
    vec.erase(vec.begin()+3);//remove함수 사용해야 한다.
    print_vector(vec);
    
    cout<<"============================"<<endl;
    
    for (int elem : vec) {
        std::cout << "원소 : " << elem << std::endl;
    }
    cout<<"============================"<<endl;
    print_vector_range_based(vec);
    return 0;
}
