class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startX = r;
                    startY = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }
        
        int totalLitter = litters.size();
        int targetMask = (1 << totalLitter) - 1;
        
        // Map litter coordinates to bit index
        auto getLitterIndex = [&](int r, int c) {
            for (int i = 0; i < totalLitter; ++i) {
                if (litters[i].first == r && litters[i].second == c) return i;
            }
            return -1;
        };

        // maxEnergy[r][c][mask] stores the maximum remaining energy seen for state (r, c, mask)
        vector<vector<vector<int>>> maxEnergy(m, vector<vector<int>>(n, vector<int>(1 << totalLitter, -1)));

        // BFS Queue: stores tuple of {r, c, mask, current_energy, steps}
        queue<tuple<int, int, int, int, int>> q;

        // Check starting cell
        int initialMask = 0;
        int initialEnergy = energy;
        
        q.push({startX, startY, initialMask, initialEnergy, 0});
        maxEnergy[startX][startY][initialMask] = initialEnergy;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c, mask, e, steps] = q.front();
            q.pop();

            if (mask == targetMask) {
                return steps;
            }

            if (e <= 0) continue; // Out of energy to make the next move

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int nextMask = mask;
                    int nextEnergy = e - 1;

                    char cell = classroom[nr][nc];

                    if (cell == 'L') {
                        int idx = getLitterIndex(nr, nc);
                        if (idx != -1) {
                            nextMask |= (1 << idx);
                        }
                    } else if (cell == 'R') {
                        nextEnergy = energy; // Reset energy to full capacity
                    }

                    // Only push if we reached this state with strictly more energy
                    if (nextEnergy > maxEnergy[nr][nc][nextMask]) {
                        maxEnergy[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, nextEnergy, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};