#include <iostream>
#include <limits>
#include <cstddef>
bool isPyth(unsigned a, unsigned b, unsigned c);
bool canMultiply(size_t a);
bool canSum(size_t a, size_t b);

int main() {
	using u_t = unsigned;
	u_t a = 0, b =0, c = 0;
	std::cin >> c >> b;
	size_t count = 0;
	
	while (std::cin >> a) {
		bool f = canMultiply(a);
		f = f|| canMultiply(b);
		f = f || canMultiply(c);

		bool s = canSum(a * a, b * b);
		s = s || canSum(b * b, c * c);
		s = s || canSum(a * a, c * c);

		if (s||f) {
			std::cerr << "Out off limit :(\n";
			return 2;
		}
		count+=isPyth(a,b,c)?1:0;
		c = b;
		b = a;
	}

	if (std::cin.eof()) {
		std::cout << count;
		std::cout << "\n";
	}

	else if (std::cin.fail()) {
		std::cerr << "Error\n";
		return 1;
	}
}
bool isPyth(unsigned a, unsigned b, unsigned c) {
	bool p = a * a == (b * b + c * c);
	p = p || (b * b == (a * a + c * c));
	p = p || (c * c == (a * a + b * b));
	return p;
}
bool canMultiply(size_t a) {
	size_t max = std::numeric_limits<size_t>::max();
	return (a < max / a);
}

bool canSum(size_t a, size_t b) {
	size_t max = std::numeric_limits<size_t>::max();
	return (a < max - b);
}