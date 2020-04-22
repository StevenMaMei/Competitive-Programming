#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;

int n;
vector<int> a;
int dp[505][505];

int dp1(int l, int r){
    assert(l<r);
    if(l+1== r){
        return dp[l][r] = a[l];
    }
    if(dp[l][r] != 0) return dp[l][r];
    dp[l][r]= -1;
    fore(mid,l+1,r){
        int lf = dp1(l,mid);
        int lg = dp1(mid,r);
        if(lf >0 && lf == lg){
            return dp[l][r]= lf+1;
        }
    }
    return dp[l][r];
}
int dp2[505];
int main()
{FIN;
    cin>>n;
    a.resize(n);
    fore(i,0,n){
        cin>>a[i];
    }
    fore(i,0,506){
        dp2[i] = 1e9;
    }
    dp2[0]= 0;
    fore(i,0,n){
        fore(j,i+1,n+1){
            if(dp1(i,j)>0){
                dp2[j] = min(dp2[j],dp2[i]+1);

            }
        }
    }
    cout<<dp2[n]<<"\n";
    return 0;
}
