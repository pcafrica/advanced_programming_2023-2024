#include <iostream>
#include <string>

int main() {
  double temperature;
  std::string unit;

  // Prompt the user for input.
  std::cout << "Enter a temperature: ";
  std::cin >> temperature;

  // Prompt the user for the unit of temperature.
  std::cout << "Enter the unit of temperature (Celsius or Fahrenheit): ";
  std::cin >> unit;

  // Perform the conversion based on the provided unit.
  double temperature_converted;

  if (unit == "Celsius" || unit == "celsius" || unit == "C") {
    // Convert from Celsius to Fahrenheit.
    temperature_converted = (9.0 / 5.0) * temperature + 32;

    std::cout << "Temperature in Fahrenheit: " << temperature_converted << " F"
              << std::endl;
  } else if (unit == "Fahrenheit" || unit == "fahrenheit" || unit == "F") {
    // Convert from Fahrenheit to Celsius.
    temperature_converted = (5.0 / 9.0) * (temperature - 32);

    std::cout << "Temperature in Celsius: " << temperature_converted << " C"
              << std::endl;
  } else {
    // Invalid unit input.
    std::cout << "Invalid unit input. Please enter 'Celsius' or 'Fahrenheit'."
              << std::endl;

    return 1; // Exit with an error code.
  }

  return 0;
}
