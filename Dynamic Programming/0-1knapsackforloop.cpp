#include<bits/stdc++.h>
using namespace std;

int main(){
    int wt,n;
    scanf("%d%d",&wt,&n);
    int weight[n+5];
    int value[n+5];

    for(int i=1;i<=n;i++){
        scanf("%d%d",&weight[i],&value[i]);
    }

    int dp[n+5][n+5];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=wt;j++){
            if(i==0||j==0) dp[j][i]=0;
            else if(weight[i]<=j)
                dp[j][i]=max(value[i]+dp[j-weight[i]][i-1],)
        }
    }

    return 0;
}
