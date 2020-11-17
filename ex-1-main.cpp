// ex_1_main_cpp.cpp
#include <iostream>
using namespace std;

#define CPP2_PRIME_UPPER_LIMIT 100//探索する値の上限値

/*    --------------------------------------------------------------- */
/*
*  nth_prime
*
*  与えられた正整数a と d と n に対して、この等差数列に含まれる n 番目の
*  素数を返す。
*
*  TODO: このnth_prime 関数を実装せよ。必要であれば他に関数や
*  ファイルを作成せよ。
*/
/*    -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
    for (int i = 0; a + (d*i) < CPP2_PRIME_UPPER_LIMIT; i++) {
        cout << a + (d*i) << endl;
    }
    return -1;
}

bool is_prime(int num) {
    bool init = true;

    if (num <= 1) 
        return false;
    if (num == 2)
        return true;
    if (num > 2) {
        for (int k = 2; k < num; k++) {
            if (num % k == 0) {
                init = false;
                break;
            }
        }
        return init;
    }
}

int main() {
    // nth_prime(2, 3, 100);
    std::cout << is_prime(1) << std::endl;
    std::cout << is_prime(2) << std::endl;
    std::cout << is_prime(5) << std::endl;
    std::cout << is_prime(11) << std::endl;
    std::cout << is_prime(15) << std::endl;
    //以下、同様に、出力例通りになるか確認せよ。
    return 0;
}
