#include "util.h"

void custom_test() {
        int arr[1048576];
        int step_size = 16384;
        for (int i = 0; i < 1048576; i += step_size) {
                arr[i] = i;
        }
        int sum = 0;
        for (int j = 1048576 - 16384; j >= 0; j--) {
                sum += arr[j];
        }
        printf("%d, sum")
}

int main() {
        setStats(1);
        custom_test();
        setStats(0);
        return 0;
}
