#include <iostream>
#include <cstdlib>  // for atoi()
#include <cmath>    // for sqrt()
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <start> <end>\n";
        return 1;
    }

    // Parse command-line arguments
    int start = std::atoi(argv[1]);
    int end = std::atoi(argv[2]);

    std::cout << "Primes between " << start << " and " << end << ":\n";
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
