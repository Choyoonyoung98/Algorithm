//
//  main.cpp
//  Cgrammar_10
//
//  Created by 조윤영 on 20/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

class String {
    char *str;
    int len;
    
public:
    String(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
    String(const char *s);
    String(const string &s);
    ~String();
    
    void add_string(const string &s);   // str 뒤에 s 를 붙인다.
    void copy_string(const string &s);  // str 에 s 를 복사한다.
    int length();                       // 문자열 길이 리턴
};

//문자열 교체하기(모든 문자열에 대해서)
string ReplaceAll(string &str, const string& from, const string& to) {
    size_t start_pos = 0;//string 처음부터 검사
    while((start_pos = str.find(from, start_pos)) != string::npos) //from을 찾을 수 없을 때까지
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); //중복 검사를 피하고 from.length() > to.length()인 경우를 위해서
    }
    return str;
}


int main(int argc, const char * argv[]) {
    /*String*/
    //[append]:추가하기.
    string myString="[base]";

    myString+="[연산자이용]"; //1.[연산자]를 이용하여 문자열 추가
    myString.append("[append함수이용]");//2.[append함수]를 이용하여 문자열 추가
    cout <<myString;
    cout <<endl;

    //[length, size]: 길이 구하기.
    string myString2 = "[length]";
    cout <<myString2<<"의 길이:" << myString2.length();//1.length()로 길이 구하기
    cout <<myString2<<"의 길이:" << myString2.size();//2.size()로 길이 구하기
    cout <<endl;

    //[at]:특정 위치 문자 받기
    string myString3 = "where am I";
    cout <<"2번째 위치의 문자는?" <<myString3.at(1);//char를 반환
    cout <<"2번째 위치의 문자는?" <<myString3[1];//at보다는 빠르지만 위험.범위 계산X
    cout <<endl;

    //[front]:맨 앞의 인자 받기
    cout <<"첫 번째 위치의 문자는?"<<myString3.front();
    cout <<endl;

    //[back]:마지막 인자 받기
    cout <<"마지막 위치의 문자는?"<<myString3.back();
    cout <<endl;

    //[push_back]:맨 뒤에 문자 더하기
    string backadd="testtest";
    backadd.push_back('b');
    cout <<"맨 뒤에 문자 더하면:"<<backadd<<endl;
    backadd.pop_back();
    cout <<"맨 뒤에 문자 빼면:"<<backadd<<endl;

    //[resize]:리사이징..string을 n만큼의 크기로 만든다.
    string resizeBase = "hahahahaha";
    cout <<"리사이징 전 결과:"<<resizeBase<<endl;
    resizeBase.resize(2);
    cout <<"리사이징 후 결과:"<<resizeBase<<endl;//ha
    resizeBase.resize(10, 'n');//char 형으로 추가해야하는 것 잊지말기
    cout <<"리사이징 후 결과:"<<resizeBase;//hannnnnnnn

    //오버해서 리사이징 하면 빈칸으로 채워진다.

    cout <<endl;

    //[중요!!!][capacity, shirink_to_fit]:메모리 최적화..낭비되고 있는 메모리를 줄이는 함수
    string basic ="yoonyoonyoonyoonyoonyoonyoonyoon";
    cout <<"basic capacity: "<<basic.capacity()<<endl;
    basic.resize(4);
    cout <<"리사이징 후, 최적화 X: "<<basic.capacity()<<endl;
    basic.shrink_to_fit();
    cout <<"리사이징 후, 최적화 O: "<<basic.capacity()<<endl;

    //[clear]:지우기
    string deleteTest ="yoonyoonyoonyoonyoonyoonyoonyoon";
    deleteTest.clear();
    cout <<deleteTest<<endl; //""

    //[empty]:비었는지 확인
    if(deleteTest.empty()) {

    }

    //[find]:특정 문자 탐색
    string myString4 = "[Finding Jenny]";
    string finding = "Jenny";
    string findResult1 = "";
    string findResult2 = "";
    int  findingLength = finding.length();
    cout <<finding<<"의 위치는?" <<myString4.find("Jenny");
    cout <<endl;
    cout <<"5번째 이후로 찾는 Jenny의 위치는?" <<myString4.find("Jenny", 5);
    cout <<endl;


    //탐색한 문자 결과 확인하기1
    int start = myString4.find("Jenny");

    for(int i=0; i<findingLength; i++) {
        findResult1 +=myString4.at(start);
        start++;
    }
    cout << "1번 탐색으로 찾은 결과:" <<findResult1;
    cout <<endl;
    //탐색한 문자 결과 확인하기2:substr...index에서부터 len만큼 잘라서 반환
    start = myString4.find("Jenny");
    findResult2 = myString4.substr(start, findingLength);
    cout << "2번 탐색으로 찾은 결과:" <<findResult2;
    cout <<endl;

    //복사
    string copyString = "";
    copyString = myString;
    cout<<"복사한 값:"<<copyString;
    cout <<endl;

    //비교
    string a = "num1";
    string b = "num2";
    if (a.compare(b) == 0) { // 두 문자열이 같을 때

    } else if (a.compare(b) < 0) { // a가 b보다 사전순으로 앞일 때 : -1 반환

    } else if (a.compare(b) > 0) { // a가 b보다 사전순으로 뒤일 때: 1 반환

    }
    a.compare(0,2,b);//0번째 인덱스부터 2번째 인덱스까지 비교

    //자르기
    string cutTest = "this is a cut test";
    cout <<"5번째부터 쭉 자르기:" <<cutTest.substr(5)<<endl;
    cout<<"5번째만 자르기:"<<cutTest.substr(5,1);
    cout<<endl;


    //바꾸기
    string str1="111";
    string str2 ="222";
    swap(str1, str2);
    cout<<"str1:"<<str1<<endl;

    //삭제하기
    string delStr = "abcd hi bye";
    delStr.erase(0,1); //0번째로부터 1개의 char을 지운다.-> bcd hi
    cout<<delStr<<endl;
    delStr.erase(find(delStr.begin(), delStr.end(), ' ')); //처음부터 끝까지 빈칸을 탐색하여 빈칸을 지운다.(최초로 발견한 빈칸만)
    cout<<delStr<<endl;
    delStr.erase(delStr.find(' '));//해당 문자를 찾은 이후 모든 문자열 삭제
    cout<<delStr<<endl;
    
    //특정 문자 변경하기(최초)
    string base = "this is me";
    base.replace(0, 2, "bye");//0번째부터 2번째까지의 문자열을 지우고 다음 문자열로 바꿔치기한다.
    cout<<base<<endl;
    
    //특정 문자 변경하기(전체)
    string allbase = "hibyehibye";
    ReplaceAll(allbase, "hi", "hello");
    cout<<allbase;

    /*char*/
    //[strlen]:길이
    char charTest[10]="abc";
    cout<<"길이:"<<strlen(charTest)<<endl;

    //[strcmp]:비교

    //[strcpy]:복사

    //[strcat]:덧붙이기

    // 문자열 선언
    char declareArray[] = "ABCD";
    char* declarePointer = "ABCD";
    // 시작주소
    void* startAddrArray = declareArray;
    void* startAddrPointer = declarePointer;
    // 끝주소
    void* endAddrArray = declareArray+3;
    void* endAddrPointer = declarePointer+3;

    // 값의 출력 결과는 동일하지만 메모리에 저장되는 구조는 다르다.
    // ==> pointer로 선언할 경우 문자열 덩어리를 가리키는 값이 메모리에 따로 저장됨
    // ==> (&declarePointer != startAddrPointer)
    cout<<"[Array]";
    cout << "Value : " << declareArray << "\n";
    cout << "Array Addr : " << &declareArray << "(" << startAddrArray << "~" << endAddrArray << ")" << "\n";
    cout<<"[Pointer]";
    cout << "Value : " << declarePointer << "\n";
    cout << "Pointer Addr : " << &declarePointer << "(" << startAddrPointer << "~" << endAddrPointer << ")" << "\n";



    /*변환*/
    //char을 int로
    char changeToInt[5]="10";//문자열 선언 방법
    int intTest = atoi(changeToInt);
    cout<<5+intTest<<endl;

    //int를 char로
    //sprintf(char *, "%d", num1);

    //string을 char로:[.c_str()]
    char ch[100];
    string atest = "I wanna go to bed";
    strcpy(ch,atest.c_str());

    cout<<ch<<endl;

    //char을 strirng으로:[str()]
    char ch2[100] = {"Oh my god"};
    string str(ch2);

    cout <<str<<endl;

    
    
    return 0;
}
