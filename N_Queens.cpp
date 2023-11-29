#include <bits/stdc++.h>
using namespace std;


bool place(int k,int i,vector<int>& x){
    
    for(int j=1;j<k;j++){
        if(x[j]==i || abs(x[j]-i)==abs(j-k)){
            return false;
        }
    }
        return true;
}

void NQueens(int k,int n,vector<int>& x){
    for(int i=1;i<=n;i++){
        if(place(k,i,x)){
            x[k]=i;
            
            if(k==n){
                for(int i=1;i<=n;i++){
                    if(x[i]!=0)
                    cout<<x[i]<<" ";
                }
                cout<<endl;
            }
            else{
                NQueens(k+1,n,x);
            }
        }
    }
}


int main(){
    int n;
    cout<<"Enter the number of queens:";
    cin>>n;
    
vector<int> x;
    x.resize(n);
    auto start = clock();
    NQueens(1,n,x);
    auto end = clock();

    auto result = (end -start);

    cout<<"Time taken: "<<result<<"ms" ;
}
