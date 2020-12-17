//
//  main.cpp
//  Cgrammar_6
//
//  Created by 조윤영 on 17/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 문제 1
 여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다. set_date 는 말그대로 Date 함수 내부를 초기화 하는 것이고 add_day, add_month, add_year 는 일, 월, 년을 원하는 만큼 더하게 됩니다. 한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요? (난이도 : 上)
 */
class Date {
    int year;
    int month;
    int day;
    int max_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
public:
    void set_date(int _year, int _month, int _date);
    void add_day(int inc);
    void add_month(int inc);
    void add_year(int inc);
    void get_date();
    void leaf_year(int _year);
    void getOverFlowState(int _month, int* _day);
    
    /*생성자*/
    Date(int _year, int _month, int _day) {
        cout << "[사용자 지정]" << endl;
        year = _year;
        month = _month;
        day = _day;
    }
    /*디폴트 값*/
    Date() {
        cout << "[기본 생성자]" << endl;
        year = 2012;
        month = 1;
        day = 1;
    }
    
};

void Date::set_date(int _year, int _month, int _day) {
    bool can_update_year = true, can_update_month=true, can_update_day=true;
    
    //입력한 년/월/일이 0이상인가?
    if(_year <=0) can_update_year=false;
    if(_month <=0)can_update_month=false;
    if(_day <=0)can_update_month=false;
    
    //입력한 년이 0이상이라면,
    if(can_update_year){
        leaf_year(_year);//윤년,평년 여부 판단
        year=_year;
    }
    
    //입력한 날짜가 0이상이라면,
    if(can_update_day){
        getOverFlowState(_month, &_day);//날짜가 그 달의 최대 날짜를 넘는지 판단.(넘으면 최대 날짜로 초기화)
        day=_day;
    }
    
    //입력한 달이 0 이상이라면,
    if(can_update_month)month=_month;
}



//셋팅한 날짜가 해당 월의 최대 날짜를 넘는지 확인/변경
void Date::getOverFlowState(int _month, int* _day){
    int max_day = max_days[_month-1];
    
    if(*_day > max_day){//셋팅된 날짜가 그 달의 존재하는 날짜보다 크다면 가장 최대 날짜로 바꾸어준다!
        *_day = max_day;
    }
}

void Date::add_day(int inc) {
    int _day = day+inc;
    bool overflowed = false;
    int max_day = max_days[month-1];
    
    if(_day > max_day){//현재 날짜+더하고자 하는 값이 최대 날짜보다 크다면,
        add_month(1);//다음달로 넘어간다. 이전의 달이 12월인 경우 1월로 돌아가게 add_month에서 처리.
        
        _day = _day - max_day;//더 더해야하는 남은 날짜를 저장한다.
        day=0;
        overflowed = true;
    }
    if(overflowed) {
        add_day(_day);//남은 날짜 수로 재귀호출 시도
        return;
    }
    day = _day;//연산의 결과로 현재 달의 최대 날짜보다 남은 날짜가 작을 때, 그 날짜를 출력.
    
}

void Date::add_month(int inc) {
    int _month = month+inc;
    bool overflowed = false;
    
    if(_month >12){
        add_year(1);
        _month = month-12;//다시 1월부터 시작.
        month=0;
        overflowed = true;
    }
    if(overflowed){
        add_month(_month);//재귀 호출.
        return;
    }
    month = _month;
    
}
void Date::add_year(int inc) {
    year+=inc;
}
void Date::get_date() {
    cout << "Date = " << year << " - " << month << " - " << day << endl;
}

/*추가적으로, 윤년을 판별하는 함수*/
//1.4로 나누어 떨어지고 &&
//2.100으로 나누어 떨어지지 않지만, 400으로 나누어 떨어지는 해는 윤년이다.
void Date::leaf_year(int year){
    
    if(((year%4==0)&&(year%100!=0))||(year%400 == 0)) max_days[1] = 29;
    else max_days[2] = 28;
}


int main(int argc, const char * argv[]) {
    
    
    Date day1 = Date();
    day1.get_date();
    
    /*암시적인 방법*/
    Date day2(2011,3,1);
    day2.get_date();
    /*명시적인 방법*/
    Date day3;
    day3.set_date(2011, 5, 1);
    day3.get_date();
    
    //    date.set_date(2012, 2, 28);
    //    date.get_date();
    //
    //    date.add_day(3);
    //    date.get_date();
    
    //    date.add_month(22);
    //    date.get_date();
    
    return 0;
}
