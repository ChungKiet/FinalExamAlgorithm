#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int n, snt[MAX], res = 0;

int main() {
	cin >> n;
	snt[0] = snt[1] = 1;
	// Tạo sàn nguyên tố: 0 - snt, 1 - không phải snt
	for (int i = 2; i <= n; i++) {
		if (snt[i] == 0) {
			for (int j = 2 * i; j <= n; j += i) {
				snt[j] = 1;
			}
		}
	}
	// Tính tống g(i) i = 2..n
	for (int i = 2; i <= n; ++i) {
		// Tìm snt đầu tiên
		for (int p = 3; p <= i; ++p) {
			// Nếu p là snt
			if (snt[p] == 0) {
				// Tính q
				int q = 2 * i - p;
				// Nếu q là snt thì cộng vào kết quả
				if (snt[q] == 0) res++;
			}
		}
	}
	cout << res;
	return 0;
}