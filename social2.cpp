#include "social.h"
#include "social2.h"

#include <string>
#include <cctype>

int Network::findID(std::string usern){
  bool foundID = false;
  int location;
  for (int i = 0; i < MAX_USERS; i++){
    if (profiles[i].getUsername() == usern){
      return i;
    }
  }
  
  return -1;
}

Network::Network(){
  int numusers = 0;
}

bool Network::addUser(std::string usern, std::string dspn){
  //check if 20 users
  if (numUsers == 20){
    return false;
  }

  for (int i = 0; i < MAX_USERS; i++){
    //if there is matching usernames
    if (usern == profiles[i].getUsername()){
      return false;
    }
  }

  //checks if alphanum
  for (int i = 0; i < usern.length(); i++){
    char c = usern[i];
    if (!isalnum(c)){
      return false;
    }
  }
  

  //if all conditions are passed,
  numUsers++;
  profiles[numUsers - 1] = {usern, dspn};
  return true;
}

std::string isTrue(bool b){
  if (b == true){
    return "True";
  }
  else {
    return "False";
  }
}
