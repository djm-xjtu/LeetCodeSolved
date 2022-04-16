class Solution {
public:
    vector<vector<bool>> st;
    int n, m;

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i ++ )
        {
            vector<bool> temp;
            for (int j = 0; j < m; j ++ )
                temp.push_back(false);
            st.push_back(temp);
        }

        for (int i = 0; i < n; i ++ )
        {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }
        for (int i = 0; i < m; i ++ )
        {
            if (board[0][i] == 'O') dfs(0, i, board);
            if (board[n - 1][i] == 'O') dfs(n - 1, i, board);
        }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!st[i][j])
                    board[i][j] = 'X';
    }

    void dfs(int x, int y, vector<vector<char>>&board)
    {
        st[x][y] = true;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && board[a][b] == 'O')
                dfs(a, b, board);
        }
    }
};