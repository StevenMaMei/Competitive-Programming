#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef pair<int,int>  ii;
bool initCovered[100001];
int  dp[100001];
vector<ii> bounds;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int n, m; cin>>n>>m;
    for(int i =0; i < n; i++){
        int x,s; cin>>x>>s;
        int x1=x-s;
        int x2=x+s;
        if(x1<0){
            x1=0;
        }
        if(x2>m){
            x2=m;
        }
        bounds.pb({x1,x2});
        for(int j =x1; j<=x2;j++){
            initCovered[j]=true;
        }
    }
    sort(bounds.begin(), bounds.end(), greater<ii>());
    for(int i =m-1; i>= 0;i--){
        int currMin= m-i;
        if(initCovered[i+1]){
            currMin= dp[i+1];
        }else{
            for(int j = 0; j < bounds.size(); j++){
                ii currPair = bounds[j];
                if(currPair.ff > i){
                    int u = (currPair.ff-i-1);
                    int trans= min(m,currPair.ss+u);
                    currMin= min(currMin,u+dp[trans]);
                }else{
                    break;
                }
            }
        }
        dp[i]=currMin;
    }
    cout<<dp[0]<<endl;
    return 0;
}
