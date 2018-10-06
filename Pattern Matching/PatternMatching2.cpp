#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256


void buildTransitionTable(char *pat,int M,int TF[][NO_OF_CHARS]){
    int i,tracker=0,x;
    for(x=0;x<NO_OF_CHARS;x++){
        TF[0][x] = 0;
    }
    TF[0][pat[0]] = 1;

    for(i=1;i<=M;i++){
        for(x=0;x<NO_OF_CHARS;x++){
            TF[i][x] = TF[tracker][x];
        }
        TF[i][pat[i]] = i+1;

        if(i<M)
            tracker = TF[tracker][pat[i]];
    }
}

void searchUsingPatternMatching(char *pat,char *txt){
    int m = strlen(pat);
    int n = strlen(txt);

    int TF[m+1][NO_OF_CHARS];

    buildTransitionTable(pat,m,TF);

    int i,j=0;
    for(int i=0;i<n;i++){
        j = TF[j][txt[i]];
        if(j==m){
            printf("Pattern found at index %d\n",i-m+1);
        }
    }
}

int main()
    {
        char *pat="aab";
        char *txt="aabbaabaabba";
        searchUsingPatternMatching(pat,txt);
        return 0;
    }
