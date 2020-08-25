#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        if( n-2 >= 0 && s[n-1] == 'o' && s[n-2] == 'p'){
            cout<<"FILIPINO"<<endl;
        }else if(n-4 >= 0 && ((s[n-1] == 'u' && s[n-2] == 's' && s[n-3] == 'e' && s[n-4] == 'd') || (s[n-1] == 'u' && s[n-2] == 's' && s[n-3] == 'a' && s[n-4] == 'm')) ){
            cout<<"JAPANESE"<<endl;
        }else{
            cout<<"KOREAN"<<endl;
        }
    }
    return 0;
}
