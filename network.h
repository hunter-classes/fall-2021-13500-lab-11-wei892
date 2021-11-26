/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 11

this is the header file for the network class

*/

#pragma once

#include <string>
#include "profile.h"

struct Post{
  std::string username;
  std::string message;
};

class Network {
 private:
  static const int MAX_USERS = 20;
  Profile profiles[MAX_USERS];
  int numUsers;
  int findID(std::string usern);
  bool following[MAX_USERS][MAX_USERS];
  static const int MAX_POSTS = 100;
  int numPosts;
  Post posts[MAX_POSTS];

public:
  Network();
  bool addUser(std::string usern, std::string dspn);
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
  bool writePost(std::string usrn, std::string msg);
  bool printTimeline(std::string usrn);
};

std::string isTrue(bool b);
