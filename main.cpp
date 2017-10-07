#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void inputMenu(), mainMenu(), aboutMenu();

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
		cout << "\nThere is no \"" << input << "\" command.\nYou can only use \"input\", \"about\" and \"exit\"\n\n";
		mainMenu();
	}
}

void inputMenu() {
	cout << "\033[H\033[2J" << std::flush;
	int x, n;
	cout << "\nType x: ";
	cin >> x;
	cout << "Type n: ";
	cin >> n;
	double out;
	if (x < 0) {

		out = 0;

		for (double i=1; i<=n; i++) {
			for (double j=1; j<=n; j++) {
				out += (1/(x-i-j));
			}
		}
	} else {

		out = 1;

		for (double i=0; i<=(n-3); i++) {
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

void aboutMenu() {
	cout << "\033[H\033[2J" << std::flush;
	cout << "\n/–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\\\n";
	cout << "| Lab for Fundamentals of Software Engineering by Ihor Tytarenko v.1.0.0      |\n";
	cout << "|                                                                             |\n";
	cout << "| Email me if you have any idea how to improve the app: jaxmef.uni@gmail.com  |";
	cout << "\n\\–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––/\n\n";
	mainMenu();
}

// min = a<b ? a:b or min = a>b ? b:a