#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void inputMenu(), mainMenu(), aboutMenu(), \
	calculate(double a, double b, double step, double n), calculate(double x, double n);

int main() {

	cout << "\033[H\033[2J" << std::flush;
	cout << "\nList of commands:\n \"input\" to input data.\n \"about\" to learn more\n \"exit\" to exit\n\n";
	mainMenu();

	return 0;
}

void mainMenu() {

	string input;
	cout << "Type command here: ";
	cin >> input;

	if (input == "input") {
		inputMenu();
	}
	if (input == "about") {
		aboutMenu();
	}
	if (input == "exit") {
		cout << "\nHave a nice day!\n\n";
		exit(0);
	}
	if (input!="input" && input!="help" && input!="exit") {
		cout << "\033[H\033[2J" << std::flush;
		cout << "\nThere is no \"" << input << \
			"\" command.\nYou can only use \"input\", \"about\" and \"exit\"\n\n";
		mainMenu();
	}
}

void inputMenu() {
	string setOrRange;
	cout << "\033[H\033[2J" << std::flush;
	cout << "Do you want to set x value or use range (type \"set\" or \"range\"): ";
	cin >> setOrRange;
	if (setOrRange=="set") {
		cout << "\033[H\033[2J" << std::flush;

		double x, n;
		cout << "\nType x: ";
		cin >> x;
		cout << "Type n: ";
		cin >> n;
		calculate(x, n);
	}
	if (setOrRange=="range") {
		cout << "\033[H\033[2J" << std::flush;

		double a, b, step, n;
		cout << "\nType a: ";
		cin >> a;
		cout << "Type b: ";
		cin >> b;
		cout << "Type step: ";
		cin >> step;
		cout << "Type n: ";
		cin >> n;
		cout << endl;
		calculate(a, b, step, n);
	}
	if (setOrRange!="set" && setOrRange!="range") {
		cout << "Error\n";
		mainMenu();
	}
}

void aboutMenu() {
	cout << "\033[H\033[2J" << std::flush;
	cout << "\n/–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\\\n";
	cout << "| Lab for Fundamentals of Software Engineering by Ihor Tytarenko v.1.0.0      |\n";
	cout << "|                                                                             |\n";
	cout << "| Email me if you have any ideas how to improve the app: jaxmef.uni@gmail.com |";
	cout << "\n\\–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––/\n\n";
	mainMenu();
}

void calculate(double a, double b, double step, double n) {
	if (a>b or step<=0) {
		cout << "Wrong input. Press any button to return to the main menu\n";
		cin.get();
		mainMenu();
	}
	double out;
	string finalOut = "", fileSave;
	for (double i=a; i<=b; i+=step) {
		if (i < 0) {
			out = 0;
			for (int j=1; j<=n; j++) {
				for (int k=1; k<=n; k++) {
					out += (1/(i-j-k));
				}
			}
		} else {
			out = 1;
			for (int j=0; j<=(n-3); j++) {
				out *= (i-j);
			}
		}
		cout << "x = " << i << "; y = " << out << ";\n";
		finalOut += ("x = " + to_string(i) + "; y = " + to_string(out) + ";\n");
	}
	cout << "\nType \"yes\" to save the answer into a file: ";
	cin >> fileSave;
	if (fileSave == "yes") {
		ofstream outFile;
		outFile.open("a" + to_string(int(a)) + " b" + to_string(int(b)) + " step" + to_string(int(step)) \
			+ " n" + to_string(int(n)) + " out.txt");
		outFile << finalOut;
		outFile.close();
		cout << "File saved successfully (" << "a" + to_string(int(a)) + " b" + to_string(int(b)) \
			+ " step" + to_string(int(step)) + " n" + to_string(int(n)) + " out.txt)";
	}
	cout << endl;
	mainMenu();
}

void calculate(double x, double n) {
	double out;
	if (x < 0) {
		out = 0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				out += (1/(x-i-j));
			}
		}
	} else {
		out = 1;
		for (int i=0; i<=(n-3); i++) {
			out *= (x-i);
		}
	}
	cout << "\nThe answer is " << out << "\n\nType \"yes\" to save the answer into a file: ";
	string fileSave;
	cin >> fileSave;
	cout << "\n";
	if (fileSave == "yes") {
		ofstream outFile;
		outFile.open("x" + to_string(x) + " n" + to_string(n) + " out.txt");
		outFile << out;
		outFile.close();
		cout << "File saved successfully (" << "x" << x << " n" << n << " out.txt)\n"; 
	}
	mainMenu();
}