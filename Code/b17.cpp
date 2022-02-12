/* Ý tưởng: liệt kê các số có không quá 9 chữ số thỏa m chỉ chứa các chữ số {0,1} ( ==> tối đa 2^9 số)
            Sau đó kiểm tra xem có chia hết cho n không

            Để liệt kê tăng dần, sử dụng tính chất số nhị phân
*/
#include <iostream>

using namespace std;



int main(){
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int max = 511;     //  511 = 2^9 - 1
    for (int i = 1; i <= max; i++) {
        int m=0, d10 = 1;
        for (int j = i; j > 0; j /= 2) {      // Vòng lặp này chuyển số i thành số m tương ứng
            m += j % 2 * d10;
            d10 *= 10;
        }
        cout << m << endl;
        if (m % n == 0) {       // Tìm được số thoả mãn
            cout << m;
            return 0;
        }
    }
    // Nếu hết vòng lặp mà không tìm được số thoả mãn
    cout << "Khong tim thay so thoa man";
    return 0;
}
