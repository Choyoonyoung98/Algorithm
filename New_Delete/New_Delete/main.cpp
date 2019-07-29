//
//  main.cpp
//  Cgrammar_3
//
//  Created by 조윤영 on 14/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    /*1:new & delete
     메모리를 관리하는 문제는 언제나 중요한 문제입니다. 프로그램이 정확하게 실행되기 위해서는 컴파일 시에 모든 변수의 주소값이 확정되어야만 했습니다.
     하지만, 이를 위해서는 프로그램에 많은 제약이 따르기 때문에 프로그램 실행 시에 자유롭게 할당하고 해제할 수 있는 힙(heap) 이라는 공간이 따로 생겼습니다.
     
     하지만 이전에 컴파일러에 의해 완벽히 확정되어 안정성이 보장되는 스택(stack) 과는 다르게 힙은 사용자가 스스로 제어해야 하는 부분인 만큼 책임이 따릅니다.
     
     C 언어에서는 malloc 과 free 함수를 지원하여 힙 상에서의 메모리 할당을 지원하였습니다. C++ 에서도 마찬가지로 malloc 과 free 함수를 사용할 수 있습니다.
     
     */
    int* p = new int; //new: int 크기의 공간을 할당하여, 그 주소갑에 p에 집어넣음.
    *p = 10;//해당 공간에 10이라는 값을 집어넣음.
    
    std::cout << *p << std::endl;
    
    delete p;//delete: 할당된 공간 해제
    
    /*2: new로 배열 할당 . delete로 배열 공간 해제 */
    /*new - delete 가 짝을 이루고 new [] 와 delete [] 가 짝을 이루는 것.*/
    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;
    
    int *list = new int[arr_size];
    
    for(int i=0; i<arr_size; i++) {
        std::cin >> list[i];
    }
    for(int i=0; i<arr_size; i++) {
        std::cout << i << "the element of list: " << list[i] <<std::endl;
    }
    delete[] list;
    
    
    /*3:변수의 결과  */
    /*3-1*/
    {
        int a = 4;
        std::cout << "안에서 a : " << a;
    }
    
    //    std::cout << "밖에서 a : " << a; //오류가 나게 된다.
    
    /*3-2: 어떤 변수를 사용할 때 컴파일러는 그 변수를 가장 가까운 범위(scope) 부터 찾게 됩니다. */
    
    int a = 4;
    {
        std::cout << "외부의 변수 1" << a << std::endl; //4
        int a = 3;
        std::cout << "내부의 변수 " << a << std::endl; //3
    }
    
    std::cout << "외부의 변수 2" << a << std::endl; //4
    
    
    return 0;
}
