#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int matrix[1002][1002];
bool checkSquare(int n,int m, int l ){
    bool found = false;
    for(int i = 0 ; i < n && !found; i++){
        for(int j = 0; j < m && !found; j++){
            if(matrix[i][j] >= l){
                int cant = 0;
                for(int k = i; k < i+l &&k<n; k++){
                    if(matrix[k][j] >= l&& k < n){
                        cant++;
                    }
                }
                //cout<< cant<< " "<<l<<endl;
                if(cant == l){
                    found = true;
                    break;
                }
            }
        }
    }
    return found;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int n,m; cin>> n>>m;
    char land[n][m];

    for(int i = 0; i < n; i++){
        char last = ' ';
        int cant = 1;
        for (int j = 0; j < m; j++){
            cin>> land[i][j];
            if(last == land[i][j]){
                cant++;
                matrix[i][j] = cant;
                //cout<< land[i][j]<<endl;
            }else{
                cant = 1;
                last = land[i][j];
                matrix[i][j]= 1;
            }
        }
    }




    int l = 1;
    int r = min(n,m);
    int side = 1;
    while(l<=r){

        int mid = l+(r-l)/2;
        //cout<<mid<<endl;
        bool could = checkSquare(n,m,mid);
        if(could){
            side = mid;
            l= mid+1;
        }else{
            r= mid-1;
        }
    }
    side =side* side;
    cout<< side<<endl;


    return 0;
}
