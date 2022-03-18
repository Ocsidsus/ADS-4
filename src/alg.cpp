// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < (len - 2); i++) {
        for (int j = i + 1; j < (len - 1); j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }

    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; arr[i] <= (float)value / 2; i++) {
        for (int j = len - 1; arr[j] >= (float)value / 2; j--) {
            if (arr[j] <= value) {
                if ((arr[i] + arr[j]) == value) {
                    count++;
                }
                if ((arr[i] + arr[j]) < value) {
                    break;
                }
            }
        }
    }

    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; arr[i] <= (float)value / 2; i++) {
        int start = i, end = len - 1;
        int y = value - arr[i];

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == y) {
                int c = 0, d = 0;
                for (c = mid - 1; c >= start; c--) {
                    if (arr[c] != y)
                        break;
                }
                for (d = mid + 1; d <= end; d++) {
                    if (arr[d] != y)
                        break;
                }
                count += (d - 1) - c;
                break;
            } else if (arr[mid] > y) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
    }

    return count;
}
