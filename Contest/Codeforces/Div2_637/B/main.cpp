#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 200010
using namespace std;
bool isPeak[N];
int preSum[N];
int main()
{FIN;
    int t;cin>>t;
    while(t--){
        memset(isPeak,0,sizeof(isPeak)); memset(preSum,0,sizeof(preSum));
        int n,k; cin>>n>>k;
        vector<int> a(n+1);
        fore(i,1,n+1){
            cin>>a[i];
        }
        int cnt = 0;
        fore(i,2,n+1){
            if(i <n &&a[i-1]<a[i] && a[i]>a[i+1]){
                cnt++;
                isPeak[i]=true;
            }
            preSum[i]=cnt;
        }
        int mx = -1;
        int l = 0;
        for(int i = 1; i<=n-k+1;i++){
            int candidate = preSum[i+k-2]-preSum[i];

            if(candidate>mx && candidate>0){
                mx = candidate;
                l=i;
            }
        }
        if(mx >0)cout<<mx+1<<" "<<l<<"\n";
        else cout<<1<<" "<<1<<"\n";

    }
    return 0;
}
