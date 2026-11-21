#include <iostream>
int main() {
    int sum = 0, factor = 3;
    for (int i = 1; i <= 6; ++i) {
        int step_val = i * factor;
        if (step_val % 2 == 0) sum += step_val;
        else sum += i;
    }
    std::cout << "Sum: " << sum;
}