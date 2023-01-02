#include <iostream>
using namespace std;

int main(){
    string str1,str2;
    cout<<"Enter strings: ";
    getline(cin,str1);
    getline(cin,str2);

    int A[26]={0};
    int i;
    
    if(str1.length()!=str2.length()){
        cout<<"Not Anagram"<<endl;
        return 1;
    }
    for(i=0;i<str1.length();i++){
        A[str1[i]-97]++;
    }
    for(i=0;i<str2.length();i++){
        if(A[str2[i]-97]>0){
            A[str2[i]-97]--;
        }
        else{
            cout<<"Not Anagram"<<endl;
            break;
        }
    }
    if(str2[i]=='\0'){
        cout<<"Anagram"<<endl;
    }
    return 0;
}