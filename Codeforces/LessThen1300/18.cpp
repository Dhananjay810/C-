#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int greatest=a[0];
    int least=-1;
    int score=0;
    int count=0;
    for(int i=1; (greatest==a[0] && least==-1); i++){
        if(a[i]>greatest){
            score++;
            least=greatest;
            greatest=a[i];
        }
        else if(a[i]<greatest){ least=a[i]; score++;}
        count++;
    }
    for(int i=2; i<n; i++){
        if(a[i]>greatest){
            score++;
            greatest=a[i];
        }
        else if(a[i]<least){
            score++;
            least=a[i];
        }
        else continue;
    }
    if(n==1) cout<<"0";
    else if(count==n) cout<<"0";
    else cout<<score;

}