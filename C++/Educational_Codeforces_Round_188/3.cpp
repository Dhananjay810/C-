#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

long long f1(long long a, long long b, long long c, long long n) {
    long long x=a, y=b;
    while(y){ long long t=y; y=x%y; x=t; }
    long long l = (a/x)*b;

    x=l; y=c;
    while(y){ long long t=y; y=x%y; x=t; }
    l = (l/x)*c;

    return n/l;
}

long long f2(long long a, long long b, long long n) {
    long long x=a, y=b;

    while(y){
        long long t=y;
        y=x%y;
        x=t;
    }

    long long l = (a/x)*b;

    return n/l;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,m;
        cin>>a>>b>>c>>m;

        long long tin=f1(a,b,c,m);

        long long do1=f2(a,b,m);
        long long do2=f2(b,c,m);
        long long do3=f2(a,c,m);

        long long mm1=f2(a,1,m);
        long long mm2=f2(b,1,m);
        long long mm3=f2(c,1,m);

        long long ans1=0, ans2=0, ans3=0;

        ans1 += 2*tin;
        ans2 += 2*tin;
        ans3 += 2*tin;

        ans1 += (do1-tin)*3;
        ans2 += (do1-tin)*3;

        ans2 += (do2-tin)*3;
        ans3 += (do2-tin)*3;

        ans1 += (do3-tin)*3;
        ans3 += (do3-tin)*3;

        long long onlyA = mm1 - do1 - do3 + tin;
        long long onlyB = mm2 - do1 - do2 + tin;
        long long onlyC = mm3 - do2 - do3 + tin;

        ans1 += onlyA * 6;
        ans2 += onlyB * 6;
        ans3 += onlyC * 6;

        cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
}