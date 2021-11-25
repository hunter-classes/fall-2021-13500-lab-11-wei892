#include <iostream>

#include "profile.h"
#include "network.h"

int main() {

  std::cout << "==========Part A==========" << std::endl;
  Profile p1("marco", "Marco");
  std::cout << p1.getUsername() << std::endl; // marco
  std::cout << p1.getFullName() << std::endl; // Marco (@marco)

  p1.setDisplayName("Marco Rossi");
  std::cout << p1.getUsername() << std::endl; // marco
  std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)

  Profile p2("tarma1", "Tarma Roving");
  std::cout << p2.getUsername() << std::endl; // tarma1
  std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

  std::cout << "\n==============================\n" << std::endl;

  std::cout << "==========Part B==========" << std::endl;
  Network nw;
  std::cout << "nw.addUser(\"mario\", \"Mario\"): ";
  bool isPossible = nw.addUser("mario", "Mario");
  std::cout << isPossible << " " << isTrue(isPossible) << std::endl;     // true (1)

  std::cout << "nw.addUser(\"luigi\", \"Luigi\"): ";
  isPossible = nw.addUser("luigi", "Luigi");     // true (1)
  std::cout << isPossible << " " << isTrue(isPossible) << std::endl;

  std::cout << "nw.addUser(\"mario\", \"Mario\"): ";
  isPossible = nw.addUser("mario", "Mario2");    // false (0)
  std::cout << isPossible << " " << isTrue(isPossible) << std::endl;
  
  std::cout << "nw.addUser(\"mario 2\", \"Mario2\"): ";
  isPossible = nw.addUser("mario 2", "Mario2");  // false (0)
  std::cout << isPossible << " " << isTrue(isPossible) << std::endl;
  
  std::cout << "nw.addUser(\"mario-2\", \"Mario2\"): ";
  isPossible = nw.addUser("mario-2", "Mario2");  // false (0)
  std::cout << isPossible << " " << isTrue(isPossible) << std::endl;
 
  for(int i = 2; i < 20; i++){
    std::cout << "nw.addUser(\"mario" + std::to_string(i) + "\", \"Mario" + std::to_string(i) + "\"): ";
    isPossible = nw.addUser("mario" + std::to_string(i),
			    "Mario" + std::to_string(i));   // true (1)
    std::cout << isPossible << " " << isTrue(isPossible) << std::endl;
  }
  
  std::cout << "nw.addUser(\"yoshi\", \"Yoshi\"): ";
  isPossible = nw.addUser("yoshi", "Yoshi");     // false (0)
  std::cout << isPossible << " " << isTrue(isPossible) << std::endl;
  
  return 0;
}
