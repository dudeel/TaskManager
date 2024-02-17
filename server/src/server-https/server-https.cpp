#include "server-https.h"
#include <QDebug>

ServerHTTPS::ServerHTTPS(int port) : _port(port) { qDebug() << _port; }
