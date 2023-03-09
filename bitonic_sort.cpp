#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>


void bitonicSort(int *arr, int n, int &c) {
    int k, j, l, i, temp;
    for (k = 2; k <= n; k *= 2) {
        for (j = k/2; j > 0; j /= 2) {
            for (i = 0; i < n; i++) {
                l = i ^ j;
                if (l > i) {
                    if ( ((i&k)==0) && (arr[i] > arr[l]) || ( ( (i&k)!=0) && (arr[i] < arr[l])) )  {
                        c++;
                        temp = arr[i];
                        arr[i] = arr[l];
                        arr[l] = temp;

                        std::ofstream file( std::string( "C:\\Users\\12345\\CLionProjects\\huy\\sor" + std::to_string( c ) + ".txt").c_str() );
                        for (int h = 0; h < 256; h++){
                            file << arr[h] << std::endl;
                        }
                        file.close();
                    }
                }
            }
        }
    }
}


int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main() {
    int a[256];
    int file_number = 0;
    int *FN_link = &file_number;
    for (int l = 0; l < 256; l++) {
        a[l] = l + 1;
    }
    for (int k = 0; k < 1000; k++) {
        int r = rand_uns(0, 255), t = rand_uns(0, 255);
        int tmp = a[r];
        a[r] = a[t];
        a[t] = tmp;
    }

    bitonicSort(a, 256, *FN_link);

//    for (int i = 0; i < 256; i++){
//        std::cout << a[i] << std::endl;
//    }
//    std::cout << file_number;
}