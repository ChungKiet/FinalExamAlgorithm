#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
    int S;
    cin >> S;
    //Bien kiem tra xem co ton tai loi giai khong
    bool check = false;
    //Tim canh cua hinh vuong
    int a = sqrt(S);
    int x, y;
    //Duyet qua het cac gia tri co the co de tim x^2 + y^2 = a^2
    for (int i = 0; i <= a; i++) {
        int hieu = S - i * i;
        int j = sqrt(hieu);
        //La tong binh phuong cua hai so nguyen duong thi tao duoc hinh vuong
        if (j * j + i * i == S) {
            check = true;
            //Gan x la j 
            x = j;
            //Gan y là i
            y = i;
        }
    }
//In ra thu tu cac dinh theo nguoc chieu kim dong ho
    if (check == true) {
        cout << 0 << " " << 0 << endl;
        cout << x << " " << -y << endl;
        cout << x + y << " " << -y + x << endl;
        cout << y << " " << x << endl;
    }
    else {
        cout << "IMPOSSIBLE";
    }
}
