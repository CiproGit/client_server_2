#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

namespace communication {
	const QString HOST_ADDRESS = "127.0.0.1";
	const quint16 PORT = 50000;

	class Server : public QObject{
		Q_OBJECT
	private:
		QTcpServer tcp_server;
		QTcpSocket *tcp_socket;
	public:
		Server();
		virtual ~Server();
		bool start();
		QTcpSocket *get_socket() const;
	public slots:
		void on_newConnection();
	signals:
		void new_message();
	};
} // namespace communication

#endif // SERVER_H
