#include <iostream>
using namespace std;

//very important algorithms

void perm(string s, int k =0){
    static int A[10]={0};
    static char res[10];
    int i;
    if(s[k]=='\0'){
        res[k]='\0';
        cout<<res<<endl;
    }
    else{
        for(i=0;s[i]!='\0';i++){
            if(A[i]==0){
                A[i]=1;
                res[k]=s[i];
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}

void perm2(string s, int l, int h){
    int i;
    if(l==h){
        cout<<s<<endl;
    }
    else{
        for(i=l;i<=h;i++){
            swap(s[i],s[l]);
            perm2(s,l+1,h);
            swap(s[i],s[l]);
        }
    }
}

int main(){
    perm2("abc",0,2);
}