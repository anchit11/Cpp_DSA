#include <iostream>
using namespace std;

class Term{
    public:
    int coeff;
    int exp;
};

class Polynomial{
    private:
    int n;
    Term *t;

    public:

    Polynomial(int n){
        this->n=n;
        t=new Term[this->n];
    }
    void read();
    void display();
    Polynomial operator+(Polynomial &p);
};

void Polynomial::read(){
    for(int i=0;i<n;i++){
        cout<<"Enter coeff & exp of term "<<i+1<<": ";
        cin>>t[i].coeff>>t[i].exp;
    }
}

void Polynomial::display(){
    for(int i=0;i<n;i++){
        cout<<t[i].coeff<<"x^"<<t[i].exp<<"+";
    }
}

Polynomial Polynomial::operator+(Polynomial &p){
    int i,j,k;
    i=j=k=0;
    Polynomial *sum;
    sum = new Polynomial(n+p.n);
    while(i<n&&j<p.n){
        if(t[i].exp>p.t[j].exp){
            sum->t[k++]=t[i++];
        }
        else if(t[i].exp<p.t[j].exp){
            sum->t[k++]=p.t[j++];
        }
        else{
            sum->t[k]=t[i];
            sum->t[k++].coeff=t[i++].coeff + p.t[j++].coeff;
        }
    }
    for(;i<n;i++){sum->t[k++]=t[i];}
    for(;j<p.n;j++){sum->t[k++]=p.t[j];}
    sum->n=k;
    return *sum;
}
int main(){
    int n;
    cout<<"Enter number of non zero terms: ";
    cin>>n;
    Polynomial p1(n);
    p1.read();
    cout<<"Enter number of non zero terms: ";
    cin>>n;
    Polynomial p2(n);
    p2.read();
    Polynomial p3 = p1+p2;

    p3.display();

}