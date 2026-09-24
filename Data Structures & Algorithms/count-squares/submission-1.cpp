class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> grid{};

    
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        grid[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        if (!grid.contains(point[0]))
            return 0;

        int res = 0;
        for (auto& pp : grid){
            if (pp.first == point[0])
                continue;
            if (!pp.second.contains(point[1]))
                continue;            
            
            int d = point[0] - pp.first;
            int x = pp.second[point[1]];
            int y = point[1] + d;

            if (pp.second.contains(y))
                if (grid[point[0]].contains(y))
                    res += x * pp.second[y] * grid[point[0]][y];

            y = point[1] - d;
            if (pp.second.contains(y))
                if (grid[point[0]].contains(y))
                    res += x * pp.second[y] * grid[point[0]][y];
        
        }
        return res;
    }
};
