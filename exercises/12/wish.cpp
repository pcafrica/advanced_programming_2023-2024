#include <array>
#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>

inline static constexpr std::string_view reset_color = "\u001B[0m";
inline static constexpr std::array<std::string_view, 8> colors = {
    "\u001B[30m", "\u001B[31m", "\u001B[32m", "\u001B[33m",
    "\u001B[34m", "\u001B[35m", "\u001B[36m", "\u001B[37m"};

std::string_view get_color(unsigned int c) {
  if (c < colors.size()) {
    return colors[c];
  }

  throw std::invalid_argument("Invalid color index.");
}

#include <vector>

std::string char_code_to_string(const std::vector<int> &codes) {
  std::string result;
  for (auto code : codes) {
    result += static_cast<char>(code);
  }
  return result;
}

void print(const std::array<int, 3> &params) {
  const std::string padding = "      ";

  const int height = std::abs(params[0]);

  const int max_str_len = 2 * height + 1;

  const int t_height = std::abs(params[1]);

  const int t_width =
      std::min(max_str_len, std::abs(params[2]) - std::abs(params[2]) % 2 + 1);

  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_int_distribution<> randi(5, 19);

  std::cout << std::endl;

  int space = max_str_len / 2;
  std::cout << padding << std::string(space, ' ');
  std::cout << colors[3] << "X--.." << reset_color << std::endl;

  for (int layer = 3; layer <= max_str_len; layer += 2) {
    std::cout << colors[2] << padding;
    space = (max_str_len / 2) - (layer / 2);
    std::cout << std::string(space, ' ');

    static int counter = 0;
    for (int i = 0; i < layer; ++i) {
      if (counter++ % randi(engine) == 0) {
        unsigned int color_index;
        do {
          color_index = engine() % 6 + 1;
        } while (color_index == 4);
        std::cout << get_color(color_index) << "O" << colors[2];
      } else {
        std::cout << "*";
      }
    }
    std::cout << std::endl;
  }

  space = (max_str_len / 2) - (t_width / 2);
  for (int i = 0; i < t_height; ++i) {
    std::cout << colors[3] << padding << std::string(space, ' ')
              << std::string(t_width, '*') << std::endl;
  }
  std::cout << std::endl;

  const std::string banner =
      char_code_to_string({124, 32,  32,  45,  45,  62,  32,  72,
                           97,  112, 112, 121, 32,  104, 111, 108,
                           105, 100, 97,  121, 115, 33,  32}) +
      std::string(u8"\U0001F973") +
      char_code_to_string({32, 60, 45, 45, 32, 32, 124});

  space = (max_str_len - banner.size()) / 2 + padding.size() + 1;
  std::cout << colors[1] << std::string(std::max(space, 0), ' ') << banner
            << std::endl
            << std::endl
            << reset_color;
}

int main(int argc, char **argv) {
  std::array<int, 3> params = {10, 3, 5};

  if (argc > 1) {
    for (int i = 1; i < argc && i < 4; ++i) {
      params[i - 1] = static_cast<size_t>(std::stoi(argv[i]));
    }
  }

  print(params);

  return 0;
}
