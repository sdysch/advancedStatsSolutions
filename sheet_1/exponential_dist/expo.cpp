#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>

int main() {
	const double lambda = 2.;
	std::vector<double> vec;
	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0., 1.);
    for (int i = 0; i < 100000; ++i) {
		const double rand = dis(gen);
		//std::cout << rand << std::endl;
        vec.push_back(log(rand) * -1./lambda);
    }
	std::ofstream myfile;
	myfile.open("out.dat");
	for (auto it = vec.begin(); it < vec.end(); ++it) {
		myfile << *it << std::endl;
	}
	myfile.close();
	return 0;
}
