#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>

double average(std::vector<double>& vec) {// return average of the numbers in the vector
	int sum = 0;
	double total = 0;
	for (auto it = vec.begin(); it < vec.end(); ++it) {
		++sum;
		total += *it;
	}
	return (double) total / sum;
}

double gen_rand(double N) {// generate N random numbers and return average
	std::vector<double> vec;
	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0., 1.);
    for (int i = 0; i < N; ++i) {
		const double rand = dis(gen);
        vec.push_back(rand);
    }
	return average(vec);
}

int main() {
	std::vector<double> store;
	const double batches = 100000;
	const double N = 100.;
	for (int i = 0; i < batches; ++i) {
		//std::cout << gen_rand(N) << std::endl;
		store.push_back(gen_rand(N));
	}
	
	std::ofstream myfile;
	myfile.open("out_100.dat");
	for (auto it = store.begin(); it < store.end(); ++it) {
		myfile << *it << std::endl;
	}
	myfile.close();
	return 0;
}
