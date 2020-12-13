// ex-1_main.cpp
#include <iostream>
using namespace std;

#define CPP2_PRIME_UPPER_LIMIT 10000000//探索する値の上限値

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

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
    int count_prime = 0;
    for (int i = 0; a + (d*i) < CPP2_PRIME_UPPER_LIMIT; i++) {
        if (is_prime(a + d*i) == true) {
            count_prime++;
            if (count_prime == n) {
                return a + (d*i);
            }
        }
    }
}

int main() {
//以下、同様に、出力例通りになるか確認せよ。
    std::cout << "Input: 367,186,151 Output: 92809 result: "
    << nth_prime(367, 186, 151) << endl;

    std::cout << "Input: 179,10,203 Output: 6709 result: "
        << nth_prime(179, 10, 203) << endl;

    std::cout << "Input: 271,37,39 Output: 12037 result: "
        << nth_prime(271, 37, 39) << endl;

    std::cout << "Input: 103,230,1 Output: 103 result: "
        << nth_prime(103,230,1) << endl;
    
    std::cout << "Input: 27,104,185 Output: 93523 result: "
        << nth_prime(27, 104, 185) << endl;

    std::cout << "Input: 253,50,85 Output: 14503 result: "
        << nth_prime(253, 50, 85) << endl;

    std::cout << "Input: 1,1,1 Output: 2 result: "
        << nth_prime(1, 1, 1) << endl;

    std::cout << "Input: 9075,337,210  Output: 899429 result: "
        << nth_prime(9075, 337, 210) << endl;

    std::cout << "Input: 307,24,79  Output: 5107 result: "
        << nth_prime(307, 24, 79) << endl;

    std::cout << "Input: 331,221,177 Output: 412717 result: "
        << nth_prime(331, 221, 177) << endl;

    std::cout << "Input: 259,170,40  Output: 22699 result: "
        << nth_prime(259, 170, 40) << endl;

    std::cout << "Input: 269,58,102 Output: 25673 result: "
        << nth_prime(269, 58, 102) << endl;

    // 入出力例確認済み

    return 0;
}
