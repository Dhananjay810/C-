int j;
    for(j=2; j<sqrt(n); j++){
        if(n%j==0){
            cout<<j<<" ";
        }
    }
    for(j=sqrt(n); j>1; j--){
        if(n%j==0){
            cout<<n/j<<" ";
        }
    }