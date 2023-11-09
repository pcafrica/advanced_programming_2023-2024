#include <iostream>
#include <map>

class Access {
public:
  void activate(unsigned int code, unsigned int level) {
    access_codes[code] = level;
  }

  void deactivate(unsigned int code) { access_codes.erase(code); }

  bool is_active(unsigned int code, unsigned int level) const {
    auto it = access_codes.find(code);
    if (it != access_codes.end()) {
      return it->second >= level;
    }
    return false;
  }

private:
  std::map<unsigned int, unsigned int> access_codes;
};

int main() {
  Access access_system;

  // Activate access codes with access levels.
  access_system.activate(1234, 1);
  access_system.activate(9999, 5);
  access_system.activate(9876, 9);

  unsigned int entered_code;
  unsigned int required_level = 5;
  bool door_opened = false;

  while (!door_opened) {
    std::cout << "Enter your access code for level " << required_level << ": ";
    std::cin >> entered_code;

    if (access_system.is_active(entered_code, required_level)) {
      std::cout << "Door opened successfully!" << std::endl;
      access_system.activate(9999, 8);
      access_system.activate(1111, 7);
      door_opened = true;
      access_system.deactivate(entered_code);
    } else {
      std::cout << "Access code is not valid for the current level "
                << required_level
                << ". Please try "
                   "again."
                << std::endl;
    }
  }

  required_level = 7;
  door_opened = false;

  while (!door_opened) {
    std::cout << "Enter your access code for level " << required_level << ": ";
    std::cin >> entered_code;

    if (access_system.is_active(entered_code, 7)) {
      std::cout << "Door opened successfully!" << std::endl;
      door_opened = true;
    } else {
      std::cout << "Access code is not valid for the current level. Please try "
                   "again."
                << std::endl;
    }
  }

  return 0;
}
