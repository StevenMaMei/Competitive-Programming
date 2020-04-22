#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> lp(n+1,-1);
    for(int i=2;i<=n;i++){
        if(lp[i]==-1){
            for(int j=i;j<=n;j+=i){
                if(lp[j]==-1){
                    lp[j] = j/i;
                }
            }
        }
    }
    lp[1]=1;

    sort(lp.begin(),lp.end());
    for(int i=2;i<=n;i++){
        cout<<lp[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
