#include "../include/server.h"
#include <iostream>

using namespace std;

namespace communication {
	Server::Server() {
		connect(&this->tcp_server, SIGNAL(newConnection()), this, SLOT(on_newConnection()));
	}

	Server::~Server() {
		this->tcp_server.close();
	}

	bool Server::start() {
		if (this->tcp_server.listen(QHostAddress(HOST_ADDRESS), PORT)) {
			cout << "Server listening...\n" << endl;
			return true;
		}
		else {
			cerr << "Error: server not listening" << endl;
			return false;
		}
	}

	QTcpSocket *Server::get_socket() const {
		return this->tcp_socket;
	}

	void Server::on_newConnection() {
		this->tcp_socket = this->tcp_server.nextPendingConnection();
		connect(this->tcp_socket, SIGNAL(readyRead()), this, SIGNAL(new_message()));
	}
} // namespace communication
