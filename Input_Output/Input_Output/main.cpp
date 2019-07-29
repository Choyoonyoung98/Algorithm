//
//  main.cpp
//  Cgrammar_1
//
//  Created by 조윤영 on 08/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
/*아하 iostream이라는 헤더파일을 include하고 있구나~
 iostream 헤더 파일은 C++에서 표준 입출력에 필요한 것들을 포함하고 있다.
 C언어에서의 stdio.h와 비슷하다.
 */

using namespace std; //cout <<  "Hello, World!\n" ;;의 오류가 나지 않게끔 한다.
int user_input;  // 사용자 입력

int main(int argc, const char * argv[]) {
    /*1:출력
     std: C++표준 라이브러리의 모든 함수,객체 등이 정의된 이름 공간(namespace)
     std::cout란 std라는 이름 공간에 정의되어 있는 cout를 의미한다.
     만약, std::없이 그냥 cout라고 한다면 컴파일러가 cout를 찾지 못하므로 주의!!
     but 생략 가능, using namespace std; 선언할 경우!
     
     이외 namespace는 굳이 설정하지 않아도 된다.
     */
    std::cout <<  "Hello, World!" ;;
    
    cout <<  "Hello, World!" ;;//std 생략 가능
    std::cout <<  "Hello, World!" << std::endl;;//개행처리
    std::cout << "print1" << "print2" << "print3"; //연결해서 출력 가능
    std::cout << std::endl; //엔터 출력
    
    /*2:
     C 와 C++ 은 기본적인 문법 구조(조건문; if, else, switch, 제어문; for, whlie, break, continue 등등) 는   똑같다.
     but 변수의 경우, 기존의 C에서는 변수를 정의할 때 언제나 소스 맨 위부분에 선언을 하였으나
     C++에서는 변수의 선언이 반드시 최상단에 있어야 하는 것은 아니다.
     */
    
    /*3:
     입력
     C언어에서의 scanf는 int형태/char형태인지 등등에 따라 %d, %c냐로 구분하였는데
     C++에서는 변수를 보고 cin이 알아서 처리해준다.
     */
    std::cout << "입력 : ";
    std::cin >> user_input;
    
    return 0;
}
