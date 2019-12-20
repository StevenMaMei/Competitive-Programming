#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r", stdin);
    #else
     #define endl '\n'
    #endif // LOCAL
    int n; cin>>n;
    map<int,int> cnt;
    fore(i,0,n){
        int x;cin>>x;
        cnt[x]++;
    }
    vector<vector<int>> cnt_by_repeats;
    cnt_by_repeats.resize(n+1);
    for(auto x: cnt){
        cnt_by_repeats[x.ss].pb(x.ff);
    }
    vector<int> geq(n+1);
    geq[n] = cnt_by_repeats[n].size();
    for(int i = n-1; i>= 1; i--){
        geq[i] = geq[i+1] + cnt_by_repeats[i].size();
    }

    int best=0,total=0,bestA=1,bestB;
    for(int i=1; i <= n; i++){
        total += geq[i];
        int tempB = total/ i;
        if(i <= tempB && (i*tempB) > best){
            best = i*tempB;
            bestA = i;
            bestB = tempB;
        }
    }
    vector<vector<int>> r(bestA,vector<int>(bestB));
    int x=0,y=0;
    for(int i = n;i >= 1; i--){
        for(auto val: cnt_by_repeats[i]){
            fore(j,0,min(i,bestA)){
                if(r[x][y] != 0)
                    x = (x+1) % bestA;
                if(r[x][y] == 0)
                    r[x][y] = val;
                x = (x+1)%bestA;
                y = (y+1)%bestB;
            }
        }
    }
    cout<<best<<endl<<bestA<<" "<<bestB<<endl;
    fore(i,0,bestA){
        fore(j,0,bestB){
            cout<< r[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
