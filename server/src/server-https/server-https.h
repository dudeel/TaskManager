#pragma once

class ServerHTTPS {
public:
  ServerHTTPS(int port = 443);
  ServerHTTPS(const ServerHTTPS &other) = default;
  ServerHTTPS &operator=(const ServerHTTPS &other) = default;
  ServerHTTPS(ServerHTTPS &&other) = default;
  ServerHTTPS &operator=(ServerHTTPS &&other) = default;
  ~ServerHTTPS() = default;

public:
  bool start();

private:
  int _socket = -1;
  int _port = 443;
};
