#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low;low<n;i++)
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
    map<int,int> quants;
    cin>>quants[0]>>quants[1]>> quants[2]>> quants[3];
    int total = quants[0] + quants[1] +quants[2]+quants[3];

    for(int i = 0; i< quants.size(); i++){
        if(quants[i]){
            auto qa = quants;
            vector<int> res;
            qa[i]--;
            res.pb(i);
            int last = i;
            for(int j = 0; j< total-1;j++){
                if(qa[last-1]){
                    res.pb(last - 1);
                    qa[last - 1]--;
                    last--;
                }else if(qa[last + 1]){
                    res.pb(last + 1);
                    qa[last + 1]--;
                    last++;
                }else{
                    break;
                }
            }
            if(res.size() == total){
                cout<<"YES"<<endl;
                for(int j = 0; j < res.size(); j++){
                    if(j+1 == res.size()){
                        cout<<res[j]<<endl;
                    }else{
                        cout<< res[j]<<" ";
                    }
                }
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
