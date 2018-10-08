#include<bits/stdc++.h>
using namespace std;

int main()
    {
        int n=5;
        int p[5]={5,4,6,2,7};
        int j,minimum,q;
        int M[5][5];
        memset(M,0,sizeof(M));
        for(int d=1;d<n-1;d++){
            for(int i=1;i<n-d;i++){
                j=i+d;
                minimum=32767;
                for(int k=i;k<=j-1;k++){
                    q=M[i][k]+M[k+1][j]+(p[i-1]*p[k]*p[j]);
                    if(q<minimum)
                        minimum=q;
                }
                M[i][j]=minimum;
            }
        }
        printf("%d\n",M[1][n-1]);
        return 0;
    }
