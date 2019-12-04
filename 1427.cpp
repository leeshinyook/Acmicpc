// sequence container

#include <iostream>
#define SWAP(x, y, temp) ( (temp) = (x), (x) = (y), (y) = (temp) )
//
using namespace std;
void QuickSort(int * arr, int left, int right) {
    int i, j, pivot, temp;
    if(left < right) {
        i = left;
        j = right + 1;
        pivot = arr[left];
        do {
            do { i++;} while(arr[i] < pivot);
            do { j--;} while(arr[j] > pivot);
            if(i < j) SWAP(arr[i], arr[j], temp);
        } while( i < j);
        SWAP(arr[left], arr[j], temp);

        QuickSort(arr, left, j - 1);
        QuickSort(arr, j + 1, right);
    }
}
int main() {

    int num = 0;
    int length = 0;
    int arr[12];
    cin >> num;

    while(num) {
        arr[length] = num % 10;
        num /= 10;
        length++;
    }
    QuickSort(arr, 0, length - 1);
    for(int i = length -1 ; i >= 0; i--) {
        cout << arr[i];
    }
    return 0;
}