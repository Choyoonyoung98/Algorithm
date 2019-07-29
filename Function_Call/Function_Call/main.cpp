//
//  main.cpp
//  Cgrammar_2
//
//  Created by 조윤영 on 14/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>

void print_square(int arg);
void change_val1(int *p);
void change_val2(int &p);

int main(int argc, const char * argv[]) {
    /*1: 일반적인 함수 호출 방식*/
    //    int i=0;
    
    //    std::cout << "제곱할 수 ? : ";
    //    std::cin >> i;
    //    print_square(i);
    
    /*2: 레퍼런스 도입 함수 호출 방식*/
    int number = 5;
    
    std::cout << number << std::endl;
    change_val1(&number);
    std::cout << number << std::endl;
    change_val2(number);
    std::cout << number << std::endl;
    
    return 0;
}

void print_square(int arg) {
    std::cout << "전달된 인자: " <<  arg*arg  << std::endl;
}
void change_val1(int *p){
    *p=10;
}
void change_val2(int &p) {//레퍼런스를 이용 방식
    
    p=3;
}
