#include<iostream>
using namespace std;
int secondlargest(int array[], int n){
    int max1=0;
    int max2=0;
    for(int j=0; j<n; j++){
        if(array[j]>max1){
            max2 = max1;
            max1 = array[j];
        }

        else if(array[j] > max2 && array[j] != max1){
            max2 = array[j];
        }
    }

    return max2;


}
int main(){
    int n;
    cout<<"enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"entre value : ";
    for(int i=0; i<n; i++){
        cin>>array[i];

    }
   int secondmax = secondlargest(array,n);

   if(secondmax == 0)cout<<"this array does no contain 2nd largest no.";
   else{

    cout<<"the 2nd largest no. is : "<<secondmax<<endl;
   }




    
}