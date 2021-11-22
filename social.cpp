#include "social.h"
#include <string>

Profile::Profile(){
  username = "";
  displayname = "";
}

Profile::Profile(std::string usrn, std::string dspn){
  username = usrn;
  displayname = dspn;
}

std::string Profile::getUsername(){
  return username;
}

std::string Profile::getFullName(){
  std::string output = "\"" + displayname + " (@" + username + ")\"";
  return output;
}

void Profile::setDisplayName(std::string dspn){
  displayname = dspn;
}
