#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
set<string> picked;
map<string,vector<ll>> pal;
map<string,vector<ll>> notPal;
int k,n;

bool isPal(string s){
    string rs = s;
    reverse(rs.begin(),rs.end());
    if(rs.compare(s) == 0) return true;

    return false;
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

    cin>>k>>n;

    fore(i,0,k){
        string s; cin>>s;
        ll c; cin>>c;
        if(isPal(s)){
            pal[s].pb(c);
        }else{
            notPal[s].pb(c);
        }
    }
    ll tot= 0;
    for(auto p: notPal){
        if(picked.count(p.ff) >0) continue;
        string rs = p.ff;
        reverse(rs.begin(),rs.end());
        picked.insert(p.ff);
        picked.insert(rs);
        if(notPal.find(rs) != notPal.end()){
            vector<ll> l1 = p.ss;
            auto it = notPal.find(rs);
            vector<ll> l2 = it -> second;
            sort(begin(l1),end(l1),greater<ll>());
            sort(begin(l2),end(l2),greater<ll>());
            for(int i = 0; i< min(l1.size(),l2.size());i++){
                ll cost = l1[i] + l2[i];
                if(cost >0){
                    tot += cost;
                }else{
                    break;
                }
            }
        }
    }
    ll maxi = -1e9;
    for(auto p: pal){
        vector<ll> vec = p.ss;
        sort(vec.begin(), vec.end(),greater<ll>());
        int i =0;
        if(vec.size() == 1 && vec[0]>0){
            maxi = max(maxi,vec[0]);
        }else{
            vector<ii> pairs;
            for(;i<vec.size()-1;i+=2){
                //if(i+1 >= vec.size())
                ll cost = vec[i]+vec[i+1];
                //cout<<vec.size()<<" i "<<i<<" " <<vec[i]<<" "<<vec[i+1]<<endl;
                if(cost>=0){
                    tot += cost;
                    pairs.pb({vec[i],vec[i+1]});
                }else{
                    break;
                }
            }
            if(i>= vec.size()){
                int ind = vec.size()-1;

                if(vec.size()%2 != 0 && vec[ind] >0){
                     maxi = max(maxi,llabs(vec[ind]));
                }else if(pairs.size()>0){
                    ii pa = pairs[pairs.size()-1];
                    ll a = pa.ff;
                    ll b = pa.ss;
                    if(a< b) swap(a,b);

                   if(b<0) maxi = max(maxi,llabs(b));
                }
            }else{
                if(vec[i]>0){
                    maxi = max(maxi,llabs(vec[i]));
                }else if(pairs.size()>0){
                    ii pa = pairs[pairs.size()-1];
                    ll a = pa.ff;
                    ll b = pa.ss;
                    if(a< b) swap(a,b);
                    if(b<0) maxi = max(maxi,llabs(b));
                }
            }
           // cout<<"maxi "<<maxi<<endl;
        }
    }
   // cout<<"tot "<<tot<<endl;
    if(maxi >0){
        tot += maxi;
    }
    cout<<tot<<endl;

    return 0;
}
