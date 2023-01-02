#include <iostream>
using namespace std;
// same as upper triangle
// i<=j is the condition & row <-> column :: lower <-> upper :: row Major <-> column Major
class LowerTri{
    private:
    int n;
    int *A;
    public:
    LowerTri(){
        n=2;
        A=new int[n*(n+1)/2];
    }
    LowerTri(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void set( int i, int j, int x);
    int get( int i,int j);
    void display();
    int getDimension(){return n;}
    ~LowerTri(){delete []A;}
};
// for column major replace A[i*(i-1)/2+j-1] by A[n*(j-1)-(j-2)*(j-1)/2+(i-j)]
void LowerTri::set( int i, int j, int x){
    if(i>=j){
        A[i*(i-1)/2+j-1]=x;
    }
}

int LowerTri::get(int i, int j){
    if(i==j){
        return A[i*(i-1)/2+j-1];
    }
    else{
        return 0;
    }
}

void LowerTri::display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){
                cout<<A[i*(i-1)/2+j-1]<<" ";
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
    cout<<"Enter order of Matrix: ";
    cin>>n;
    LowerTri m1(n);
    cout<<"Enter elements: "<<endl;
    int ele;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ele;
            m1.set(i,j,ele);
        }
    }
    cout<<endl<<endl;
    m1.display();
    return 0;
}