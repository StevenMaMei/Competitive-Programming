#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
ll n,m,x,k,y;
const int N = int(2e5)+5;
ll a[N], b[N];
bool canUpd(int l, int r, ll &res){
    if(l>r)return true;
    int mx = *max_element(a+l,a+r+1);
    bool canDelete= false;
    int len = r-l +1;
    if(l-1>=0 && a[l-1]>mx)canDelete=true;
    if(r+1<n && a[r+1]>mx)canDelete=true;
    if(len <k && !canDelete)return false;

    ll need = len%k;
    res += need*y;
    len -= need;
    if(y*k >=x){
        res += (len/k)*x;
    }else if(canDelete){
        res += y*len;
    }else{
        res += (len -k)*y+x;
    }
    return true;
}
int main(){FIN;
    cin>>n>>m>>x>>k>>y;
    fore(i,0,n)cin>>a[i];
    fore(i,0,m)cin>>b[i];
    ll last=-1,posa=0,posb=0;
    ll ans = 0;
    while(posb<m){
        while(posa<n && a[posa]!=b[posb])posa++;
        if(posa == n){
            cout<<"-1\n";
            return 0;
        }
        if(!canUpd(last+1,posa-1,ans)){
            cout<<"-1\n";
            return 0;
        }
        last = posa;
        posb++;
    }
    if(!canUpd(last+1,n-1,ans)){
        cout<<"-1\n";
        return 0;
    }
    cout<<ans<<"\n";
    return 0;
}
