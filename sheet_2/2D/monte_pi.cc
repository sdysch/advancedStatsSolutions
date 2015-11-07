#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include <iomanip>

double gen_rand() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0., 1.);
	return dis(gen);
}

bool in_circle(const double x, const double y) {
	if (pow(x, 2.) + pow(y, 2.) <= 1) return true;
	else return false;
}

int main() {
	const double pi = 3.141592654;
	std::ofstream myfile1, myfile2;
	myfile1.open("out_normal.dat");
	myfile2.open("out_div_pi.dat");
	int number_generated = 0;
	int number_in_circle = 0;
	const int iterations = 50000;

	for (int i = 0; i < iterations; ++i) {
		const double xt = gen_rand();
		const double yt = gen_rand();
		++number_generated;
		if (in_circle(xt, yt)) ++number_in_circle;
		if (i % 500 == 0) myfile1 << i + 1 << " " << std::setprecision(9) << 4. * (double) number_in_circle / number_generated << std::endl;
		if (i % 500 == 0) myfile2 << i + 1 << " " << std::setprecision(9) << 1. / pi * 4. * (double) number_in_circle / number_generated << std::endl;
	}
	return 0;
}
