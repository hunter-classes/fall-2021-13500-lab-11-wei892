#pragma once

#include <string>
#include "profile.h"

class Network {
 private:
  static const int MAX_USERS = 20;
  Profile profiles[MAX_USERS];
  int numUsers;
  int findID(std::string usern);
  bool following[MAX_USERS][MAX_USERS];

public:
  Network();
  bool addUser(std::string usern, std::string dspn);
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
};

std::string isTrue(bool b);
