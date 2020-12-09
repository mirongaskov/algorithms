#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <complex>

using namespace std;


void Shell_Sort(int *array, int len_array) {
    for (int s = len_array / 2; s > 0; s = s / 2)
        for (int i = s; i < len_array; ++i)
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s)
                swap(array[j], array[j + s]);
}


void heapify(int *array, int n, int i) {
    int largest = i; int left = 2 * i + 1; int right = 2 * i + 2;
    if (left < n and array[left] > array[largest])
        largest = left;
    if (right < n and array[right] > array[largest])
        largest = right;
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}


void Heap_Sort(int *array, int array_len) {
    for (int i = array_len / 2 - 1; i >= 0; i--)
        heapify(array, array_len, i);
    for (int i = array_len - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}


void Quick_Sort(int *array, int array_len) {
    int left = 0;
    int right = array_len - 1;
    int mid = array[array_len / 2];
    while (left <= right) {
        while(array[left] < mid)
            left++;
        while(array[right] > mid)
            right--;
        if (left <= right) {
            swap(array[left], array[right]);
            left++;
            right--;
        }
    }
    if (right > 0)
        Quick_Sort(array, right + 1);
    if (left < array_len)
        Quick_Sort(&array[left], array_len - left);
}


void Intro_Sort(int *array, int array_len, int deep) {
    if (deep == 0) {
        Heap_Sort(array, array_len);
    } else {
        Quick_Sort(array, array_len);
    }
}


void test() {
    ifstream in_put;
    ofstream out_put;
    int len_array;

    string directory = "C:/Users/test1/PycharmProjects/sorts/";

    for (int test_number = 1; test_number <= 100; test_number++) {

        in_put.open(directory + "files/inputs/input" + to_string(test_number) + ".txt");
        in_put >> len_array;
        int array[len_array];
        for (int i = 0; i < len_array; i++)
            in_put >> array[i];
        in_put.close();

        Intro_Sort(array, len_array, log(len_array));

        out_put.open(directory + "files/outputs/output" + to_string(test_number) + ".txt");
        for (int i = 0; i < len_array; i++)
            out_put << array[i] << " ";
        out_put.close();

    }
}


signed main() {
    test();
    return 0;
}