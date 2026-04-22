#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int charToValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    return 0;
}

char valueToChar(int value) {
    if (value < 10) {
        return '0' + value;
    } else {
        return 'A' + value - 10;
    }
}

int main() {
    int m, n, B;
    cin >> m >> n >> B;

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = m - 1;
    int len2 = n - 1;
    int maxLen = max(len1, len2);

    string result(maxLen, '0');

    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = maxLen - 1;

    while (i >= 0 || j >= 0 || k >= 0) {
        int val1 = (i >= 0) ? charToValue(str1[i]) : 0;
        int val2 = (j >= 0) ? charToValue(str2[j]) : 0;

        int sum = val1 + val2 + carry;
        carry = sum / B;
        int remainder = sum % B;

        if (k >= 0) {
            result[k] = valueToChar(remainder);
        }

        i--;
        j--;
        k--;
    }

    cout << result;

    return 0;
}