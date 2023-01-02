#include <iostream>
using namespace std;

class Queue{
    private:
    int size;
    int front;
    int rear;
    int *Q;

    public:
    Queue();
    Queue(int s);
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

Queue::Queue(){
    size = 10;
    front = rear = -1;
    Q=new int[size];
}

Queue::Queue(int size){
    this->size = size;
    front = rear = -1;
    Q=new int[size];
}

bool Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    return false;
}

bool Queue::isFull(){
    if(rear==size-1){
        return true;
    }
    return false;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue is Full"<<endl;
    }else{
        rear++;
        Q[rear]=x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i];
        if(i<rear){
            cout<<" <- ";
        }
    }
    cout<<endl;
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q(sizeof(A)/sizeof(A[0]));
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();
 
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout<<q.dequeue()<<endl;
    }
 
    // Underflow
    q.dequeue();
    
    return 0;
}
