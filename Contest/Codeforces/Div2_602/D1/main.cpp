#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef pair<int,int> ii;
vector<ii> pairs;

bool compar(ii p1, ii p2){
    if(p1.ff<p2.ff){
        return true;
    }else if(p1.ff>p2.ff){
        return false;
    }else{
        return p1.ss>p2.ss;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int n; cin>>n;
    fore(i,0,n){
        int a; cin>>a;
        pairs.pb({a,i});
    }
    sort(pairs.begin(), pairs.end(),compar);
   // fore(i,0,n){
     //   cout<<pairs[i].ff<<" "<< pairs[i].ss<<" --- ";
//    }
    int m; cin>>m;
    fore(i,0,m){
        int k,posj; cin>>k>>posj;
        vector<ii> quer;
        fore(j, n-k,n){
            quer.pb({pairs[j].ss,pairs[j].ff});
        }
        sort(quer.begin(),quer.end());

        cout<<quer[posj-1].ss<<endl;
    }
    return 0;
}
