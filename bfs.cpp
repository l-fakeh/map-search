#include<iostream>
#include<vector>
#include<functional>
#include<queue>
typedef std::pair<int,int> PII;
int n,m;
int main() {
    std::cin >> n >> m;
    std::vector<std::vector<int> > g(n, std::vector(m,0));
    std::vector<std::vector<int> > dis(n, std::vector(m,0));
    for(auto row : g) {
        for(auto ch : row) {
            std::cin >> ch;
        }
    }
    std::queue<PII> q;
    std::function<int()> bfs = [&]() ->int  {
        int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
        q.push({0,0});
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i ++) {
                int x = t.first + dx[i],y = t.second + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && dis[x][y] == 0) {
                    q.push({x,y});
                    dis[x][y] = dis[t.first][t.second] + 1;
                }
        }
        }
        return dis[n - 1][m - 1] ? dis[n - 1][m - 1] : -1;
    };
    std::cout << bfs() << '\n';
    return 0;
}