#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int getFact(int num);
double getRank(double num, int rank);
string taylor(double errorRate, int max, double curr);

int main() {

	string errorRateS, startS, stopS, stepS, maxElemsS;

	double errorRate, start, stop, step;
	int maxElems;
	
	while (true) {

		cout << "Enter error rate: ";
		cin >> errorRateS;
		cout << endl;

		try {

			errorRate = stod(errorRateS);

		}
		catch (exception) {

			cout << "Invalid value" << endl << endl;
			continue;

		}
		if (errorRate < 0) {

			cout << "Error rate must be more than 0" << endl<<endl;
			continue;

		}
		break;

	}
	while (true) {

		cout << "Enter max sum elems count: ";
		cin >> maxElemsS;
		cout << endl;

		try {

			maxElems = stoi(maxElemsS);

		}
		catch (exception) {

			cout << "Invalid value" << endl << endl;
			continue;

		}
		if ((maxElemsS.find('.') != maxElemsS.npos) || (maxElemsS.find(',') != maxElemsS.npos)) {

			cout << "Max elems must be integer" << endl;
			continue;

		}
		if (maxElems < 0) {

			cout << "Max elems value must be more than 0" << endl << endl;
			continue;

		}
		break;

	}
	while (true) {

		cout << "Enter bottom interval value: ";
		cin >> startS;
		cout << endl;

		try {

			start = stod(startS);

		}
		catch (exception) {

			cout << "Invalid value" << endl << endl;
			continue;

		}
		if (start<=-1||start>=1) {

			cout << "Start and stop values must be in range from -1 to 1 excluded" << endl << endl;
			continue;

		}
		break;

	}
	while (true) {

		cout << "Enter top interval value: ";
		cin >> stopS;
		cout << endl;

		try {

			stop = stod(stopS);

		}
		catch (exception) {

			cout << "Invalid value" << endl << endl;
			continue;

		}
		if (stop <= -1 || stop>=1) {

			cout << "Start and stop values must be in range from -1 to 1" << endl << endl;
			continue;

		}
		break;

	}
	if (start >= stop) {
		cout << "Start value must be less than stop value" << endl;
		system("pause");
		return 0;
	}

	while (true) {

		cout << "Enter step: ";
		cin >> stepS;
		cout << endl;

		try {

			step = stod(stepS);

		}
		catch (exception) {

			cout << "Invalid value" << endl << endl;
			continue;

		}
		if (step < 0||step>stop-start) {

			cout << "Step must be more than 0 and less than stop-start" << endl << endl;
			continue;

		}
		break;

	}
	printf("%-20s|%-35s|%-20s\n", "x", "taylor", "sin()");
	printf("____________________|___________________________________|__________\n");
	while (start < stop) {

		printf("%-20f|%-35s|%-20f\n", start, taylor(errorRate, maxElems, start).c_str(), sin(start));
		start += step;
	}
	cout << endl;

	system("pause");
	return 0;

}

int getFact(int num) {

	int result = 1;

	for (int i = 1; i <= num; i++) {

		result *= i;

	}

	return result;

}

double getRank(double num, int rank) {

	double result;
	result = num;

	for (int i = 1; i < rank; i++) {

		result *= num;

	}

	return result;

}

string taylor(double errorRate, int max, double curr) {

	bool state(true), res(false);
	int temp = 1;
	double result = 0, elem;

	for (int i=0; i < max; i++) {

		if (i == 0) {
			elem = curr;
			result += elem;
			temp += 2;
			state = false;
		}
		if (state&&i!=0) {

			elem = getRank(curr, temp) / getFact(temp);
			if (abs(elem) < errorRate) {
				res = true;
				break;
			}
			else {
				result += elem;
				temp += 2;
				state = false;
			}

		}
		else if (!state && i != 0) {

			elem = getRank(curr, temp) / getFact(temp);
			if (abs(elem) < errorRate) {
				res = true;
				break;
			}
			else {
				result -= elem;
				temp += 2;
				state = true;
			}

		}

	}
	if (res) {
		return to_string(result);
	}
	else {
		return "Haven't reached max accuracy";
	}


}