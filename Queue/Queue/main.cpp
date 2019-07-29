#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100

int front,rear;
int queue[MAX_QUEUE_SIZE];

void queueInit(void) {
    front = 0;
    rear=0;
    
}
int queueIsEmpty(void) {
    return(front == rear);
}
int queueIsFull(void) {
    if((rear+1)%MAX_QUEUE_SIZE == front) {
        return 1;
    }else{
        return 0;
    }
}
void queueEnqueue(int value) {
    if(queueIsFull()){
        cout<<"queue is full!";
    }
    queue[rear] = value;
    rear++;
    if(rear == MAX_QUEUE_SIZE) {
        rear = 0;
    }
}
int queueDequeue() {
    if(queueIsEmpty()){
        cout<<"queue is empty!";
        return -1;
    }
    return queue[front];
    front++;
    
}
