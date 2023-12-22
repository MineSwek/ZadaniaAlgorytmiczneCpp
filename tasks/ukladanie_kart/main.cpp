#include <iostream>
#include <vector>

long long merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    long long inversionCount = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inversionCount += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversionCount;
}

long long mergeSort(std::vector<int>& arr, int left, int right) {
    long long inversionCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        inversionCount += mergeSort(arr, left, mid);
        inversionCount += mergeSort(arr, mid + 1, right);
        inversionCount += merge(arr, left, mid, right);
    }

    return inversionCount;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cards[i];
    }

    long long totalInversions = mergeSort(cards, 0, n - 1);

    std::cout << totalInversions << std::endl;

    return 0;
}
