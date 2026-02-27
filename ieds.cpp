#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> mat(n, vector<pair<int,int>>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string s;
            cin >> s;
            int pos = s.find(',');
            int a = stoi(s.substr(0,pos));
            int b = stoi(s.substr(pos+1));
            mat[i][j] = {a,b};
        }
    }

    vector<int> rows(n), cols(n);
    iota(rows.begin(), rows.end(), 0);
    iota(cols.begin(), cols.end(), 0);

    bool turn = 0;
    while(rows.size()>1 || cols.size()>1){
        if(turn==0 && rows.size()>1){
            for(int i=0;i<rows.size();i++){
                bool dominated = false;
                for(int j=0;j<rows.size();j++){
                    if(i==j) {
                        continue;
                    }
                    bool less = true;
                    for(int c:cols){
                        if(mat[rows[i]][c].first >= mat[rows[j]][c].first){
                            less = false;
                            break;
                        }
                    }
                    if(less){
                        dominated = true;
                        break;
                    }
                }
                if(dominated){
                    rows.erase(rows.begin()+i);
                    break;
                }
            }
        }
        else if(turn==1 && cols.size()>1){
            for(int i=0;i<cols.size();i++){
                bool dominated = false;
                for(int j=0;j<cols.size();j++){
                    if(i==j) continue;
                    bool less = true;
                    for(int r:rows){
                        if(mat[r][cols[i]].second >= mat[r][cols[j]].second){
                            less = false;
                            break;
                        }
                    }
                    if(less){
                        dominated = true;
                        break;
                    }
                }
                if(dominated){
                    cols.erase(cols.begin()+i);
                    break;
                }
            }
        }
        turn = 1-turn;
    }

    cout << mat[rows[0]][cols[0]].first << "," << mat[rows[0]][cols[0]].second << endl;
}