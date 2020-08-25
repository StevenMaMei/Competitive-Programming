#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
vector<int> a,k;
int cnt_less(int l){
    int cnt = 0;
    for(int i:a) if(i<=l) cnt++;

    for(int y: k){
        if(y>0 && y<=l) cnt++;

        if(y<0 && abs(y)<=cnt)
            cnt--;

    }
    return cnt;
}
int main(){FIN;
    int n,q; cin>>n>>q;
    a.resize(n);
    k.resize(q);
    fore(i,0,n){
        cin>>a[i];
    }
    fore(i,0,q){
        cin>>k[i];
    }
    if(cnt_less(int(1e9))== 0){
        cout<<0<<"\n";
        return 0;
    }
    int l = 0;
    int r = int(1e6)+1;
    int ans =1e9;
//    cout<<cnt_less(3)<<"\n";
    while(l<r){
        int mid = (l+r)/2;
//        cout<<l<<" "<<r<<" "<<mid<<"\n";
        if(cnt_less(mid)>0)
            r= mid, ans = min(ans,r);
        else
            l=mid+1;
    }
    cout<<r<<"\n";
    return 0;
}
