#include<iostream>
using namespace std;
void display(int a[]){
    for(int h=0; h<=2; h++){
        cout<<a[h]<<" ";
    }
    cout<<endl; 

}
void change(int a[]){
    a[0]=100;
}
int main(){
    int arr[3]={1,2,4};
    display(arr);
    
    change(arr);
    display(arr);

     
}