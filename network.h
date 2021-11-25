#pragma once

#include <string>
#include "profile.h"

class Network {
 private:
  static const int MAX_USERS = 20;
  Profile profiles[MAX_USERS];
  int numUsers;
  int findID(std::string usern);

public:
  Network();
  bool addUser(std::string usern, std::string dspn);
};

std::string isTrue(bool b);
