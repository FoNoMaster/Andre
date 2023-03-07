#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main() {
    int a[100], file_number = 1;
    for (int l = 0;l < 100; l++){
        a[l] = l + 1;
    }
    for (int k = 0; k < 1000; k++){
        int r = rand_uns(1, 99), t = rand_uns(1, 99);
        int tmp = a[r];
        a[r] = a[t];
        a[t] = tmp;
    }
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100-i-1; j++)
            if (a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;

                std::ofstream file( std::string( "sort_bubble" + std::to_string( file_number ) + ".txt").c_str() );
                for (int h = 0; h < 100; h++){
                    file << a[h] << std::endl;
                }
                file.close();
                file_number += 1;
            }
}
