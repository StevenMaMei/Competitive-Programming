#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 55
#define M 20005
using namespace std;
int animals[N][M],l[N][M],r[N][M],pre[N][M],dp[N][M];

int getS(int i, int j1,int j2){
    return pre[i][j2]-pre[i][j1-1];
}
int main()
{FIN;
    int n,m,k; cin>>n>>m>>k;
    fore(i,1,n+1){
        fore(j,1,m+1){
            cin>>animals[i][j];
            pre[i][j] =animals[i][j]+ pre[i][j-1];
        }
    }
    fore(i,1,n+1){
        for(int j = 1; j<=m-k+1;j++){
            int p = getS(i,j,j+k-1)+getS(i+1,j,j+k-1);
            if(i==1){
                dp[i][j]=p;
                continue;
            }
            int mx = 0;
            for(int z = max(1,j-k+1); z<= min(j+k-1,m-k+1);z++){
                mx= max(mx,dp[i-1][z]+p-getS(i,max(j,z),min(z+k-1,j+k-1) ));
            }
            dp[i][j]= mx;

            if(j>k){
                dp[i][j] = max(dp[i][j], l[i-1][j-k]+p);

            }
            if(j+k<=m-k+1){
                dp[i][j] = max(dp[i][j], r[i-1][j+k]+p);
            }
        }
        for(int j = 1; j<=m;j++){
            l[i][j]= max(dp[i][j],l[i][j-1]);
        }
        for(int j=m; j>=1;j--){
            r[i][j]= max(dp[i][j],r[i][j+1]);
        }
    }
    cout << *max_element(dp[n] + 1, dp[n] + m + 1) << '\n';
    return 0;
}
