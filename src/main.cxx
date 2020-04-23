#include <fmt/format.h>

int fib(int n) {
	int a = 0, b = 1;

	for ([[maybe_unused]] int i = 0; i < n; ++i) {
		auto tmp = b;
		b = a + b;
		a = tmp;
	}

	return a;
}

int main() {
	for (int i = 0; i < 15; ++i) {
		fmt::print("fib({}) = {}\n", i, fib(i));
	}
}
