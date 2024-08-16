#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
int n,m;
int main() {
    std::cin >> n >> m;
    std::vector<std::vector<int> > g(n,std::vector<int>(m,0));
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    for(auto& i : g) {
        for(auto& j : i) {
            std::cin >> j;
        }
    } 
    int k = INT_MAX;
    std::function<void(int,int,int)> dfs = [&](int x,int y,int s) {
        if(x >= n || y >= n || x < 0 || y < 0) return ;
        if(g[x][y] == 1) return ;
        if(x == n - 1 && y == m - 1) {
            k = std::min(k,s);
            return ;
        }
        g[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            dfs(x + dx[i],y + dy[i],s + 1);
        }
        g[x][y] = 0;
    };
    dfs(0,0,0);
    std::cout << k << '\n';
    return 0;
}
