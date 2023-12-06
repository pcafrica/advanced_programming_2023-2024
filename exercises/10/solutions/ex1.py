#!/usr/bin/env python3

from math import sin

def step_counter(generator_func):
    def wrapper(*args, **kwargs):
        gen = generator_func(*args, **kwargs)
        wrapper.steps = 0

        while True:
            wrapper.steps += 1
            print(f"Step number: {wrapper.steps}")
            yield next(gen)
            print()

    return wrapper

@step_counter
def explicit_euler(u0, h):
    u = u0
    while True:
        u = u - h * sin(u)
        yield u

gen = explicit_euler(u0=1.0, h=0.1)
for _ in range(10):
    print(next(gen))
