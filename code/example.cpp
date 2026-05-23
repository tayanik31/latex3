#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Исходный массив: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    vector<int> arr2 = arr;
    bubbleSort(arr);
    quickSort(arr2, 0, arr2.size()-1);
    
    cout << "Пузырьковая сортировка: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "Быстрая сортировка: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    return 0;
}