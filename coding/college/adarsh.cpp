#include<iostream>
using namespace std;
int main(){
    int t=3;
    int a1[t];
    int a2[t];
    cout<<"enter value to a1 : ";
    for(int i=0; i<t; i++){
        cin>>a1[i];
    }
    cout<<"enter value to a2 : ";
    for(int i=0; i<t; i++){
        cin>>a2[i];
    }

    int a3[t][t];
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            a3[i][j]=a1[i]+a2[j];
        }
    }
    int min=a3[0][0];
    int sum=0;
for(int i=0; i<t; i++){
    for(int j=0; j<t; j++){
        if(min>=a3[j][i]){
            min=a3[j][i];
        }
        else{
            continue;
        }
    }
    cout<<min<<" ";
    sum = sum+min;
}
cout<<endl<<sum;
}