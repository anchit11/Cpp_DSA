#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter order of matrices: ";
    cin>>n;
    int a[n][n];
    int b[n][n];
    int res[n][n];
    cout<<endl<<"Enter elements of Matrix 1: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter element for index "<<"["<<i+1<<"]["<<j+1<<"]: ";
            cin>>a[i][j];
        } 
    }
    cout<<endl<<"Enter elements of Matrix 2: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter element for index "<<"["<<i+1<<"]["<<j+1<<"]: ";
            cin>>b[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int ele=0;
            for(int k=0;k<n;k++){
                ele+=a[i][k]*b[k][j];
            }
            res[i][j]=ele;
        }
    }
    cout<<endl<<"Resultant matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ 
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }

}