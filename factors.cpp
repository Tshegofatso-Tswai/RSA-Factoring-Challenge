#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> factorize(int n) {
    std::vector<int> factors;
    int divisor = 2;

    while (n > 1) {
        if (n % divisor == 0) {
            factors.push_back(divisor);
            n = n / divisor;
        } else {
            divisor++;
        }
    }

    return factors;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

    const char* input_file = argv[1];
    std::ifstream file(input_file);

    if (!file) {
        std::cerr << "Error: File '" << input_file << "' not found." << std::endl;
        return 1;
    }

    std::vector<std::string> numbers;
    std::string line;

    while (std::getline(file, line)) {
        numbers.push_back(line);
    }

    for (const std::string& number : numbers) {
        int n = std::stoi(number);
        std::vector<int> factors = factorize(n);
        int p = factors[0];
        int q = n / p;
        std::cout << n << "=" << p << "*" << q << std::endl;
    }

    return 0;
}

