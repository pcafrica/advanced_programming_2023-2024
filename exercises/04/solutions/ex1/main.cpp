#include <cmath>
#include <iostream>

class ADExpression {
public:
  virtual ~ADExpression() = default;

  virtual double evaluate() const = 0;
  virtual double derivative() const = 0;
};

class Scalar : public ADExpression {
public:
  Scalar(const double &val, const double &der = 0.0) : val(val), der(der) {}

  double evaluate() const override { return val; }

  double derivative() const override { return der; }

private:
  const double val;
  const double der;
};

class Sum : public ADExpression {
public:
  Sum(const ADExpression &t1, const ADExpression &t2) : term1(t1), term2(t2) {}

  double evaluate() const override {
    return term1.evaluate() + term2.evaluate();
  }

  double derivative() const override {
    return term1.derivative() + term2.derivative();
  }

private:
  const ADExpression &term1;
  const ADExpression &term2;
};

class Difference : public ADExpression {
public:
  Difference(const ADExpression &t1, const ADExpression &t2)
      : term1(t1), term2(t2) {}

  double evaluate() const override {
    return term1.evaluate() - term2.evaluate();
  }

  double derivative() const override {
    return term1.derivative() - term2.derivative();
  }

private:
  const ADExpression &term1;
  const ADExpression &term2;
};

class Product : public ADExpression {
public:
  Product(const ADExpression &f1, const ADExpression &f2)
      : factor1(f1), factor2(f2) {}

  double evaluate() const override {
    return factor1.evaluate() * factor2.evaluate();
  }

  double derivative() const override {
    return (factor1.derivative() * factor2.evaluate()) +
           (factor1.evaluate() * factor2.derivative());
  }

private:
  const ADExpression &factor1;
  const ADExpression &factor2;
};

class Division : public ADExpression {
public:
  Division(const ADExpression &num, const ADExpression &den)
      : numerator(num), denominator(den) {}

  double evaluate() const override {
    return numerator.evaluate() / denominator.evaluate();
  }

  double derivative() const override {
    const double num_val = numerator.evaluate();
    const double den_val = denominator.evaluate();
    const double num_der = numerator.derivative();
    const double den_der = denominator.derivative();
    return (num_der * den_val - num_val * den_der) / (den_val * den_val);
  }

private:
  const ADExpression &numerator;
  const ADExpression &denominator;
};

class Power : public ADExpression {
public:
  Power(const ADExpression &b, int exp) : base(b), exponent(exp) {}

  double evaluate() const override {
    return std::pow(base.evaluate(), exponent);
  }

  double derivative() const override {
    return exponent * std::pow(base.evaluate(), exponent - 1) *
           base.derivative();
  }

private:
  const ADExpression &base;
  const int exponent;
};

int main() {
  // Set x = 2.0 and its derivative (dx/dx) is 1.0.
  const Scalar x(2.0, 1.0);

  // Define a polynomial: f(x) = 2x^3 - 3x^2 + 4x - 5.
  const auto two = Scalar(2);
  const auto three = Scalar(3);
  const auto four = Scalar(4);
  const auto five = Scalar(5.0);

  const auto x2 = Power(x, 2);
  const auto x3 = Power(x, 3);

  const auto _4x = Product(four, x);
  const auto _2x3 = Product(two, x3);
  const auto _3x2 = Product(three, x2);

  const auto f1 = Difference(_2x3, _3x2);
  const auto f2 = Sum(f1, _4x);

  const auto f = Difference(f2, five);

  // Compute the value and derivative of the polynomial at x.
  const double result = f.evaluate();
  const double derivative = f.derivative();

  // Print the result.
  std::cout << "f(" << x.evaluate() << ") = " << result << std::endl;
  std::cout << "f'(" << x.evaluate() << ") = " << derivative << std::endl;

  // Define the function 1 / x^2.
  const auto one = Scalar(1.0);
  const auto g = Division(one, x2);
  std::cout << "g(" << x.evaluate() << ") = " << g.derivative() << std::endl;

  return 0;
}
