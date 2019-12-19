#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        string n; cin >>n;
        int quant = 0;
        quant += (n.size()-1)*9;
        quant += (n[0] -'0');
        bool must =false;
        if(n.size()>= 2 &&n[0] == n[1]){
            for(int i = 1; i< n.size();i++){
                if(n[0]>n[i]){
                    must =true;
                    break;
                }else if( n[0] < n[i]){
                    break;
                }
            }

        }else if(n.size()>= 2 && n[0] > n[1]){
            must = true;
        }
        if(must) quant--;
        cout<<quant<<endl;
    }
    return 0;
}
