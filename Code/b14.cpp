#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

int n, a, b;
long long x[MAX], y[MAX];
long long xy[MAX];
long long sumxy[MAX];
long long res = LLONG_MAX;
int doubleAreaOfPolygon(int x[], int y[], int n) {
	int area = 0.0;
	int j = n - 1;
	for (int i = 0; i < n; i++) {
		area += (x[j] + x[i]) * (y[j] - y[i]);
		j = i;
	}
	return abs(area);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	// ta có diện tích của một polygon S(n) = 1/2((x(1).y(2) + x(2).y(3)+ ... + x(n).y(1)) - (x(2).y(1) + x(3).y(2) + ... + x(1).y(n))
	// ta tiến hành lưu từng cặp x(i).y(j) - x(j).y(i)
	for (int i = 1; i < n; ++i) {
		xy[i] = x[i] * y[i + 1] - x[i + 1] * y[i];
	}
	xy[n] = x[n] * y[1] - x[1] * y[n];
	// tính tổng cộng dồn
	for (int i = 1; i <= n; ++i) {
		sumxy[i] = sumxy[i - 1] + xy[i];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 2; j <= n; ++j) {
			if (i != 1 || j != n) {
				long long s = sumxy[j - 1] - sumxy[i - 1] + x[j] * y[i] - x[i] * y[j];
				if (res > llabs(sumxy[n] - 2 * s)) {
					a = i; b = j; res = llabs(sumxy[n] - 2 * s);
				}
			}
		}
	cout << a << " " << b;
	return 0;
}