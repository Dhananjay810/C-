#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
int main(){
   string str;
   //cout<<"enter code : ";
   cin>>str;
   stringstream strstr(str);
   vector<int> v;
   string h;
   while(strstr>>h){
    for(int i=0; i<h.length(); i++){
        if(h[i]=='.'){
            cout<<"0";
        }
        else if(h[i]=='-'){
            if(h[i+1]=='-'){
            
                cout<<"2";
                i +=1;
            }
            else if(h[i+1]=='.'){
                cout<<"1";
                i += 1;
            }
           
    }
    //  else{
    //             cout<<"1";
            
    //     }
   }
}
}