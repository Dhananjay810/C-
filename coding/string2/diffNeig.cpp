#include<iostream>
#include<string>
using namespace std;
int main(){
    string n;
    cout<<"enter string : ";
    cin>>n;
    int h = n.length();
    int count = 0;
    
    for(int i=0; n[i]!='\0'; i++){

        if((i==0 || i==h-1) && (n[i] != n[i+1] || n[i] != n[i-1])){
            count++;
            
        }
         else if(n[i]!=n[i-1] && n[i]!=n[i+1]){
            count++;
        }
        else{
            continue;
        }
    }
    cout<<count<<endl;
    
}