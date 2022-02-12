#include <bits/stdc++.h>
using namespace std;

class MyPoint
{
public:
    long long x;
    long long y;
    int index;

    MyPoint()
    {
        x = y = index = 0;
    }

    MyPoint(long long x, long long y, int index)
    {
        this->x = x;
        this->y = y;
        this->index = index;
    }

    bool operator==(const MyPoint &p) const
    {
        return x == p.x && y == p.y;
    }

    bool operator!=(const MyPoint &p) const
    {
        return !(*this == p);
    }

    friend istream &operator>>(istream &is, MyPoint &point)
    {
        is >> point.x >> point.y;
        return is;
    }

    friend ostream &operator<<(ostream &os, const MyPoint &point)
    {
        os << "{x: " << point.x << " y: " << point.y << '}';
        return os;
    }
};

vector<MyPoint> points;

MyPoint findLeftBottom(vector<MyPoint> &points)
{
    int bottomLeft = 0;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].x < points[bottomLeft].x)
        {
            bottomLeft = i;
        }
        else if (points[i].x == points[bottomLeft].x)
        {
            if (points[i].y < points[bottomLeft].y)
            {
                bottomLeft = i;
            }
        }
    }
    return points[bottomLeft];
}

MyPoint bottomLeft;

long long dientich(MyPoint A, MyPoint B, MyPoint C) {
    return (B.x - A.x)*(B.y+A.y) + (C.x - B.x)*(C.y+B.y) + (A.x - C.x)*(A.y+C.y);
}

bool cmp(MyPoint p1, MyPoint p2) {
    return dientich(p1, bottomLeft, p2) < 0;
}

pair<int, int> splitPoints()
{
    // Tim diem ben trai nhat o duoi
    bottomLeft = findLeftBottom(points);

    // Sap xep cac diem
    sort(points.begin(), points.end(), cmp);
    // Tra ve cap dinh can tim
    return make_pair(bottomLeft.index, points[points.size() / 2].index);
}

int main(int argc, char const *argv[])
{
    int n, x, y;
    // Input
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        points.push_back(MyPoint(x, y, i));
    }
    // Output
    pair<int,int> ans = splitPoints();
    cout << ans.first << endl;
    cout << ans.second;
    return 0;
}
