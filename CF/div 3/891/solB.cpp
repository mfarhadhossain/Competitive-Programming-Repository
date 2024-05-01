#include <iostream>
#include <string>

using namespace std;

int maximize_number(int x) {
    string x_str = to_string(x);
    int n = x_str.length();

    // Find the leftmost non-zero digit
    int k = n - 1;
    while (k >= 0 && x_str[k] == '0') {
        k--;
    }

    if (k == -1) {
        // All digits are zero
        return x;
    }

    // Round the leftmost non-zero digit to the nearest multiple of 10^k
    int new_digit = x_str[k] - '0';
    new_digit = (new_digit + 1) % 10;
    x_str = x_str.substr(0, k) + to_string(new_digit) + string(n - k - 1, '0');

    // Continue the process for the remaining digits
    for (int i = k - 1; i >= 0; i--) {
        if (x_str[i] >= '5') {
            new_digit = (x_str[i] - '0' + 1) % 10;
            x_str = x_str.substr(0, i) + to_string(new_digit) + string(n - i - 1, '0');
        } else {
            break;
        }
    }

    return stoi(x_str);
}

int main() {
    int t;
    cin >> t;

    // Process each test case
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        int result = maximize_number(x);
        cout << result << endl;
    }

    return 0;
}

