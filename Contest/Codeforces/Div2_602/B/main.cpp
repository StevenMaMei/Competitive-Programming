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
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        stack<int> mins;
        vector<int> vq;
        bool picked[n+1];
        memset(picked,0,sizeof(picked));
        vq.resize(n);
        fore(i,0,n){
            mins.push(n-i);
            cin>>vq[i];
        }
        vector<int> res;
        res.pb(vq[0]);
        int cMax = vq[0];
        picked[vq[0]] = true;
        bool can = true;
        for(int i=1;i<n && can;i++){
            if(cMax < vq[i]){
                cMax = vq[i];
                res.pb(vq[i]);
                picked[vq[i]] = true;
            }else{
                bool stop = false;
                while(!stop){
                    int curr = mins.top();
                    mins.pop();
                    if(!picked[curr]){
                        picked[curr] = true;
                        stop =true;
                        if(curr > cMax){
                            can = false;
                        }else{
                            res.pb(curr);
                        }
                    }
                }
            }
        }
        if(can){
            fore(i,0,n){
                if(i+1 == n){
                    cout<<res[i]<<endl;
                }else{
                    cout<<res[i]<<" ";
                }
            }
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
