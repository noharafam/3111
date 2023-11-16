#include <iostream>
#include <chrono>

// Non-recursive Fibonacci function
long long fibNonRecursive(int n) {
    if (n <= 1) {
        return n;
    }

    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

// Recursive Fibonacci function
long long fibRecursive(int n) {
    if (n <= 1) {
        return n;
    }

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Measure time for non-recursive Fibonacci
    auto startNonRecursive = std::chrono::high_resolution_clock::now();
    long long resultNonRecursive = fibNonRecursive(n);
    auto endNonRecursive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationNonRecursive = endNonRecursive - startNonRecursive;

    // Measure time for recursive Fibonacci
    auto startRecursive = std::chrono::high_resolution_clock::now();
    long long resultRecursive = fibRecursive(n);
    auto endRecursive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationRecursive = endRecursive - startRecursive;

    // Output results and time complexity analysis
    std::cout << "Non-recursive Fibonacci(" << n << "): " << resultNonRecursive << std::endl;
    std::cout << "Time taken by non-recursive function: " << durationNonRecursive.count() << " seconds" << std::endl;

    std::cout << "\nRecursive Fibonacci(" << n << "): " << resultRecursive << std::endl;
    std::cout << "Time taken by recursive function: " << durationRecursive.count() << " seconds" << std::endl;

    return 0;
}
