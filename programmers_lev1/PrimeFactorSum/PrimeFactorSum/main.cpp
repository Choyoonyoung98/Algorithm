#include <vector>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*vector와 에라토스테네스를 이용한 소수의 합 구하기*/
/*2부터 N까지의 모든 소수의 합을 구하세요.
 N이 7이라면 {2,3,5,7} = 17을 출력 하시면 됩니다.
 N의 범위는 2이상 10,000,000이하 입니다.*/
template <typename T>
void print_vector(std::vector<T>& vec) {
    for(const auto& elem:vec) {
        cout<<elem <<endl;
    }
}

long long solution(int N) {
    long long answer = 0; int prevSum=0;
    vector<int> vec(N,0);

    for(int i=2; i<N+1; i++ ) {
        vec[i]=i;
    }

    for(int i=2; i<=sqrt(N); i++) {
        if(vec[i]==0)continue;
        
        for(int j=i+i; j<N+1; j+=i) {
            vec[j]=0;
        }
    }
    for(int i=2; i<N+1; i++) {
        if(vec[i]!=0){
            answer+=vec[i];
        }
    }
    return answer;
}

 int main() {
     cout<<solution(7);
    
    return 0;
}
