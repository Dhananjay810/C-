#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main
(){
    string n;string h;
    cout<<"enter string : ";
    cin>>n;
    // sort(n.begin(),n.end());
    int count = 0;
    int maxcount = 0;
    for(int i=0; n[i]!='\0'; i++){
        for(int j=0; n[j]!='\0'; j++){
            if(n[i]==n[j] && i != j){
                count++;
            }
        }
        if(maxcount<count){
            maxcount=0;
            maxcount=count;
            count=0;
            
            h = n[i];
        }
        else{
            continue;
        }
        

    }
    if(maxcount==0){
        cout<<"no repetation occur";
    }
    else{
    cout<<h<<" "<<maxcount<<" times";
    }
}