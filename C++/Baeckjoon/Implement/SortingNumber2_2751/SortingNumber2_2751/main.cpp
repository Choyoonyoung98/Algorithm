//
//  main.cpp
//  SortingNumber2_2751
//
//  Created by 조윤영 on 2020/11/24.
//수 정렬하기2
//다양한 정렬방식에 대해 숙지하고, 동작 방식과 코드에 대해 익숙해지기
//https://www.acmicpc.net/problem/2751

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void printList(vector<int> list);
void printListFromIndex1(vector<int> list);
int N = 0;
vector<int> numbers;
vector<int> temp_numbs;

void input() {
    cin>> N;
    numbers.assign(N, 0);
    for(int i=0; i<N; i++) cin>> numbers[i];
    
    temp_numbs = numbers;
}

void selectionSort(vector<int> numbs) {
    cout<<"[선택정렬을 사용한 정렬]\n";
    
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(numbs[i] > numbs[j]) {
                int temp = numbs[i];
                numbs[i] = numbs[j];
                numbs[j] = temp;
            }
        }
    }
    
    for(int n: numbs) cout<<n<<"\n";
}

void insertSort(vector<int> numbs) {
    cout<<"[삽입정렬을 사용한 정렬]\n";
    
    for(int i=1; i<N; i++) {
        for(int j=i-1; j>=0; j--) {
            if(numbs[j] > numbs[j+1]) {
                int temp = numbs[j];
                numbs[j] = numbs[j+1];
                numbs[j+1] = temp;
            } else break;
        }
    }
    for(int n: numbs) cout<<n<<"\n";
    
}

void heapify(int paretIndex) {
    int leftChildIndex = 2 * paretIndex; //왼쪽 자식 노드
    int rightChildIndex = 2* paretIndex + 1; //오른쪽 자식 노드
    int swapIndex = leftChildIndex;
    
    //왼쪽 자식 노드와 오른쪽 자식 노드를 비교해서 더 값이 큰 노드를 parentIndex와 바꾼다
    if(leftChildIndex < N && temp_numbs[leftChildIndex] < temp_numbs[rightChildIndex])  swapIndex = rightChildIndex;
    
    if(temp_numbs[paretIndex] < temp_numbs[leftChildIndex]) {
        int temp = temp_numbs[swapIndex];
        temp_numbs[swapIndex] = temp_numbs[paretIndex];
        temp_numbs[paretIndex] = temp;
        if(swapIndex <= N / 2) heapify(leftChildIndex); //swap된 자식노드들의 손자노드들 또한 정렬하기 위해 재귀함수로 들어간다
    }
}

void heapSort(int index) {
    //1: 루트(가장 큰 원소)와 정렬되지 않은 원소 중에서 마지막 원소 SWAP
    int temp = temp_numbs[index];
    temp_numbs[index] = temp_numbs[1];
    temp_numbs[1] = temp;
    
    //2: 1의 과정을 거치고 나면 루트노드에 최하단 자식 노드의 값이 들어오게 되므로
    //루트 노드의 왼쪽 자식 노드를 기준으로 최대힙을 재구성한다!
    int root = 1; //편의상 루트는 1부터 시작한다!
    int leftChildIndex = 0, rightChildIndex = 0;
    
    while(leftChildIndex / 2 < index) {
        leftChildIndex = 2* root;
        rightChildIndex = 2 * root + 1;
        int swapIndex = leftChildIndex;
        
        if(leftChildIndex < index - 1 && temp_numbs[leftChildIndex] < temp_numbs[rightChildIndex] ) swapIndex = rightChildIndex;
        if(leftChildIndex < index && temp_numbs[root] < temp_numbs[swapIndex]) {
            int temp = temp_numbs[root];
            temp_numbs[root] = temp_numbs[swapIndex];
            temp_numbs[swapIndex] = temp;
        }
        root = swapIndex;
    }
}

void heap() {
    cout<<"[힙정렬을 사용한 정렬]\n";
    
    //1: 최초 heap 생성: 자식노드가 부모노드보다 무조건 작은 트리를 형성한다
    //배열 전체 크기/2부터 루트까지 검사한다.
    for(int i = N / 2; i >0; i--) heapify(i);
    
    //2: heap 정렬
    //최대힙을 오름차순으로 정렬한다
    for(int i = N; i >0; i--) heapSort(i);
    printListFromIndex1(temp_numbs);
}

void merge(int left, int mid, int right) {
    vector<int> sorted_list(N, 0);
    int i = left;
    int j = mid + 1;
    int k = left;
    
    while(i <= mid && j <= right ) {
        if(temp_numbs[i] <= temp_numbs[j]) {
            sorted_list[k] = temp_numbs[i];
            i++;
        } else { // temp_numbs[i] > temp_numbs[j]
             sorted_list[k] = temp_numbs[j];
            j++;
        }
        k++;
    }
    
    if(i > mid) {
        for(int index = j; index <= right; index++) {
            sorted_list[k] = temp_numbs[index];
            k++;
        }
    } else {
        for(int index = i; index <= mid; index++) {
            sorted_list[k] = temp_numbs[index];
            k++;
        }
    }
    
    for(int index = left; index <= right; index++) temp_numbs[index] = sorted_list[index];
}

void mergeSort(int left, int right) {
    
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid); //좌측 정렬
        mergeSort(mid+1, right); //우측 정렬
        merge(left, mid, right);
    }
}

void quickSort(int left, int right) { //*
    if(left >= right) return;
    
    int pivot = left;
    int i = left + 1; //왼쪽 출발 지점
    int j = right; //오른쪽 출발 지점
    
    while(i <= j) {
        while(i <= right && temp_numbs[i] <= temp_numbs[pivot]) i++;
        while(j > left && temp_numbs[j] >= temp_numbs[pivot]) j--;
        
        if(i > j) {
            int temp = temp_numbs[j];
            temp_numbs[j] = temp_numbs[pivot];
            temp_numbs[pivot] = temp;
        } else {
            int temp = temp_numbs[i];
            temp_numbs[i] = temp_numbs[pivot];
            temp_numbs[pivot] = temp;
        }
    }

    quickSort( left, j-1);
    quickSort(j+1, right);
}

void bubbleSort(vector<int> numbs) { //*
    cout<<"[버블정렬을 사용한 정렬]\n";
    
    for(int i=N-1; i>=1; i--) {
        for(int j=0; j<i; j++) {
            if(numbs[j] > numbs[j+1]) {
                int temp = numbs[j+1];
                numbs[j+1] = numbs[j];
                numbs[j] = temp;
            }
        }
    }
    for(int n: numbs) cout<<n<<"\n";
}

void algorithmSort(vector<int> numbs) {
    cout<<"[sort 함수를 사용한 정렬]\n";
    sort(numbs.begin(), numbs.end());
    for(int n: numbs) cout<<n<<"\n";
}

void resetGlobalList() {
    temp_numbs = numbers;
}

void resetListFromIndex1() {
    temp_numbs.assign(N+1, 0);
    for(int i=0; i<N; i++) {
        temp_numbs[i+1] = numbers[i];
    }
}

void printList(vector<int> list) {
    for(int l: list) cout<<l<<"\n";
}
void printListFromIndex1(vector<int> list) {
    for(int i=1; i<=N; i++) cout<<list[i]<<"\n";
}

void solution() {
    algorithmSort(numbers);
    insertSort(numbers);
    bubbleSort(numbers);
    selectionSort(numbers);

    cout<<"[퀵정렬을 사용한 정렬]\n";
    quickSort(0, N-1);
    printList(temp_numbs);

    cout<<"[머지정렬을 사용한 정렬]\n";
    resetGlobalList();
    mergeSort(0, N-1);
    printList(temp_numbs);
    
    resetListFromIndex1();
    heap();
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}
