#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <algorithm>
#include <stdlib.h>
#include <mutex>
#include <iomanip>
using namespace std;
const int n = 100000;
int min_per_thread = 500;


void parallel_summ(int arr[], int length_arr, int* results, int idx) {
    mutex mtx;
    mtx.lock();

    int max_threads = (length_arr + min_per_thread - 1) / min_per_thread;
    int hardware_threads = (thread::hardware_concurrency());
    int num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    int block_size = length_arr / num_threads;



    for (int i = idx; i < length_arr; i += block_size) {
        int j = 0;

        while (((j % block_size != 0) or (j == 0)) and (j + i < length_arr)) {
            int* arr_of_five = new int[block_size];


            arr_of_five[j] = arr[i + j];

            results[i] += arr_of_five[j];

            j++;

        }

        break;
    }
    mtx.unlock();

}

long double Pi(long double eps) {
long double a, rez, b;
   long i = 1;
   b = 4.0;
   a = rez = 4.0;
   while (abs(a) >= eps) {
       b = -b;
       
       a = b / (2 * i + 1.0);
       i++;
       rez += a;
   }
   return rez;
}
/*long double Pi2(double eps) {
    double pi = 1, p, i = 0, pi_prev;

    do {
        i++;
        p = pow(2 * i, 2) / ((2 * i - 1) * (2 * i + 1));
        pi_prev = pi;
        pi = pi * p;
    } while (2 * abs(pi - pi_prev) / (pi + pi_prev));

    return pi * 2;
}*/
long double wallis_formula(int count, long double eps)
{
    long double pi = 1.0;

        for (int i = 1; i < count; i++)
        {
            long double num = 4.0 * i * i;
            pi *= num / (num - 1);
        }
        return pi * 2;
    
}


int main(){
    setlocale(LC_ALL, "Rus");
    double eps = 1e-7;
    int count, count1;
    int input_count = 130000;
    printf("pi = %.10Lf\n", Pi(eps));
    cout << "\n Значение числа Пи за количесиво итераций " << input_count << ": " << wallis_formula(input_count,eps) << "\n\n";



    /*
 * C++ Style
     */

    //long double result = wallis_formula(input_count);
    //std::cout << result << std::endl;

    std::system("pause");
    }














        /*
        int hardware_threads = std::thread::hardware_concurrency();
        std::cout << "in this system can be used " << hardware_threads << " threads";

        setlocale(LC_ALL, "");
        int arr_a[n] = { 0 };
        for (int i = 0; i < n; i++) {
            arr_a[i] = rand() % 10;
        }
        int min_per_thread = 5;
        int max_threads = (n + min_per_thread - 1) / min_per_thread;
        int num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

        thread* threads = new std::thread[num_threads];
        thread::id id;
        int results = 0;

        int* arr_results = new int[num_threads];

        for (int i = 0; i < num_threads; i++) {
            arr_results[i] = { 0 };
        }
        cout << '\n';
        int start1 = clock();
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < num_threads; i++) {
            threads[i] = thread(parallel_summ, arr_a, n, ref(arr_results), i);
        }

        for (int i = 0; i < num_threads; i++) {
            if (threads[i].joinable()) {
                id = threads[i].get_id();

                threads[i].join();

            }
        }
        delete[] threads;
        auto end = chrono::high_resolution_clock::now();
        int end1 = clock();
        double time = (double)(end1 - start1) / CLOCKS_PER_SEC;
        chrono::duration<float> duration = end - start;
        int sum_result = 0;
        for (int i = 0; i < num_threads; i++)
        {
            cout << "Результат" << i << ' ' << arr_results[i] << '\n';
            sum_result += arr_results[i];
        }
        delete[] arr_results;
        cout << "ИТОГИ:" << sum_result << '\n';
        cout << '\n' << "Выполнен за t = " << duration.count() << " seconds" << '\n';
        cout << '\n' << "Выполнен за 1t = " << time << " seconds" << '\n';

        */
    

