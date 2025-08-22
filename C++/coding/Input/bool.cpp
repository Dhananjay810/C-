#include<iostream>
using namespace std;
int main(){
    bool p = false;
    bool q = false;
    bool r = true;
    cout<<(p == q == r)<<endl;
    // it mean  
    //            is p = q
    //             is q is not equal to r
    int h = 5;
    int o = 4;
    int y = 3;
    cout<<(h ==(o != y));

}