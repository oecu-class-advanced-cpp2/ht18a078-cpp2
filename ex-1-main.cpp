#include <iostream>

#define CPP2_PRIME_UPPER_LIMIT 10000000 //探索する値の上限値

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
}

 int main(){
     std:cout << nth_prime(367, 186, 151) << std:endl;
     //以下、同様に、出力例通りになるか確認せよ。
     return 0;
 }
