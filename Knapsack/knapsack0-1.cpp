#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int w[100];
int p[100];


int knapsack(int sz,int n){
    if(sz==0||n==0)
        return 0;
    if(dp[sz][n]!=-1)
        return dp[sz][n];
    int r1=0,r2=0;
    if(w[n]<=sz){
        r1=p[n]+knapsack((sz-w[n]),n-1);
        r2=knapsack(sz,n-1);
        return dp[sz][n]=max(r1,r2);
    }
    return dp[sz][n]=knapsack(sz,n-1);
}

int main(){
    int sz,n;
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&sz,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&p[i]);
    }
    int r = knapsack(sz,n);
    cout<<r<<"\n";
    return 0;
}
