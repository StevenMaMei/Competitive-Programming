#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxi = -1;
    int idxMax = -1;
    for (int i = 0; i < n; i++){
        int act;
        cin >> act;
        if (act > maxi){
            maxi = act;
            idxMax = i;
        }
    }
    if (idxMax == 0)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
