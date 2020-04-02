#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool flag = true;
    int n = 0;
    int cnt = 0;
    
    vector<int> temp = priorities;
    vector<boo> visited(temp.size(), false);//같은 숫자도 존재하므로!
    queue<int> q;
    
    //우선순위가 높은 순서대로 재정렬
    sort(priorities.begin(),priorities.end(), greater<int> );
    
    //우선순위 높은 순서대로 정렬된 것을 큐에 저장.
    for(int i=0; i<priorities.size(); i++) {
        q.push(priorities[i]);
    }
    
    while(flag == true) {
        n=q.front();
        for(int i=0; i<temp.size(); i++) {
            if(visited[i]==false && n==temp[i]){
                cnt++;//나중에 location 몇번째 숫자인지 나중에 알려주기 위해
                
                if(i==location) {
                    flag = false;
                    break;
                }
                
                q.pop();
                visited[i] = true;
                n=q.front();
            }
        }
    }
    answer = cnt;
    
    
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<int> priorites = {1,1,9,1,1,1};
    int location = 0;
    cout<<solution(priorites, location);
    
    return 0;
}
