#include<iostream>
using namespace std;
int sort(int a[], int n){
    int zero = 0;
    int one = 0;
    for(int i=0; i<n; i++){
        if(a[i]==0){
            zero++;
        }
        else{
            one++;
        }
          
    }
      for(int f=1; f<=zero; f++){
        cout<<"0";
      }
      for(int f=1; f<=one; f++){
        cout<<"1";
      }
    
}
int main(){
    int n;
    cout<<"enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"enter 0 OR 1 : ";
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }
    for(int i=0; i<n; i++)
    {
        cout<<array[i];
    }
    cout<<endl;
    int y = sort(array,n);
}