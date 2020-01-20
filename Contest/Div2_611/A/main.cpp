#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int tt = 24*60;
        int hh,mm; cin>>hh>>mm;
        tt -= hh*60+mm;
        cout<<tt<<endl;
    }
    return 0;
}
