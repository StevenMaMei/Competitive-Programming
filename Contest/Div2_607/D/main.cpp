#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int t; cin>>t;
    while(t--){
        int r,c; cin>>r>>c;
        int org[r][c];
        fore(i,0,r){
            fore(j,0,c){
                char cc;cin>>cc;
                if(cc == 'A'){
                    org[i][j]=1;
                }else{
                    org[i][j] = 0;
                }
            }
        }
        //int sumPerRows[r][c];
        //int sumPerCols[r][c];
        //memset(sumPerCols,0,sizeof(sumPerCols));
        //memset(sumPerRows,0,sizeof(sumPerRows));
        vector<vector<int>> sumPerRows(r,vector<int>(c));
        vector<vector<int>> sumPerCols(r,vector<int>(c));
        fore(i,0,r){
            fore(j,0,c){
                if(j-1 >= 0){
                    sumPerRows[i][j] = sumPerRows[i][j-1];
                }
                sumPerRows[i][j] += org[i][j];
                if(i-1 >= 0){
                    sumPerCols[i][j] = sumPerCols[i-1][j];
                }
                sumPerCols[i][j] += org[i][j];
            }
        }
        int cant = 0;
        fore(j,0,c) cant+= sumPerCols[r-1][j];

        if(cant == 0){
            cout<<"MORTAL"<<endl;
        }else if(cant == r*c){
            cout<<"0"<<endl;
        }else{
            if(sumPerRows[0][c-1] == c || sumPerRows[r-1][c-1] == c || sumPerCols[r-1][0] == r || sumPerCols[r-1][c-1]== r){
                cout<<"1"<<endl;
            }else{
                bool exist = false;
                fore(i,0,r) if(sumPerRows[i][c-1] == c){exist = true; break;}
                fore(j,0,c) if(sumPerCols[r-1][j] == r){exist = true; break;}
                //exit(0);
                if(exist || org[0][0] == 1 || org[0][c-1] == 1 || org[r-1][0] == 1 || org[r-1][c-1] == 1){
                    cout<<"2"<<endl;
                }else{
                    if(sumPerRows[0][c-1] >= 1 || sumPerRows[r-1][c-1] >=1 || sumPerCols[r-1][0] >= 1 || sumPerCols[r-1][c-1] >= 1){
                        cout<<"3"<<endl;
                    }else{
                        cout<<"4"<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
