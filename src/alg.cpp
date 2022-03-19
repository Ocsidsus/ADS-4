// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value);

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;

    int i = 0, j = len - 1;

    for (; (arr[i] <= value / 2) && (i < len - 1); i++) {
        int x = value - arr[i];
        while ((arr[j] >= x) && (j > i)) {
            if (arr[j] == x) {
                for (int k = j; (arr[k] == x) && (k > i); k--) {
                    count++;
                }
                break;
            }
            j--;
        }
    }

    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; (arr[i] <= value / 2) && (i < len - 1); i++) {
        int x = value - arr[i];
        count += cbinsearch(arr + (i + 1), len - (i + 1), x);
    }

    return count;
}

int cbinsearch(int* arr, int size, int value) {
    if (size == 1) {
        if (arr[size - 1] == value) {
            return 1;
        }
    }
    int i = 0, j = size - 1;
    while (i < j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] == value) {
            int c = 0, d = 0;
            for (c = mid - 1; c >= i; c--) {
                if (arr[c] != value)
                    break;
            }
            for (d = mid + 1; d <= j; d++) {
                if (arr[d] != value)
                    break;
            }
            return (d - 1) - c;
        } else if (arr[mid] > value) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return 0;
}
