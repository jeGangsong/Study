#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Package {
    int cnt, price;
    Package() {}
    Package(int c, int p) : cnt(c), price(p) {}
};

struct Product {
    Package smallPackage, bigPackage;
    Product() {}
    Product(const Package& small, const Package& big) : smallPackage(small), bigPackage(big) {}
};

int N, M;
vector<int> needList, haveProduct;
vector<Product> packages;
int ans = 0;

void set() {
    cin >> N >> M;
    needList.resize(N);
    haveProduct.resize(N);
    packages.resize(N);

    for (int i = 0; i < N; i++) {
        int need, have, smallCnt, smallPrice, bigCnt, bigPrice;
        cin >> need >> have >> smallCnt >> smallPrice >> bigCnt >> bigPrice;
        needList[i] = need;
        haveProduct[i] = have;
        packages[i] = Product(Package(smallCnt, smallPrice), Package(bigCnt, bigPrice));
    }
}

bool canMake(int expectBomb) {
    int limitMoney = M;
    for (int i = 0; i < N; i++) {
        int needProduct = (needList[i] * expectBomb) - haveProduct[i];
        if (needProduct > 0) {
            int limit_bigPackage = needProduct / packages[i].bigPackage.cnt;
            if (needProduct % packages[i].bigPackage.cnt != 0)
                limit_bigPackage += 1;

            int limit_smallPackage = needProduct / packages[i].smallPackage.cnt;
            if (needProduct % packages[i].smallPackage.cnt != 0)
                limit_smallPackage += 1;

            int spentMoney = INT_MAX;

            for (int k = 0; k <= limit_bigPackage; k++) {
                for (int z = limit_smallPackage; z >= 0; z--) {
                    if ((k * packages[i].bigPackage.cnt) + (z * packages[i].smallPackage.cnt) >= needProduct) {
                        spentMoney = min(spentMoney, (k * packages[i].bigPackage.price) + (z * packages[i].smallPackage.price));
                        //limit_smallPackage = z;
                    }
                    else {
                        break;
                    }
                }
            }

            limitMoney -= spentMoney;
        }
        if (limitMoney < 0) return false;
    }
    return true;
}

void solve() {
    int left = 0;
    int right = 100;

    while (left <= right) {
        int expectBomb = (left + right) / 2;
        if (canMake(expectBomb)) {
            ans = expectBomb;
            left = expectBomb + 1;
        }
        else {
            right = expectBomb - 1;
        }
    }
    cout << ans << " ";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    set();
    solve();
    return 0;
}
