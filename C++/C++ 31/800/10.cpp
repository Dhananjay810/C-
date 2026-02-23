#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>> v;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                char ch;
                cin>>ch;
                if(ch=='X') v.push_back({i,j});
            }
        }
        int ans=0;
        for(int i=0; i<v.size(); i++){
            int a=v[i].first;
            int b=v[i].second;
            if((a==0 || a==9 || b==0 || b==9)) ans+=1;
            else if(
                ((a==1 || a==8) && (b>0 && b<9)) || ((b==1 || b==8) && (a>0 && a<9))
            ) ans+=2;
            else if(
                ((a==2 || a==7) && (b>1 && b<8)) || ((b==2 || b==7) && (a>1 && a<8))
            ) ans+=3;
            else if(
                ((a==3 || a==6) && (b>2 && b<7)) || ((b==3 || b==6) && (a>2 && a<7))
            ) ans+=4;
            else if(
                ((a==4 || a==5) && (b>3 && b<6)) || ((b==4 || b==5) && (a>3 && b<6))
            ) ans+=5;
        }
        cout<<ans<<endl;
    }
}