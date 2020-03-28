#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll v, n;
    cin >> v >> n;
    for(int i = 1; i < 10; i++){
        ll res=i*v*n;
        ll toRest=res/10;
        toRest*=10;
        ll decider=res-toRest;
        if(decider!=0){
            cout << (toRest/10)+1;
        }else{
            cout << (toRest/10);
        }
        if(i!=9){
            cout << " ";
        }else{
            cout <<"\n";
        }
    }
}
