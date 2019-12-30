#include <string>
#include <iostream>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <string>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
int solution(int N) {
    
    int answer = 0;
    
    int addNumber = 5;
    
    int index = -1;
    int pos = 0;
    string stringN = to_string(N);
    
    if(stringN[0] == '-'){
        for(int i=1; i<stringN.size(); i++) {
            cout<<stringN[i]<<endl;
            if((stringN[i]-'0')>=5) {
                index = i;
                break;
            }
        }
    }else{
        if(N == 0) index = 0;
        else {
            for(int i=0; i<stringN.size(); i++) {
                if((stringN[i]-'0')<=5) {
                    index = i;
                    break;
                }
            }
        }
    }
    
    if(index == -1) index = stringN.size()-1;
    
    stringN.insert(index, "5");
    cout<<index<<endl;
    
    answer = stoi(stringN);
    return answer;
    
    
    
}
int main(int argc, const char * argv[]) {
    cout<<solution(-999);
    return 0;
}
