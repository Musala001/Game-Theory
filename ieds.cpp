#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> mat(n, vector<pair<int,int>>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            int a,b;
            cin >> a;
            cin >> c;
            cin >> b;
            mat[i][j]={a,b};
        }
    }
    vector<int> rows(n), cols(n);
    iota(rows.begin(), rows.end(), 0);
    iota(cols.begin(), cols.end(), 0);
    bool turn=0;
    while(rows.size()>1){
        if(turn==0){
            for(int i=0;i<rows.size();i++){
                bool dominated=false;
                for(int j=0;j<rows.size();j++){
                    if(i==j) continue;
                    bool d=true;
                    for(int k:cols){
                        if(mat[rows[i]][k].first>=mat[rows[j]][k].first){
                            d=false; break;
                        }
                    }
                    if(d){ dominated=true; break; }
                }
                if(dominated){ rows.erase(rows.begin()+i); break; }
            }
        } else {
            for(int i=0;i<cols.size();i++){
                bool dominated=false;
                for(int j=0;j<cols.size();j++){
                    if(i==j) continue;
                    bool d=true;
                    for(int k:rows){
                        if(mat[k][cols[i]].second>=mat[k][cols[j]].second){
                            d=false; break;
                        }
                    }
                    if(d){ dominated=true; break; }
                }
                if(dominated){ cols.erase(cols.begin()+i); break; }
            }
        }
        turn=!turn;
    }
    cout << mat[rows[0]][cols[0]].first << "," << mat[rows[0]][cols[0]].second << endl;
}