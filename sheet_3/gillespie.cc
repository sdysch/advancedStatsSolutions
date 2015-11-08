#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

double get_random() {// uniform random number between 0 and 1
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0., 1.);
	return dis(gen);
}

double get_random_expo(const double lambda) {// random number from exponential distribution with parameter lambda
	return -1./lambda * log(get_random());
}

bool absorbed_beginning(bool* pos, const int length) {// determine if the particle has been absorbed @ n=0
	for (int n = 0; n < length; ++n) {
		if (pos[n] && n == 0) {// if particle position is beginning, been absorbed
			return true;
		}
	}
	return false;
}

bool absorbed_end(bool* pos, const int length) {// determine if the particle has been absorbed @ n=N
	for (int n = 0; n < length; ++n) {
		if (pos[n] && n == length - 1) {// if particle position is end, been absorbed
			return true;
		}
	}
	return false;
}
int main() {
	const double rate = 0.05;
	const int N = 100;
	const int initial_n = 10;// initial position 
	double t = 0;// start at 0 time

//==============================================================================================================//
	bool positions[N];// array of positions
	for (int n = 0; n < N; ++n) {// initialise initial conditions -> position[i] = delta(i,n_initial)
		if (n == initial_n) {
			positions[n] = true;
		}
		else {
			positions[n] = false;
		}
	}
//=============================== MAIN CODE ================================================================//
	
	std::cout << absorbed_beginning(positions, N) << " " << absorbed_end(positions, N) << std::endl;		
	positions[initial_n] = false;
	positions[0] = true;
	std::cout << absorbed_beginning(positions, N) << " " << absorbed_end(positions, N) << std::endl;
	positions[0] = false;
	positions[N - 1] = true;
	std::cout << absorbed_beginning(positions, N) << " " << absorbed_end(positions, N) << std::endl;
	return 0;
}
