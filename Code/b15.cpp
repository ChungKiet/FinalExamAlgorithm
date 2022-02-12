#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.141592653589793

using namespace std;

double distant(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    double x1 = 1, y1 = 2, x2 = 3, y2 = 4, R = 2;
    cin >> x1 >> y1 >> x2 >> y2 >> R;

    double d = distant(x1, x2, y1, y2);

    double part1 = R * R * acos((d*d + R*R - R*R)/(2*d*R));
    double part2 = R * R * acos((d*d + R*R - R*R)/(2*d*R));
    double part3 = 0.5 * sqrt((-d+R+R)*(d+R-R)*(d-R+R)*(d+R+R));

    double intersectionArea = part1 + part2 - part3;

    double circleArea = PI * R * R;

    cout << setprecision(3) << fixed << 2 * circleArea - intersectionArea;
}
