#include <iostream>
using namespace std;

class Symmetric{
    private:
    int n;
    int *A;
    public:
    Symmetric(){
        n=2;
        A=new int[n*(n+1)/2];
    }
    Symmetric(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void set( int i, int j, int x);
    int get( int i,int j);
    void display();
    int getDimension(){return n;}
    void create();
    ~Symmetric(){delete []A;}
};

void Symmetric::create(){
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>x;
            this->set(i,j,x);
        }
    }
}
void Symmetric::set( int i, int j, int x){
    if(i<=j){
        A[n*(i-1)-(i-1)*(i-2)/2+(j-i)]=x;
    }
}

int Symmetric::get(int i, int j){
    if(i<=j){
        return A[n*(i-1)-(i-1)*(i-2)/2+(j-i)];
    }
    else{
        return get(j,i);
    }
}

void Symmetric::display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j){
                cout<<this->get(i,j)<<" ";
            }
            else{
                cout<<this->get(j,i)<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter order of matrix: ";
    cin>>n;
    Symmetric m1(n);
    m1.create();
    m1.display();
    return 0;
}

