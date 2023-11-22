#include "muparserx/mpParser.h"
#include <iostream>

int main() {
  // Create the parser instance.
  mup::ParserX p;

  // Create some basic values.
  mup::Value a(2.0);
  mup::Value c(mup::cmplx_type(1, 1));
  mup::Value s("Hello World");
  mup::Value f(1.1);

  // Now add the variable to muParser.
  p.DefineVar("a", mup::Variable(&a));
  p.DefineVar("c", mup::Variable(&c));
  p.DefineVar("s", mup::Variable(&s));
  p.DefineVar("f", mup::Variable(&f));

  p.SetExpr("a + c * strlen(s) - f");

  for (unsigned int i = 0; i < 10; ++i) {
    // Evaluate the expression and change the value of
    // the variable c in each turn.
    c = mup::cmplx_type(1.1 * i, 1.1 * i);
    const mup::Value result = p.Eval();

    // Print the result.
    std::cout << result << std::endl;
  }

  return 0;
}
