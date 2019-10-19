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
    for(int r1 = 0; r1 < r; r1++){
        string s;
        cin >> s;
    }
    return 0;
}
