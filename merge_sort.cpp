#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>


void merge(int *array, int l, int m, int r, int &c) {
    int i, j, k, nl, nr;
    nl = m-l+1; nr = r-m;
    int larr[nl], rarr[nr];

    for(i = 0; i<nl; i++)
        larr[i] = array[l+i];

    for(j = 0; j<nr; j++)
        rarr[j] = array[m+1+j];

    i = 0; j = 0; k = l;

    while(i < nl && j<nr) {
        if(larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;

            std::ofstream file( std::string( "C:\\Users\\12345\\CLionProjects\\huy\\sort_merge" + std::to_string( c ) + ".txt").c_str() );
            for (int h = 0; h < 100; h++){
                file << array[h] << std::endl;
            }
            file.close();
            c++;
        }
        else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl) {
        array[k] = larr[i];
        i++; k++;

        std::ofstream file( std::string( "C:\\Users\\12345\\CLionProjects\\huy\\sort_merge" + std::to_string( c ) + ".txt").c_str() );
        for (int h = 0; h < 100; h++){
            file << array[h] << std::endl;
        }
        file.close();
        c++;
    }
    while(j<nr) {
        array[k] = rarr[j];
        j++; k++;

        std::ofstream file( std::string( "C:\\Users\\12345\\CLionProjects\\huy\\sort_merge" + std::to_string( c ) + ".txt").c_str() );
        for (int h = 0; h < 100; h++){
            file << array[h] << std::endl;
        }
        file.close();
        c++;
    }
}

void mergeSort(int *array, int l, int r, int &c) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;

        mergeSort(array, l, m, c);
        mergeSort(array, m+1, r, c);
        merge(array, l, m, r, c);
    }
}

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main() {
    int a[100];
    int file_number = 1;
    int *FN_link = &file_number;
    for (int l = 0; l < 100; l++) {
        a[l] = l + 1;
    }
    for (int k = 0; k < 1000; k++) {
        int r = rand_uns(0, 99), t = rand_uns(0, 99);
        int tmp = a[r];
        a[r] = a[t];
        a[t] = tmp;
    }
    mergeSort(a, 0, 99, *FN_link);
//    for (int i = 0; i < 100; i++){
//        std::cout << a[i] << std::endl;
//    }
//    std::cout << file_number;
}
