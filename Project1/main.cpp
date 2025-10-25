#include <iostream>

int main() {
	using u_t = unsigned;
	u_t a = 0;
	size_t count = 0;
	while (std::cin >> a) {
		count++;
	}

	std::cin >> a;
	if (std::cin.eof()) {
		std::cout << 0;
		std::cout << "\n";
	}
	else if (std::cin.fail()) {
		std::cerr << "Erro\n";
		return 1;
	}
}