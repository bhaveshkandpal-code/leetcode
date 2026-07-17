class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        set<pair<int,int>> s;

        for (auto &r : rectangles) {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            area += 1LL * (x2 - x1) * (y2 - y1);

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            vector<pair<int,int>> corners = {
                {x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}
            };

            for (auto &p : corners) {
                if (s.count(p))
                    s.erase(p);
                else
                    s.insert(p);
            }
        }

        if (area != 1LL * (maxX - minX) * (maxY - minY))
            return false;

        if (s.size() != 4)
            return false;

        return s.count({minX, minY}) &&
               s.count({minX, maxY}) &&
               s.count({maxX, minY}) &&
               s.count({maxX, maxY});
    }
};