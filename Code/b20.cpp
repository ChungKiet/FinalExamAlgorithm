#include<bits/stdc++.h>
#define MAX 24
using namespace std;

string s1;
long long a[MAX];
long long fac[MAX];
bool mem[MAX];
long long stt;
int y, n = 1;
int main() {
	// đề cho thiếu n nên dùng getline 
	getline(cin, s1);
	cin >> y;
	stringstream X(s1); 
	string tmp;
	while (getline(X, tmp, ' ')) {
		a[n] = stoi(tmp);
		++n;
	}
	--n;
	// tính mảng fac[i] là mảng i!
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i;
	}
	// cho hoán vị tìm thứ tự
	// xét mỗi số trong hoán vị được cho a[1]...a[n]
	// ta đếm được số các hoán vị mà (giá trị tại vị trí i) < a[i]
	// bằng cách lấy stt += (a[i] - 1 - (count(số nhỏ hơn a[i] đã xuất hiện trước đó)))*(n-i)!
	for (int i = 1; i <= n; ++i) {
		long long tmp = a[i] - 1;
		for (int j = 1; j < i; ++j) {
			if (tmp == 0) break;
			if (a[j] < a[i]) --tmp;
		}
		stt += tmp * fac[n - i];
	}
	cout << ++stt << "\n";
	// để làm chiều ngược lại, ta dùng một mảng mem với mem[i] = true tương đương với i đã xuất hiện
	// tmp được tính bằng việc lấy y % (n-i)!
	// số thứ i cần tìm là số thứ tmp của các số chưa xuất hiện, vd: chưa xuất hiện = {1, 3}, tmp = 2 thì số cần tìm là 3.
	// cập nhật lại y = y - (tmp - 1) * (n-i)! để cho lượt i+1 sau
	mem[0] = MAX;
	for (int i = 1; i <= n; ++i) {
		long long tmp = y / fac[n - i];
		if (y % fac[n - i] != 0) ++tmp;
		long long res, count = tmp;
		for (res = 1; count > 0; ++res) {
			if (!mem[res]) --count;
			if (count == 0) break;
		}
		cout << res << " ";
		mem[res] = true;
		y = y - (tmp - 1) * fac[n - i];
	}
	return 0;
}