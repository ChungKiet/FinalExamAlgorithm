#include <bits/stdc++.h>
using namespace std;

map<int, int> mp; //Dung de luu tru id va gia tri so nguyen tuong ung hoan vi cua day
vector<int> f; //Dung de luu lai so buoc it nhat de co the chuyen toi trang thai tuong ung cua id

//Khoi tao map
void initMp(int n) {
    vector<int> a(n);
    //Khoi tao mang a gom cac so tu 1 -> n
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }
    int id = 1;
    //Thuc hien cap nhat id va gia tri bien s tuong ung voi id bang hoan vi cua mang a
    do {
        int s = 0;
        for (int i : a) s = s * 10 + i;
        mp[s] = id++;
    } while (next_permutation(a.begin(), a.end()));
}

//Tu trang thai cua mang a tra lai id cua hoan vi duoc luu trong map
int getId(vector<int> a) {
    int s = 0;
    for (int i : a) s = s * 10 + i;
    return mp[s];
}

//Thuc hien vet can cac hoan vi
void bruteForce(vector<int> a, int c) {

    //Lay id cua hoan vi tuong ung voi trang thai cua mang a
    int id = getId(a);

    //Khi so lan chuyen moi nho hon gia tri ban dau thi gan gia tri
    //Nguoc lai thi dung vet can truong hop do
    if (f[id] > c) f[id] = c;
    else return;

    //Khi tim duoc trang thai tang dan thi dung vet can truong hop do
    if (id == 1) return;

    // Thuc hien vet can hoan vi tat ca cac vi tri cua mang a
    for (int i = 1; i < a.size(); i++) {
        //Thuc hien hoan vi mang a tai vi tri i
        for (int j = 0; j < (i + 1) / 2; j++) {
            swap(a[j], a[i - j]);
        }
        //Goi de quy vet can lan tiep theo
        bruteForce(a, c + 1);
        //Thuc hien hoan vi mang a tai vi tri i
        for (int j = 0; j < (i + 1) / 2; j++) {
            swap(a[j], a[i - j]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        a[i] = tmp;
    }
    //Khoi tao map voi n la so luong phan tu cua a
    initMp(n);
    //Khoi tao mang f voi so luong phan tu 8! ~ 50000
    f = vector<int>(50000, INT_MAX);
    //Thuc hien vet can
    bruteForce(a, 0);
    //Ta co trang thai dau tien cua f la trang thai sap xep tang dan
    // => in ra f[1]
    cout << f[1];
}
