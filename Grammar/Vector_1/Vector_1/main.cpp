/*Vector*/
class Vector {
    string* data;
    int capacity;
    int length;
    
public:
    // 생성자
    Vector(int n = 1);
    
    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(string s);
    
    // 임의의 위치의 원소에 접근한다.
    string operator[](int i);
    
    // x 번째 위치한 원소를 제거한다.
    void remove(int x);
    
    // 현재 벡터의 크기를 구한다.
    int size();
    
    ~Vector();
};
Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

void Vector::push_back(string s) {
    if(capacity <=length) {
        string* temp = new string[capacity *2];//임의의 배열의 공간을 두배로 증가시킨다.
        for(int i=0; i<length; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity*2;
    }
    data[length] = s;
    length++;
}
string Vector::operator[](int i) {
    return data[i];
}
void Vector::remove(int x) {
    for(int i=x+1; i<length; i++) {
        data[i-1] = data[i];
        
    }
    length--;
}
int Vector::size() {
    return length;
}
Vector::~Vector() {
    if(data){
        delete []data;
    }
}
