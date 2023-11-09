#include <iostream>
#include <set>

class Access {
public:
  void activate(unsigned int code) { active_codes.insert(code); }

  void deactivate(unsigned int code) { active_codes.erase(code); }

  bool is_active(unsigned int code) const {
    return active_codes.count(code) > 0;
  }

private:
  std::set<unsigned int> active_codes;
};

int main() {
  Access access_system;

  // Activate access codes.
  access_system.activate(1234);
  access_system.activate(9999);
  access_system.activate(9876);

  unsigned int entered_code;
  bool door_opened = false;

  while (!door_opened) {
    std::cout << "Enter your access code: ";
    std::cin >> entered_code;

    if (access_system.is_active(entered_code)) {
      std::cout << "Door opened successfully!" << std::endl;
      door_opened = true;
      access_system.deactivate(entered_code);
    } else {
      std::cout << "Access code is not valid. Please try again." << std::endl;
    }
  }

  access_system.deactivate(9999);
  access_system.activate(1111);

  door_opened = false;

  while (!door_opened) {
    std::cout << "Enter your access code: ";
    std::cin >> entered_code;

    if (access_system.is_active(entered_code)) {
      std::cout << "Door opened successfully!" << std::endl;
      door_opened = true;
    } else {
      std::cout << "Access code is not valid. Please try again." << std::endl;
    }
  }

  return 0;
}
