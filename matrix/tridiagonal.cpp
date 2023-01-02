#include <iostream>
using namespace std;

class TriDiagonal{
    private:
    int n;
    int *A;
    public:
    TriDiagonal(){
        n=2;
        A=new int[3*n-2];
    }
    TriDiagonal(int n){
        this->n=n;
        A=new int[3*n-2];
    }
    void set( int i, int j, int x);
    int get( int i,int j);
    void display();
    int getDimension(){return n;}
    void create();
    ~TriDiagonal(){delete []A;}
};

void TriDiagonal::create(){
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>x;
            this->set(i,j,x);
        }
    }
}
void TriDiagonal::set( int i, int j, int x){
    if((i-j)==1){
        A[i-2]=x;
    }
    else if((i-j)==-1){
        A[2*n-2+i]=x;
    }
    else if(i==j){
        A[n-2+i]=x;
    }
}

int TriDiagonal::get(int i, int j){
    if((i-j)==1){
        return A[i-2];
    }
    else if((i-j)==-1){
        return A[2*n-2+i];
    }
    else if(i==j){
        return A[n-2+i];
    }
    else{
        return 0;
    }
}

void TriDiagonal::display(){
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
    TriDiagonal m1(n);
    m1.create();
    cout<<endl<<"Resultant Matrix is: "<<endl;
    m1.display();
    return 0;
}