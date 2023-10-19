#include <cmath>
#include <iostream>

class ADExpression {
public:
  virtual ~ADExpression() = default;

  virtual double evaluate() const = 0;
  virtual double derivative() const = 0;
};

class Scalar : public ADExpression {
private:
  double val;
  double der;

public:
  Scalar(double val, double der = 0.0) : val(val), der(der) {}

  double evaluate() const override { return val; }

  double derivative() const override { return der; }
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
  int exponent;
};

int main() {
  // Input values.
  Scalar x(2.0, 1.0); // Set x = 2.0 and its derivative is 1.0 (df/dx)

  // Define a polynomial: f(x) = 2x^3 - 3x^2 + 4x - 5.
  auto f = Difference(Sum(Difference(Product(Scalar(2), Power(x, 3)),
                                     Product(Scalar(3), Power(x, 2))),
                          Product(Scalar(4), x)),
                      Scalar(5.0));

  // Compute the value and derivative of the polynomial at x.
  const double result = f.evaluate();
  const double derivative = f.derivative();

  // Print the result.
  std::cout << "f(" << x.evaluate() << ") = " << result << std::endl;
  std::cout << "f'(" << x.evaluate() << ") = " << derivative << std::endl;

  // Define the function 1 / x^2.
  auto g = Division(Scalar(1.0), Power(x, 2));
  std::cout << "g(" << x.evaluate() << ") = " << g.derivative() << std::endl;

  return 0;
}
