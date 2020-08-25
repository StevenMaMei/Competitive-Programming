#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,s,v,j,f,ss; cin>>t>>s>>v>>j>>f>>ss;
    int total = 0;
    if(f>ss){
        int cant = min(t,j);
        total += f*cant;
        j -= cant;
        cant = min(min(s,v),j);
        total += ss*cant;
    }else{
        int cant = min(min(s,v),j);
        total += ss*cant;
        j -= cant;
        cant = min(t,j);
        total += f*cant;
    }
    cout<<total<<endl;
    return 0;
}
