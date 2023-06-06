#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Point {
    int x, y;
};

struct PathPoint {
    Point point;
    int cost;

    PathPoint(Point p, int c) : point(p), cost(c) {}
};

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

vector<Point> findShortestPath(vector<vector<int>>& costs) {
    int n = costs.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<Point>> prev(n, vector<Point>(n));

    dist[0][0] = 0;

    auto compare = [](const PathPoint& p1, const PathPoint& p2) {
        return p1.cost > p2.cost;
    };
    priority_queue<PathPoint, vector<PathPoint>, decltype(compare)> pq(compare);
    pq.push(PathPoint({ 0, 0 }, 0));

    while (!pq.empty()) {
        PathPoint cur = pq.top();
        pq.pop();

        Point curPoint = cur.point;
        int curCost = cur.cost;

        if (visited[curPoint.x][curPoint.y])
            continue;

        visited[curPoint.x][curPoint.y] = true;

        if (curPoint.x == n - 1 && curPoint.y == n - 1) {
            vector<Point> path;
            Point p = { n - 1, n - 1 };
            while (p.x != 0 || p.y != 0) {
                path.push_back(p);
                p = prev[p.x][p.y];
            }
            path.push_back({ 0, 0 });
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curPoint.x + dx[i];
            int ny = curPoint.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                !visited[nx][ny] && curCost + costs[nx][ny] < dist[nx][ny]) {
                dist[nx][ny] = curCost + costs[nx][ny];
                prev[nx][ny] = curPoint;
                pq.push(PathPoint({ nx, ny }, dist[nx][ny]));
            }
        }
    }

    return vector<Point>();
}

void printCosts(vector<vector<int>>& costs) {
    int n = costs.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }
}

void printPath(vector<Point>& path) {
    for (const auto& p : path) {
        cout << p.x * 5 + p.y << " ";
    }
    cout << endl;
}

int main333() {
    vector<vector<int>> costs(5, vector<int>(5));
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> costs[i][j];
        }
    }

   
    vector<Point> path = findShortestPath(costs);

 
    if (!path.empty()) {
        printPath(path);
    }

    return 0;
}
