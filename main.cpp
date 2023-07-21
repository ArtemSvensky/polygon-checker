#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Point {
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}
};

struct Line {
    Point start;
    Point end;

    Line(Point start, Point end) : start(start), end(end) {}
};

class Polygon {
public:
    Polygon(const std::string& polygonData) {
        std::istringstream iss(polygonData);
        double x, y;
        while (iss >> x >> y) {
            vertices.push_back(Point(x, y));
        }
    }

    bool contains(const Point& p) const {
        int i, j;
        bool c = false;
        for (i = 0, j = vertices.size() - 1; i < vertices.size(); j = i++) {
            if (((vertices[i].y > p.y) != (vertices[j].y > p.y)) &&
                (p.x < (vertices[j].x - vertices[i].x) * (p.y - vertices[i].y) / (vertices[j].y - vertices[i].y) + vertices[i].x)) {
                c = !c;
            }
        }
        return c;
    }

private:
    std::vector<Point> vertices;
};

int main() {
    std::ifstream polyFile("polys.txt");
    if (!polyFile) {
        std::cerr << "Failed to open polys.txt" << std::endl;
        return 1;
    }

    std::string polygonData;
    std::getline(polyFile, polygonData);
    Polygon polygon(polygonData);
    polyFile.close();

    std::ifstream lineFile("lines.txt");
    if (!lineFile) {
        std::cerr << "Failed to open lines.txt" << std::endl;
        return 1;
    }

    std::ofstream resultFile("results.txt");
    if (!resultFile) {
        std::cerr << "Failed to open results.txt" << std::endl;
        return 1;
    }

    std::string lineData;
    while (std::getline(lineFile, lineData)) {
        std::istringstream iss(lineData);
        double x1, y1, x2, y2;
        iss >> x1 >> y1 >> x2 >> y2;
        Line line(Point(x1, y1), Point(x2, y2));

        bool startInside = polygon.contains(line.start);
        bool endInside = polygon.contains(line.end);

        if (startInside && endInside) {
            resultFile << "0\n"; // Both points are inside the polygon.
        } else if (!startInside && !endInside) {
            resultFile << "3\n"; // Both points are outside the polygon.
        } else if (startInside || endInside) {
            resultFile << "2\n"; // One point is inside, the other is outside the polygon.
        }
    }

    lineFile.close();
    resultFile.close();
    std::cout << "Task completed successfully. Results are written to results.txt" << std::endl;

    return 0;
}
