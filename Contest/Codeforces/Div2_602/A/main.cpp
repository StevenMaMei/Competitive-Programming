#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)


using namespace std;
typedef pair<int,int> ii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ii> intervals;
        intervals.resize(n);
        fore(i,0,n){
            int a,b; cin>>a>>b;
            intervals[i] = {b,a};
        }
        sort(intervals.begin(),intervals.end());
        int a = intervals[0].ff;
        int b = a;
        fore(i,1,n){
            ii p = intervals[i];
            if(b>=p.ss && b <= p.ff){

            }else{
                b = p.ss;
            }
        }
        cout<<b-a<<endl;

    }
    return 0;
}
