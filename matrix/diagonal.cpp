#include <iostream>
using namespace std;

class Matrix{
    private:
    int n;
    int *A;
    public:
    Matrix(){
        n=2;
        A=new int[n];
    }
    Matrix(int n){
        this->n=n;
        A=new int[n];
    }
    void set( int i, int j, int x);
    int get( int i,int j);
    void display();
    ~Matrix(){delete []A;}
};

void Matrix::set( int i, int j, int x){
    if(i==j){
        A[i-1]=x;
    }
}

int Matrix::get(int i, int j){
    if(i==j){
        return A[i-1];
    }
    else{
        return 0;
    }
}

void Matrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<A[i]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter order of matrix: ";
    cin>>n;
    Matrix m1(n);
    m1.set(1,1,1);
    m1.set(2,2,4);
    m1.set(3,3,9);
    m1.display();
    return 0;
}

