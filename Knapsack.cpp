
#include<iostream>
#include <vector>
using namespace std;

//int max(int a,int b){return (a>b)?a:b;}
     int t[1001][1001] ;
     
    // memset(t, -1, sizeof(t));
    //Function to return max value that can be put in knapsack of capacity W.
    int knapsack(int W, int wt[], int val[], int n) 
    { 
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               if(i==0 || j==0){
                    t[i][j]=0;              
               }
           }
       }
       
       for(int i=1;i<n+1;i++){
           for(int j=1;j<W+1;j++){
               
               if(wt[i-1] <= j){
                   
                   t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                   
               }
               
               else{
                   t[i][j] = t[i-1][j];
               }
           }
       }
       
       return t[n][W];
    }

int main(){
int wt[] = {1,2,3};
int profit[] = {10,15,40};
int W = 6;
int n = 3;


cout<<knapsack(W,wt,profit,n);

cout<<"\n";

for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){
        cout<<t[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}