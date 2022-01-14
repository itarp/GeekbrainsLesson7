#include <iostream>
#include <random>
#include <chrono>
#include "mylib.h"
namespace mylib {
	void arrayInit(float* arr, const size_t size) {
		const double from = -3000.;
		const double to = 3000.;
		using namespace std::chrono;
		std::default_random_engine engine(system_clock::to_time_t(system_clock::now()));
		std::uniform_real_distribution<> distr(from, to);
		auto gen_number = [&engine, &distr]() { return distr(engine); };
		for (int i = 0; i < size; i++) {
			*(arr + i) = (float)gen_number();
		}
	}

	void arrayShow(float* arr, const size_t size) {
		for (int i = 0; i < size; i++)
			std::cout << *(arr + i) << std::endl;
		std::cout << std::endl;
	}

	void countPositiveNegative(float* arr, const size_t size) {
		int negative(0);
		int positive(0);
		for (int i = 0; i < size; i++)
			if (*(arr + i) < 0)
				negative++;
			else
				positive++;
		std::cout << "Positive elements: " << positive << std::endl;
		std::cout << "Negative elements: " << negative << std::endl;
	}
}