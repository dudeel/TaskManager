#pragma once

#import <iostream>

namespace database {
class Database {
public:
  virtual bool connectToDB();
  virtual bool isConnected();

  virtual bool setHostName();
  virtual bool setPort();
  virtual bool setDatabaseName();
  virtual bool setUserName();
  virtual bool setPassword();

  virtual std::string &HostName() const noexcept;
  virtual int &Port() const noexcept;
  virtual std::string &DatabaseName() const noexcept;
  virtual std::string &UserName() const noexcept;
  virtual std::string &Password() const noexcept;

private:
  bool _isConnected;

  std::string _hostName;
  int _port;
  std::string _databaseName;
  std::string _userName;
  std::string _password;

public:
  Database();
  virtual ~Database() = default;

  Database(const Database &other) = delete;
  Database &operator=(const Database &other) = delete;

  Database(Database &&other) noexcept = default;
  Database &operator=(Database &&other) noexcept = default;
};
} // namespace database
