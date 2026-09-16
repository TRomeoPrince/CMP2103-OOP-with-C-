#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long number;
    cout << "Enter a credit card number as a long integer: ";
    cin >> number;

    if (isValid(number)) {
        cout << number << " is valid" << endl;
    } else {
        cout << number << " is invalid" << endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int totalSize = getSize(number);

    // Validate overall length (13 to 16 digits)
    if (totalSize < 13 || totalSize > 16) {
        return false;
    }

    // Validate card prefix (4, 5, 37, 6)
    if (!prefixMatched(number, 4) && 
        !prefixMatched(number, 5) && 
        !prefixMatched(number, 37) && 
        !prefixMatched(number, 6)) {
        return false;
    }

    // Perform Luhn check (Mod 10 rule)
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Start at the second digit from the right (even place)

    while (number > 0) {
        int digit = number % 10;
        sum += getDigit(digit * 2);
        number /= 100; // Move two places to the left
    }

    return sum;
}

// Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Return sum of odd place digits in number
int sumOfOddPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        number /= 100; // Move two places to the left
    }

    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int sizeD = getSize(d);
    return getPrefix(number, sizeD) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    if (d == 0) return 1;
    int count = 0;
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int numSize = getSize(number);
    if (numSize < k) {
        return number;
    }
    
    // Divide away trailing digits to leave only the first k digits
    long long factor = pow(10, numSize - k);
    return number / factor;
}