#include <QCoreApplication>

#include "server-https/server-https.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  // ServerHTTPS serverHTTPS(443);
  return a.exec();
}
