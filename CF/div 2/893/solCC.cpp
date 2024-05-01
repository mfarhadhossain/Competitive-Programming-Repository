#include <iostream>
#include <vector>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> solve(int n) {
    std::vector<int> permutation;
    if (n == 2) {
        permutation.push_back(1);
        permutation.push_back(2);
        return permutation;
    }

    int prime = 2;
    for (int i = 1; i < n; ++i) {
        while (!is_prime(prime)) {
            ++prime;
        }
        permutation.push_back(prime++);
    }
    permutation.push_back(1);

    return permutation;
}

int main() {
    int t;
    std::cin >> t;  // Number of test cases

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;  // Size of the permutation
        std::vector<int> permutation = solve(n);

        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

