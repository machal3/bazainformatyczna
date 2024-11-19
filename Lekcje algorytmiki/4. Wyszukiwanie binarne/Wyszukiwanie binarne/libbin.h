#include <functional>
#include <iostream>
#include <vector>
#include <cstdlib>

bool szukaj(int n, std::function<long long(int)> const & B, long long x);

struct container {
	std::vector<long long> V;

	void push_back(long long x) {
		V.push_back(x);
	}

	long long get_value(int x) {
		if(x < 1 || x > (int)V.size()) {
			std::cout << "Przegrales" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		return V[x - 1];
	}
};

bool test() {
	int n = 0;
	
	std::cout << "Prosze podac dlugosc ciagu (0, jesli konczymy): ";
	std::cin >> n;

	if(n == 0) return false;

	container C;

	std::cout << "Prosze podac ciag: ";
	for(long long i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		C.push_back(x);
	}

	long long x;
	std::cout << "A teraz liczbe, ktorej szukamy: ";
	std::cin >> x;

	bool wynik = szukaj(n, std::bind(&container::get_value, &C, std::placeholders::_1), x);

	std::cout << "Twoj program stwierdzil, że liczba " << x << (wynik ? " " : " nie ") << "wystepuje w ciagu." << std::endl;
	std::cout << "---" << std::endl;

	return true;
}

int main() {
	std::cout << "Dzien dobry, pobawmy sie w wyszukiwanie binarne." << std::endl;
	while(test());
}
