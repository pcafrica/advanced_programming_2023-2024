#!/usr/bin/env python3

# 1.
def website(url):
    return url.split(".")[1]

print(website("www.google.com"))


# 2.
def divisible(a, b):
    return True if a % b == 0 else False

print(divisible(10, 3))
print(divisible(6, 3))

# 3.
l = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print([_ ** 2 for _ in l])

# 4.
names = ['Steve Irwin', 'koala', 'kangaroo', 'Australia', 'Sydney', 'desert']
print([_ for _ in names if _[0].isupper()])

# 5.
keys = [f"key-{k}" for k in range(10)]
vals = range(10)
print({k:v for k, v in zip(keys, vals)})

# 6.
try:
    5 / 0
except ZeroDivisionError:
    print("I caught you!")

# 7.
def listgen(n):
    counter = 0
    numbers = list(range(n))
    while counter <= n // 10:
        yield numbers[(10 * counter) : (10 * (counter+1))]
        counter += 1

g = listgen(100)
print(next(g))
print(next(g))
print(next(g))

g = listgen(5)
print(next(g))

# 8.
matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
print([[row[i] for row in matrix] for i in range(4)])

# 9.
def lucky_sum(*args):
    if 13 in args:
        return sum(args[:args.index(13)])
    return sum(args)

print(lucky_sum(1, 2, 3, 4))
print(lucky_sum(1, 13, 3, 4))
print(lucky_sum(13))

# 10.
two_channel_eeg_signal1 = [8, 9]
event1 = 1

two_channel_eeg_signal2 = [3, 3]
event2 = 2

two_channel_eeg_signal3 = [2, 3]
event3 = 2

nested_list = []
nested_list.append([two_channel_eeg_signal1, event1])
nested_list.append([two_channel_eeg_signal2, event2])
nested_list.append([two_channel_eeg_signal3, event3])
print("EEG signal: ", nested_list)

# (1) Using a for loop.
eeg_signals = []
events = []

for item in nested_list:
    #eeg_signals.append(item[0]) # Create a list of lists.
    eeg_signals.extend(item[0]) # Flattened.
    events.append(item[1])

print("EEG signals (using for loop):", eeg_signals)
print("Events (using for loop):", events)

# (2) Using list comprehension.
#eeg_signals = [item[0] for item in nested_list] # Create a list of lists.
eeg_signals = [value for item in nested_list for value in item[0]] # Flattened.
events = [item[1] for item in nested_list]

print("EEG signals (using list comprehension):", eeg_signals)
print("Events (using list comprehension):", events)
