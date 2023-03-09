#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

void swap(int* a, int* b, int &c){
    int t = *a;
    *a = *b;
    *b = t;
    c++;
}

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main() {
    int a[100];
    int file_number = 0;
    int* FN_link = &file_number;
    for (int l = 0; l < 100; l++){
        a[l] = l + 1;
    }
    for (int k = 0; k < 1000; k++){
        int r = rand_uns(0, 99), t = rand_uns(0, 99);
        int tmp = a[r];
        a[r] = a[t];
        a[t] = tmp;
    }
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100-i-1; j++)
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1], *FN_link);

                std::ofstream file( std::string( "C:\\Users\\12345\\CLionProjects\\huy\\sort_bubble" + std::to_string( file_number ) + ".txt").c_str() );
                for (int h = 0; h < 100; h++){
                    file << a[h] << std::endl;
                }
                file.close();
            }
//    for (int i = 0; i < 100; i++){
//        std::cout << a[i] << std::endl;
//    }
//    std::cout << file_number;
}
