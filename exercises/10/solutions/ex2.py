#!/usr/bin/env python3

from time import time

class Polynomial:
    def __init__(self, *coefficients):
        self.coefficients = coefficients

    def __repr__(self):
        terms = [f"{a}x^{i}" if i > 1 else f"x" if i == 1 else str(a) for i, a in enumerate(self.coefficients)]
        return " + ".join(terms)

    def __add__(self, other):
        common_len = min(len(self.coefficients), len(other.coefficients))
        new_coefficients = [a + b for a, b in zip(self.coefficients, other.coefficients)]
        remaining_coefficients = (
            self.coefficients[common_len:] + other.coefficients[common_len:]
        )
        new_coefficients += remaining_coefficients
        return Polynomial(*new_coefficients)

    def __mul__(self, other):
        new_coefficients = [0] * (len(self.coefficients) + len(other.coefficients) - 1)
        for i, a in enumerate(self.coefficients):
            for j, b in enumerate(other.coefficients):
                new_coefficients[i + j] += a * b
        return Polynomial(*new_coefficients)

    
    @classmethod
    def from_string(cls, poly_str):
        terms = poly_str.split("+")
        coefficients = [int(term.split("x")[0]) for term in terms]
        return cls(*coefficients)

class StandardPolynomialEvaluator(Polynomial):
    def evaluate(self, x_list):
        return [sum(a * (x ** i) for i, a in enumerate(self.coefficients)) for x in x_list]

class HornerPolynomialEvaluator(Polynomial):
    def evaluate(self, x_list):
        y_list = []
        for x in x_list:
            result = 0
            for a in reversed(self.coefficients):
                result = result * x + a
            y_list.append(result)
        return y_list

def measure_time(func):
    def wrapper(*args, **kwargs):
        start_time = time()
        result = func(*args, **kwargs)
        end_time = time()
        print(f"Time taken by {func.__name__}: {end_time - start_time} seconds.\n")
        return result
    return wrapper

@measure_time
def evaluate_polynomial(poly_evaluator, x_list):
    return poly_evaluator.evaluate(x_list)

poly1 = Polynomial(1, 2, 3)
poly2 = Polynomial(2, 3, 4)
print(poly1 + poly2)
print(poly1 * poly2, '\n')

poly3 = Polynomial.from_string("1 + 2x + 3x^2")
print(poly3, '\n')

standard_evaluator = StandardPolynomialEvaluator(1, 2, 3)
horner_evaluator = HornerPolynomialEvaluator(1, 2, 3)

print("Standard evaluation")
result_standard = evaluate_polynomial(standard_evaluator, range(1000))
print("Horner evaluation")
result_horner = evaluate_polynomial(horner_evaluator, range(1000))

assert result_standard == result_horner
