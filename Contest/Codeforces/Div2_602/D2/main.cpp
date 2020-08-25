#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
vector<ii> pairs;

map<ii,int> offAns;
vector<pair<ii,int>> ordQueries;
vector<ii> queries;

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

    int m; cin>>m;
    fore(i,0,m){
        int k,posj; cin>>k>>posj;
        queries.pb({k,posj});
        ordQueries.pb({{k,posj},i});
    }
    sort(ordQueries.begin(),ordQueries.end());
    ordered_set quer;
    vector<int> answers;
    answers.resize(m);
    int index = 0;
    fore(i,1,n+1){
        quer.insert({pairs[n-i].ss,pairs[n-i].ff});

        while(ordQueries[index].ff.ff == i){
            ii p = *quer.find_by_order(ordQueries[index].ff.ss-1);
            answers[ordQueries[index].ss] = p.ss ;
            index++;
        }
        if(index >= m)
            break;
    }
    fore(i,0,m){
        cout<< answers[i]<<endl;
    }
    return 0;
}
