#include "../include/communication.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "**********************\n";
	cout << "*       SERVER       *\n";
	cout << "**********************\n" << endl;

	QApplication app(argc, argv);

	cout << "Starting server..." << endl;
	communication::Communication communication;
	if (!communication.start()) return EXIT_FAILURE;
	app.exec();

	cout << "Closing server..." << endl;
	communication.~Communication();

	cout << "End" << endl;
	return EXIT_SUCCESS;
}
