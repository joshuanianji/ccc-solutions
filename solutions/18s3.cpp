#include <bits/stdc++.h>

using namespace std;

char grid[101][101];
int seen[101][101];
int cnlock[101][101]{0};

vector<tuple<int, int>> empties;
deque<tuple<int, int, int>> q;

int n, m;
int sx, sy;

tuple<int, int> direction(char c) {
    if (c == 'L') {
        return {0, -1};
    }
    if (c == 'R') {
        return {0, 1};
    }
    if (c == 'U') {
        return {-1, 0};
    }
    if (c == 'D') {
        return {1, 0};
    } else {
        return {0, 0};
    }
}

void add_loc(int x, int y, int prio) {
    //printf("%d, %d -> %d\n", x, y, prio);

    if (x < n && x >= 0 && y < m && y >= 0) {
        if (cnlock[x][y] || grid[x][y] == 'W' || grid[x][y] == 'c' || grid[x][y] == 'C') return;

        if (grid[x][y] == '.') {
            q.push_back({prio - 1, x, y});
        } else {
            int dx, dy;
            tie(dx, dy) = direction(grid[x][y]);
            if (dx != 0 || dy != 0) {
                cnlock[x][y] = 1;
                add_loc(x + dx, y + dy, prio);
                cnlock[x][y] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            seen[i][j] = -1;
            char c;
            
            cin >> c;

            if (c == '.') {
                empties.push_back({i, j});
            } else if (c == 'S') {
                sx = i;
                sy = j;
            }
            
            grid[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == 'C') {
                for (int k = i; k < n  && grid[k][j] != 'W'; k++) if (grid[k][j] == '.' || grid[k][j] == 'S') grid[k][j] = 'c';
                for (int k = i; k >= 0 && grid[k][j] != 'W'; k--) if (grid[k][j] == '.' || grid[k][j] == 'S') grid[k][j] = 'c';
                for (int k = j; k < m  && grid[i][k] != 'W'; k++) if (grid[i][k] == '.' || grid[i][k] == 'S') grid[i][k] = 'c';
                for (int k = j; k >= 0 && grid[i][k] != 'W'; k--) if (grid[i][k] == '.' || grid[i][k] == 'S') grid[i][k] = 'c';
            }
        }
    }

    
    q.push_back({0, sx, sy});

    while (!q.empty()) {
        int prio, x, y;
        tie(prio, x, y) = q.front();
        q.pop_front();

        if (grid[x][y] == 'c') continue;

        if (seen[x][y] != -1) continue;

        add_loc(x + 1, y, prio);
        add_loc(x - 1, y, prio);
        add_loc(x, y + 1, prio);
        add_loc(x, y - 1, prio);
        //printf("M %d, %d -> %d\n", x, y, prio);

        seen[x][y] = -prio;
    }

    for (tuple<int, int> p : empties) {
        int x, y;
        tie(x, y) = p;
        cout << seen[x][y] << endl;
    }

}