#include <iostream>
#include <vector>
#include <functional>

std::vector<int> &operator|(std::vector<int> &a, std::function<void(int &)> f) {
    for (auto &i : a) {
        f(i);
    }
    return a;
}

int main() {
    std::vector<int> v{1, 2, 3};
    std::function<void(const int &)> f {[](const int &i) { std::cout << i << ' '; }};
    auto f2 = [](int &i) { i *= i; };
    v | f2 | f;
}