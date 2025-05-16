#include <iostream>
#include <vector>

using namespace std;

void bresenham_line(int x1, int y1, int x2, int y2, vector<pair<int, int>>& points) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int error = dx - dy;

    while (true) {
        points.push_back({x1, y1});
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int e2 = 2 * error;
        if (e2 > -dy) {
            error -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            error += dx;
            y1 += sy;
        }
    }
}

void draw_rectangle(int x1, int y1, int x2, int y2, vector<pair<int, int>>& points) {
    bresenham_line(x1, y1, x2, y1, points);
    bresenham_line(x2, y1, x2, y2, points);
    bresenham_line(x2, y2, x1, y2, points);
    bresenham_line(x1, y2, x1, y1, points);
}

void draw_circle(int x, int y, int r, vector<pair<int, int>>& points) {
    int x0 = 0;
    int y0 = r;
    int decision = 1 - r;

    while (x0 <= y0) {
        points.push_back({x + x0, y + y0});
        points.push_back({x - x0, y + y0});
        points.push_back({x + x0, y - y0});
        points.push_back({x - x0, y - y0});
        points.push_back({x + y0, y + x0});
        points.push_back({x - y0, y + x0});
        points.push_back({x + y0, y - x0});
        points.push_back({x - y0, y - x0});

        if (decision < 0) {
            decision += 2 * x0 + 1;
        } else {
            decision += 2 * (x0 - y0) + 1;
            y0 -= 1;
        }
        x0 += 1;
    }
}

int main() {
    int x1 = 10, y1 = 20;
    int x2 = 50, y2 = 60;
    int x_center = 30, y_center = 40;
    int radius = 20;

    vector<pair<int, int>> rectangle_points, circle_points;

    draw_rectangle(x1, y1, x2, y2, rectangle_points);
    draw_circle(x_center, y_center, radius, circle_points);

    // Output points or use them for drawing
    for (auto point : rectangle_points) {
        cout << point.first << " " << point.second << endl;
    }

    cout << endl;

    for (auto point : circle_points) {
        cout << point.first << " " << point.second << endl;
    }

    return 0;
}