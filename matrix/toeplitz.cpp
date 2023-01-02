#include <iostream>
using namespace std;

class Toeplitz{
    private:
    int n;
    int *A;
    public:
    Toeplitz(){
        n=2;
        A=new int[2*n-1];
    }
    Toeplitz(int n){
        this->n=n;
        A=new int[2*n-1];
    }
    void set( int i, int j, int x);
    int get( int i,int j);
    void display();
    int getDimension(){return n;}
    void create();
    ~Toeplitz(){delete []A;}
};

void Toeplitz::create(){
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>x;
            this->set(i,j,x);
        }
    }
}
void Toeplitz::set( int i, int j, int x){
    if(i==1){
        A[j-i]=x;
    }
    else if(j==1&&i!=1){
        A[n+i-j]=x;
    }
}

int Toeplitz::get(int i, int j){
    if(i<=j){
        return A[j-i];
    }
    else if(i>j){
        return A[n+i-j];
    }
    else{
        return 0;
    }
}

void Toeplitz::display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<this->get(i,j)<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter order of matrix: ";
    cin>>n;
    Toeplitz m1(n);
    m1.create();
    cout<<endl<<"Resultant Matrix is: "<<endl;
    m1.display();
    return 0;
}