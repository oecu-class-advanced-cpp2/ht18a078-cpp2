#include <iostream>
#include <string>
#include <sstream>

namespace cpp2 {
    /* --------------------------------------------------------------------- */
    /*
    mcxi

    mcxi 記法を解析するクラスです。
    */
    /* --------------------------------------------------------------------- */
    class mcxi {
    public:
        /* ----------------------------------------------------------------- */
        /*
        mcxi

        指定された文字列を解析して、オブジェクトを初期化します。
        以下の場合には例外が創出されます。

        1. [2-9,m,c,x,i] 以外の文字が出現した場合
        2. 2 文字続けて数字 (2-9) が出現した場合
        3. m, c, x, i がこの順序で出現しなかった場合
        ただし、例えば mx のように、特定の文字をスキップする事は許容
        されます。
        */
        /* ----------------------------------------------------------------- */
        mcxi(const std::string& s) : value_(0) {
            int num = 0;
            for (auto pos = s.begin(); pos != s.end(); pos++) {
                if (*pos >= '2' && *pos <= '9') {
                    num = *pos - '0';   // char - '0':文字コードを数字になおすテクニック
                }
                else {
                    auto u = unit(*pos);
                    value_ += std::fmax(num, 1) * u;
                    num = 0;
                }
            }
        }


        /* ----------------------------------------------------------------- */
        /*
        operator+

        2 つのオブジェクトの加算結果を取得します。
        */
        /* ----------------------------------------------------------------- */
        mcxi operator+(const mcxi& rhs) {
            // value + valueの計算
            return this->value_ + rhs.value_;
        }
        const mcxi(int value) { this->value_ = value; }

        /* ----------------------------------------------------------------- */
        /*
        to_string

        現在の値を mcxi 記法に変換します。
        */
        /* ----------------------------------------------------------------- */
        std::string to_string() const {
            std::stringstream ss;
            int value = value_;
            int num = value / 1000;
            if (num == 1) {
                ss << 'm';
                value -= num * 1000;
            }
            else if (num >= 2 && num <= 9) {
                ss << num;
                ss << 'm';
                value -= num * 1000;
            }

            num = value / 100;
            if (num == 1) {
                ss << 'c';
                value -= num * 100;
            }
            else if (num >= 2 && num <= 9) {
                ss << num;
                ss << 'c';
                value -= num * 100;
            }

            num = value / 10;
            if (num == 1) {
                ss << 'x';
                value -= num * 10;
            }
            else if (num >= 2 && num <= 9) {
                ss << num;
                ss << 'x';
                value -= num * 10;
            }

            num = value;
            if (num == 1) {
                ss << 'i';
            }
            else if (num >= 2 && num <= 9) {
                ss << num;
                ss << 'i';
            }

         return ss.str();
    }

    private:
        /* ----------------------------------------------------------------- */
        /*
        unit

        単位に対応する値を取得します。
        */
        /* ----------------------------------------------------------------- */
        int unit(char c) {
            switch (c) {
                case 'm':
                    return 1000;
                case 'c':
                    return 100;
                case 'x':
                    return 10;
                case 'i':
                    return 1;
            }
            std::cout << c << "は使用できない文字です" << std::endl;
            return -1;
        }

    private:
        int value_;
    };
}

int main() {
    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    auto result0 = a0 + b0;
    std::cout << "3x" << " " << result0.to_string() << std::endl;

    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    auto result1 = a1 + b1;
    std::cout << "x" << " " << result1.to_string() << std::endl;

    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    auto result2 = a2 + b2;
    std::cout << "6cx" << " " << result2.to_string() << std::endl;

    cpp2::mcxi a3("m2ci");
    cpp2::mcxi b3("4m7c9x8i");
    auto result3 = a3 + b3;
    std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

    cpp2::mcxi a4("9c9x9i");
    cpp2::mcxi b4("i");
    auto result4 = a4 + b4;
    std::cout << "m" << " " << result4.to_string() << std::endl;

    cpp2::mcxi a5("i");
    cpp2::mcxi b5("9m9c9x8i");
    auto result5 = a5 + b5;
    std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

    cpp2::mcxi a6("m");
    cpp2::mcxi b6("i");
    auto result6 = a6 + b6;
    std::cout << "mi" << " " << result6.to_string() << std::endl;

    cpp2::mcxi a7("i");
    cpp2::mcxi b7("m");
    auto result7 = a7 + b7;
    std::cout << "mi" << " " << result7.to_string() << std::endl;

    cpp2::mcxi a8("m9i");
    cpp2::mcxi b8("i");
    auto result8 = a8 + b8;
    std::cout << "mx" << " " << result8.to_string() << std::endl;

    cpp2::mcxi a9("9m8c7xig");
    cpp2::mcxi b9("c2x8i");
    auto result9 = a9 + b9;
    std::cout << "9m9c9x9" << " " << result9.to_string() << std::endl;
}