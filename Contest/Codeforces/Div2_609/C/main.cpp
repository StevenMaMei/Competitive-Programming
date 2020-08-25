#include <bits/stdc++.h>

#define fore(i,low,n) for(int i =low;i<n;i++)


using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    string s; cin>>s;
    string c = s;
    bool mayor = false;
    int last = -1;
    fore(i,k,n){

        c[i] = c[i-k];

    }
    fore(i,0,n){
        if(c[i]>s[i]){
            break;
        }
        if(c[i]<s[i]){
            mayor = true;
        }
    }
    if(mayor){
        for(int i = k-1; i>=0;i--){
                //cout<<"jjejej"<<endl;
            if(c[i] != '9'){
                int indx = i;

                c[indx]++;
                //cout<<"c "<<c<<endl;
                for(int j = indx+1; j< k;j++){
                   if(c[j] == '9') c[j] = '0';
                }
               // cout<<c<<endl;
                break;
            }
        }
        fore(i,k,n){
        c[i] = c[i-k];
        }
    }
    cout<<c.size()<<endl;
    cout<<c<<endl;
    return 0;
}
