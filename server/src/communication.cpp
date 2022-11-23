#include "../include/communication.h"
#include <iostream>

using namespace std;

namespace communication {
	Communication::Communication() {
		connect(&(this->server), SIGNAL(new_message()), this, SLOT(on_new_message()));

		this->timer.setInterval(5000);
		connect(&(this->timer), SIGNAL(timeout()), this, SLOT(on_timeout()));
	}

	Communication::~Communication() {}

	bool Communication::start() {
		if (this->server.start()) return true;
		else return false;
	}

	void Communication::on_new_message() {
		QTcpSocket *tcp_socket = this->server.get_socket();

		QByteArray ingoing_message = tcp_socket->readAll();
		cout << ingoing_message.size() << " bytes received\n";
		cout << "Ingoing message: " << QString(ingoing_message).toStdString() << '\n' << endl;

		this->timer.start();
	}

	void Communication::on_timeout() {
		QTcpSocket *tcp_socket = this->server.get_socket();

		QByteArray outgoing_message;
		outgoing_message.append("Bip!");
		cout << "Outgoing message: " << QString(outgoing_message).toStdString() << '\n';
		cout << tcp_socket->write(outgoing_message) << " bytes sent\n" << endl;
	}
} // namespace communication
