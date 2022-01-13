#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "server.h"
#include <QTimer>

namespace communication {
	class Communication : public QObject {
		Q_OBJECT
	private:
		Server server;
		QTimer timer;
	public:
		Communication();
		virtual ~Communication();
		bool start();
	public slots:
		void on_new_message();
		void on_timeout();
	};
} // namespace communication

#endif // COMMUNICATION_H
