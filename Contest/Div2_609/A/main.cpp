#include <bits/stdc++.h>

using namespace std;

const int N = 10000010;
int lp[N+1];
vector<int> pr;
set<int> primes;
int main()
{
    for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }
    for(int i: pr){
        primes.insert(i);
    }
    int n; cin>>n;
    for(int i = n+1; i<1000000000;i++){
        if( primes.count(i) == 0 && i-n >2 && primes.count(i-n) == 0){
            cout<<i<<" "<<i-n<<endl;
            break;
        }
    }
    return 0;
}
