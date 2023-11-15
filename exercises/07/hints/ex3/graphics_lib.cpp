#include "graphics_lib.hpp"
#include <iostream>

void GraphicsLib::draw_rectangle(double width, double height) {
  const double area = MathLib::multiply(width, height);
  std::cout << "Drawing a rectangle with area: " << area << std::endl;
}
