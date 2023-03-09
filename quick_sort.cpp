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

int partition (int arr[], int low, int high, int &c){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j], c);
            std::ofstream file( std::string( "C:\\Users\\12345\\CLionProjects\\huy\\sorrt_bubble" + std::to_string( c ) + ".txt").c_str() );
            for (int h = 0; h < 100; h++){
                file << arr[h] << std::endl;
            }
            file.close();
        }
    }
    swap(&arr[i + 1], &arr[high], c);
    std::ofstream file( std::string( "C:\\Users\\12345\\CLionProjects\\huy\\sorrt_bubble" + std::to_string( c ) + ".txt").c_str() );
    for (int h = 0; h < 100; h++){
        file << arr[h] << std::endl;
    }
    file.close();
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int &c){
    if (low < high){
        int pivot = partition(arr, low, high, c);

        quickSort(arr, low, pivot - 1, c);
        quickSort(arr, pivot + 1, high, c);
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
    int file_number = 0;
    int* FN_link = &file_number;
    for (int l = 0; l < 100; l++) {
        a[l] = l + 1;
    }
    for (int k = 0; k < 1000; k++) {
        int r = rand_uns(0, 99), t = rand_uns(0, 99);
        int tmp = a[r];
        a[r] = a[t];
        a[t] = tmp;
    }
    quickSort(a, 0, 99, *FN_link);
    for (int i = 0; i < 100; i++)
        std::cout << a[i] << std::endl;
    std::cout << file_number;
}