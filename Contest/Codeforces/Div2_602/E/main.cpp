#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef pair<int,int> ii;
vector<vector<ii>> centres;
vector<vector<int>> sumRows, sumCols;
int n,m;
int calculate(int x1,int y1, int x2,int y2){
    int ans = sumRows[x2][y2];
    if(x1) ans -= sumRows[x1-1][y2];
    if(y1) ans -= sumRows[x2][y1-1];
    if(x1&&y1) ans += sumRows[x1-1][y1-1];
    return ans;
}
bool can(int t){
    bool ans = true;
    vector<vector<int>> resultMatrix(n,vector<int>(m,1e9));
    queue<ii> q;
    fore(i,0,n){
        fore(j,0,m){
            if(i-t >= 0&&j-t>=0&&j+t < m && i+t < n && calculate(i-t,j-t,i+t,j+t) >= (2*t+1)*(2*t+1)){
                centres[t].pb({i,j});
                q.push({i,j});
                resultMatrix[i][j] = 0;
            }
        }
    }
    while(q.size()){
        int x = q.front().ff; int y = q.front().ss; q.pop();
        if(resultMatrix[x][y] == t) break;
        fore(dx,-1,2) {
            fore(dy,-1,2){
                int nx = x+dx; int ny = y+dy;
                if(nx>=0&&ny>=0 &&nx<n&&ny<m && resultMatrix[nx][ny] > resultMatrix[x][y]+1){
                    resultMatrix[nx][ny] = resultMatrix[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    fore(i,0,n){
        fore(j,0,m){
            if(sumCols[i][j] ==1){
                if( resultMatrix[i][j] == 1e9){
                    ans =false;
                }
            }
        }
    }
    //cout<<"can mid: "<<t<<" "<<ans<<endl;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL
    cin>>n>>m;
    sumRows.resize(n); sumCols.resize(n);
    fore(i,0,n){
        sumRows[i].resize(m);
        sumCols[i].resize(m);
    }
    for(int i =0; i<n;i++){
        for(int j = 0; j<m;j++){
            char curr; cin>> curr;
            sumRows[i][j] += curr == 'X';
            if(i) sumRows[i][j] += sumRows[i-1][j];
            if(j) sumRows[i][j] += sumRows[i][j-1];
            if(i&& j) sumRows[i][j] -= sumRows[i-1][j-1];
            sumCols[i][j] = curr =='X';
        }
    }
    int l = 0; int r = min(n,m);
    centres.resize(r+1);
    int last=0;
    while(l <= r){
       int mid = (l+r)/2;
       //cout<<"mid: "<<mid<<endl;
       if(can(mid)){
         l =  mid +1;
         last = mid;
       }
       else r = mid -1;

    }

    cout<<last<<endl;
    bool res[n][m];
    memset(res,0,sizeof(res));
    for(ii p: centres[last]){
        res[p.ff][p.ss] = 1;
    }
    fore(i,0,n){
        fore(j,0,m){
            char c= res[i][j]==1?'X': '.';
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
