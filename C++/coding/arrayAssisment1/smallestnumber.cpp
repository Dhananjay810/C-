#include<iostream>
using namespace std;
int smallestnum(int array[] , int o){
    int min = 4;
    for(int j=0; j<o; j++){
        if(array[j]<min){
            min=array[j];
        }


    }
    return min;
}
int main(){
    int o;
    cout<<"enter no. of element : ";
    cin>>o;
    cout<<"enter value : ";
    int array[o];
    for(int i=0; i<o; i++){
        cin>>array[i];

    }

    int minimum = smallestnum(array,o);
    cout<<minimum;
    
}