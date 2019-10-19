#include <iostream>
#include <vector>
using namespace std;

vector<int> z_function(string s)
{
    int n = (int) s.length();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if(i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l= i, r = i + z[i] -1;
    }
    return z;
}

int main()
{
    int n,r,m;
    string t;
    cin >> n;
    cin >> t;
    cin>> r;
    cin>> m;
        int quant= 0;
    for(int r1 = 0; r1 < r; r1++){
        string s;
        cin >> s;
        int n2 = s.length();
        string p1 = s+"$"+t;
        string p2="";
        for(int i = n2-1; i>=0 ;i--){
            p2+= s[i];
        }
        p2+="$";

        for(int i =n-1; i >= 0 ; i--){
            p2+= t[i];
        }
        //cout<< p2<<endl;
        //cout<<p1<<endl;
        vector<int> z1 = z_function(p1);
        vector<int> z2 = z_function(p2);
        for(int i = m+1; i<n+m+1;i++){
            if(i+m-1<n+m+1){
                //cout<< p1[i]<<" "<< p2[n-i+1]<<endl;
               int ii = n-i+m+2;
                //cout<<i<< " "<< ii<<endl;

                if(z1[i]== m || z1[i]== m-1 || z2[ii]==m-1||z1[i]+z2[ii]== m-1){
                    quant++;
                }
            }
        }

    }
        cout<< quant<< endl;
    return 0;
}
