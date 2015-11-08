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

void initial_conditions(bool* pos, const int length, const int ni, double& time) {// initialise array to initial conditions
	time = 0;
	for (int n = 0; n < length; ++n) {// initialise initial conditions -> position[i] = delta(i,n_initial)
		if (n == ni) {
			pos[n] = true;
		}
		else {
			pos[n] = false;
		}
	}
}

int shuffle(bool* pos, const int length, double& time) {// determines possible states to move to, increments time, returns position of new state
	const double rate = 0.05;// transition rate, W+- fixed @ 0.05
	const double lambda = rate + rate;
	time += get_random_expo(lambda);// increment time drawn from expo distribution
	int current_position;
	for (int n = 0; n < length; ++n) {// get current position
		if(pos[n]) {
			current_position = n;
		}
	}
	const double p = get_random();// random number between 0 and 1
	if (p < rate / lambda) {// p < 1/2 in default case
		return current_position + 1;
	}
	else return current_position - 1;
}

int main() {
	const int runs = 100;// number of gillespie simulations to run
	const int N = 100;
	const int initial_n = 10;// initial position 
	double t = 0;// start at 0 time
	bool positions[N];// array of positions

	std::ofstream abs_end;
	abs_end.open("absorbed_end.dat");
	std::ofstream abs;
	abs.open("absorbed.dat");

	for (int i = 0; i < runs; ++i) {
		initial_conditions(positions, N, initial_n, t);
		while (true) {	
			if (!absorbed_beginning(positions, N) && !absorbed_end(positions, N)) {
				const int new_position = shuffle(positions, N, t);
				for (int n = 0; n < N; ++n) {// change positions over
					if(positions[n]) {
						positions[n] = false;
					}
				}
				positions[new_position] = true;
				//std::cout << new_position << std::endl;
			}
			else {
				abs << t << std::endl;
				if (absorbed_end(positions, N)) {
					abs_end << t << std::endl;
				}				
				break;
			}
		}
	}
	abs_end.close();
	abs.close();
	return 0;
}
