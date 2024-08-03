#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int tw=0;
    int fif=0;
    int cost=25;
    for(int i=0; i<n; i++){
        int curr=v[i];
        int ret=curr-cost;
        if(ret==0){
            tw++;
        }
        else if(ret==25){
            if(tw==0){
                cout<<"NO";
                return 0;
            }
            else{
                tw--;
                fif++;
            }
        }
        else if(ret==75){
            if(fif!=0 && tw !=0){
                fif--;
                tw--;
            }
            else if(tw>=3) tw -= 3;
            else{
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}