#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int> >& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = 1000000000;
            }
        }



        dp[0][0] = grid[0][0];
        pair<int,int> s[3]={{1,0},{0,1},{1,1}};
        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }



        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                for(auto x : s){
                    int l = i-x.first;
                    int k = j-x.second;
                    if(l>=m || k>=n) break;
                    dp[i][j] = min(dp[i][j], dp[l][k]+grid[i][j]);
                }
            }
        }

        return dp[m-1][n-1];
    }


int main(){

vector <vector<int> > grid;

 int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        vector<int> v1;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            v1.push_back(x);
        }
    grid.push_back(v1);
    }


cout << minPathSum(grid) ;

return 0;
}
