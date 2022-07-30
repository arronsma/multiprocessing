#include <iostream>
#include <cmath>//sqrt
#include <iostream>
#include <iomanip>//format output
#include <chrono>
#include <thread>//for faster code
#include <mutex>//for faster code
#include <sstream>//stringstream
using namespace std::chrono;//time_piont duration
using namespace std;

//test helper function begin 测试辅助代码开始
void check_do(bool b, int line = __LINE__)
{
    if (b) { cout << "line:" << line << " Pass" << endl; }
    else { cout << "line:" << line << " Ohh! not passed!!!!!!!!!!!!!!!!!!!!!!!!!!!" << " " << endl; exit(0); }
}
#define check(msg)  check_do(msg, __LINE__);
//test helper function end 测试辅助代码结束

//do not change this function! 不要修改这个函数
//if you want to check a number is prime number or not, you can use this function only.
//判断素数只能用这个函数
bool is_number_prime(int n)
{
    if (n == 2 || n == 3)//prime less than 5
    {
        return true;//is prime
    }
    if (n % 6 != 5 && n % 6 != 1)//is not prime
    {
        return false;
    }
    int cmb = (int)std::sqrt(n);
    for (int i = 5; i <= cmb; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;//is not prime
        }
    }
    return true;//is prime
}

/*
    100以内的素数 primes within 100
    2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/
//测试判断素数的函数是否正确
void test_is_prime_number(void)
{
    stringstream ss;
    for (int  i = 2; i < 100; i++)
    {
        if (is_number_prime(i))
        {
            ss << i << " ";
        }
    }
    check(ss.str() == "2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 ");
}

//do not change this function!
//不要修改此函数
long long test_the_sum_of_all_primes_within(long long scale)
{
    auto start = system_clock::now();

    long long sum = 0;

    for (int n = 2; n <= scale; n++) {
        if (is_number_prime(n)) {
            sum += n;
        }
    }

    cout << "the sum of all primes from 2~"<< setw(10) << scale << " is : " << setw(15) << sum
        << ", elapled " << setw(10) << static_cast<long long>(duration<double, milli>(system_clock::now() - start).count()) << " milliseconds"
        << endl;
    return sum;
}
//please change this function to let your program faster by use multi core in your CPU.
//请重新实现此函数以让你的CPU多核优势得到发挥
//hint: maybe you can use multi thread technology to let your code faster.
//提示：你可以使用多线程来发挥多核的计算优势从而让你的程序跑的更快
long long faster_test_the_sum_of_all_primes_within(long long scale)
{
    auto start = system_clock::now();
    long long sum = 0;

    for (int n = 2; n <= scale; n++) {
        if (is_number_prime(n)) {
            sum += n;
        }
    }

    cout << "the sum of all primes from 2~" << setw(10) << scale << " is : " << setw(15) << sum
        << ", elapled " << setw(10) << static_cast<long long>(duration<double, milli>(system_clock::now() - start).count()) << " milliseconds"
        << endl;
    return sum;
}
//do not change the code in this function 
//不要修改此函数中的内容
int main()
{
    
    test_is_prime_number();
    long long sum = 0;
    cout << "base slow version:" << endl;
    sum = test_the_sum_of_all_primes_within(10000 * 10);
    check(sum == 454396537);
    sum = test_the_sum_of_all_primes_within(10000 * 100);
    check(sum == 37550402023);
    sum = test_the_sum_of_all_primes_within(10000 * 1000);
    check(sum == 3203324994356);
    sum = test_the_sum_of_all_primes_within(10000 * 10000);
    check(sum == 279209790387276);

    cout << endl << "my faster version:" << endl;
    sum = faster_test_the_sum_of_all_primes_within(10000 * 10);
    check(sum == 454396537);
    sum = faster_test_the_sum_of_all_primes_within(10000 * 100);
    check(sum == 37550402023);
    sum = faster_test_the_sum_of_all_primes_within(10000 * 1000);
    check(sum == 3203324994356);
    sum = faster_test_the_sum_of_all_primes_within(10000 * 10000);
    check(sum == 279209790387276);

    //test output in my pc : 我计算机上的输出示例
    //what you have to do is let your faster version faster than base slow version.
    //你要做的是让更快的版本比基础慢版本更快
    /*
        line:60 Pass
        base slow version:
        the sum of all primes from 2~    100000 is :       454396537, elapled          3 milliseconds
        line:111 Pass
        the sum of all primes from 2~   1000000 is :     37550402023, elapled         55 milliseconds
        line:113 Pass
        the sum of all primes from 2~  10000000 is :   3203324994356, elapled       1131 milliseconds
        line:115 Pass
        the sum of all primes from 2~ 100000000 is : 279209790387276, elapled      27449 milliseconds
        line:117 Pass

        faster version:
        the sum of all primes from 2~    100000 is :       454396537, elapled          2 milliseconds
        line:125 Pass
        the sum of all primes from 2~   1000000 is :     37550402023, elapled         45 milliseconds
        line:127 Pass
        the sum of all primes from 2~  10000000 is :   3203324994356, elapled       1083 milliseconds
        line:129 Pass
        the sum of all primes from 2~ 100000000 is : 279209790387276, elapled      27438 milliseconds
    */


    return 0;
}