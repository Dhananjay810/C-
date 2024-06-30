#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string str;
    cout<<"enter string : ";
    cin>>str;
    stringstream strstr(str);
    vector<int> v;
    string d;
    while(strstr>>d){

       // cout<<d[0];
       // cout<<d.length();
        for(int i=0;i<d.length();i++){
            int u = (int)d[i];
            if(u==45){
            if(i<d.length()-1){
                int t = (int)d[i+1];
                if(u==45&&t==45){
                    cout<<"2";
                    i=i+1;
                }
                else{
                    cout<<"1";
                }
                

            }
            else{
                cout<<"1";
            }
            }
            
            
            if(u==46){
                cout<<"0";
            }
            // else if(u==45){
            //     cout<<"1";
            // }
            // else if(u == 45 && t ==45){
            //     cout<<"2";
            // }
            // else{
            //     cout<<"error";
            // }
           // cout<<d[i];


        }
    }
}