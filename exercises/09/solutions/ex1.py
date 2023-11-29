# 1.
print(5 ** 5)

# 2.
print(73 % 6)

# 3.
print(1234 // 3)
print(1234 % 3)

# 4.
s = "apple#banana#cherry#orange"
print(s.split("#"))

# 5.
email = "pafrica@fakemail.com"
print(email.split("@")[-1].split(".com")[0])

# 6.
thing = "light"
speed = 299792458  # m/s
print(f"The speed of {thing} is {speed:2e} m/s.")

# 7.
l = [10,[3,4],[5,[100,200,['AdvProg']],23,11],1,7]

print(*l[2][1][2])

# 8.
d = {
    "outer": [
        1,
        2,
        3,
        {"inner": ["this", "is", "inception", {"inner_inner": [1, 2, 3, "AdvProg"]}]},
    ]
}

print(d['outer'][3]['inner'][3]['inner_inner'][3])

# 9.
t = (1, 2, 3, 4, 5)
# t[-1] = 6 # TypeError: 'tuple' object does not support item assignment

# 10.
language = "Python"
if language.lower() == "python":
    print("I love snakes!")
elif language.lower() == "c++":
    print("Are you a pirate?")
else:
    print(f"What is {language}?")
