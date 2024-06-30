#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int u=0,v=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='1'){
            u++;
        }
        else if(s[i]=='4' && i!=0){
            if(s[i-1]=='1'){
                u++;
            }
            else if(s[i-1]=='4' && i!=1){
                if(s[i-2]=='1'){
                    u++;
                }
                else{
                    v=1;
                    break;
                }
            }
            else{
                v=1;
                break;
            }
        }
        else{
            v=1;
            break;
        }
    }
    if(v!=0){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}