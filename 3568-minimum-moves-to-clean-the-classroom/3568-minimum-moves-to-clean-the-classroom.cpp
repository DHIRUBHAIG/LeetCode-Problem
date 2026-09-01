class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;

        // Give every litter cell a unique index
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // All litter collected
        if (litterCount == 0)
            return 0;

        int fullMask = (1 << litterCount) - 1;

        /*
            State:
            row, col      -> current position
            energyLeft    -> remaining energy
            mask          -> collected litter

            visited[r][c][energy][mask]
        */

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // BFS queue:
        // {row, col, remaining energy, mask}
        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                // No energy left -> cannot move
                if (e == 0)
                    continue;

                for (int dir = 0; dir < 4; dir++) {

                    int nr = r + dr[dir];
                    int nc = c + dc[dir];

                    // Outside classroom
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[nr][nc];
                        newMask |= (1 << id);
                    }

                    // Recharge
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Already visited this state
                    if (visited[nr][nc][newEnergy][newMask])
                        continue;

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        // Impossible
        return -1;
    }
};