#include <bits/stdc++.h>

using namespace std;

int row;
int col;

void dfs(vector<vector<int>> &screen, int x, int y, int prevColor, int newColor) {
    screen[y][x] = newColor;
    int delX[] = {-1,0,+1,0};
    int delY[] = {0,+1,0,-1};
    for (int i = 0; i < 4; i++) {
        int newX = x + delX[i];
        int newY = y + delY[i];
        if (newX >= 0 && newX < screen[0].size() && newY >= 0 && newY < screen.size() && screen[newY][newX] == prevColor && screen[newY][newX] != newColor) {
            dfs(screen, newX, newY, prevColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& screen, int x, int y, int newColor) {
    int prevColor = screen[y][x];
    if (prevColor != newColor) {
        dfs(screen, x, y, prevColor, newColor);
    }
    return screen;
}

int main() {
    vector<vector<int>> screen= {  {1, 1, 1},
                                    {1, 1, 0},
                                    {1, 0, 1} };

    row = screen.size();
    col = screen[0].size();

    int x, y;
    cin >> x >> y;
    int newColor = 2;

    screen = floodFill(screen, x, y, newColor);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}
