作业介绍：
下面的作业给出一个已经搭建好的C++作业框架

该框架只有一个源文件，可以在任何操作系统的上通过对应的C++编译工具编译运行

你只需要重新实现函数faster_test_the_sum_of_all_primes_within，就可以看出你重新实现的版本和基础版本相比较，程序是否在更短的时间运行出了正确的结果。

代码结构介绍：
下面的作业是求某个数字以内的素数和。

由于任何数字以内的素数和都是确定的（有唯一答案），所以可以无差别的测试每个人的程序。

程序一开始是用test_is_prime_number验证程序本身提供的求素数的函数test_is_prime_number是否正确。

接下来开始实际计算某个数字以内的素数和，此时使用程序提供的默认版本test_the_sum_of_all_primes_within来计算。

接下来重新使用faster_test_the_sum_of_all_primes_within再次计算。该函数已经实现好了，只不过就是直接拷贝的默认版本test_the_sum_of_all_primes_within中的代码。所以可以看到两个版本的运行时间其实是一样的。

两个版本运行的时间是毫秒为单位。

由于毫秒为单位的时间过于精细，每次计算都有一定的波动，所以不用关心这里面的差别。

我们主要关注的时数据量大到秒级别的时候，你实现的faster_test_the_sum_of_all_primes_within函数，耗时是否大幅度降低。这正是你的工作。

作业框架代码：
```cpp
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
```

请开始吧！

期待你的程序输出一个更快的结果，看看它到底快了多少吧！

加油！！！！

请把你的运行结果以留言的形式发出来。证明自己已经掌握了多线程编程的核心要义！



后面会给出我实现的版本，以及运行结果：

看看谁的更快吧！