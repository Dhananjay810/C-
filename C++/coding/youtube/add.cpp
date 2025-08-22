#include<iostream>
using namespace std;
int main(){



int array[4][4
    ] = {{2,6},{5,8},{4,9},{8,6}};
    int arr[4][4] = {{8,4},{5,7},{4,5},{7,1}};

    //int add[2][2];
    int v,i,j,k,l,m,n,o,p;
    cout<<"enter  initial coor.  x1,y1  x2,y2 : ";
    cin>>i>>j>>k>>l;
    cout<<"enter last coor.  x3,y3  x4,y4 : ";
    cin>>m>>n>>o>>p;

    for(int t;t<=m; i++){
        for(int j; j<=n; j++){
            v = arr[j][i] + array[j][i];
            cout<<v<<" ";
        }
        cout<<endl;
    }
}