#ifndef COMPARE_POLICY_HPP__
#define COMPARE_POLICY_HPP__
#include <cctype>
#include <string>

// Case sensitive comparator.
class CaseCompare {
public:
  bool operator()(const char &a, const char &b) const { return a == b; }
};

// Case insensitive comparator.
class NoCaseCompare {
public:
  bool operator()(const char &a, const char &b) const {
    return std::toupper(a) == std::toupper(b);
  }
};

// Function that compares two strings according to a policy.
//
// The policy is provided as a template parameter. We assume that
// it is default-constructible and has a call operator that takes two chars
// and returns true if and only if they are considered equivalent.
template <class Policy> bool equal(const std::string &a, const std::string &b) {
  if (a.size() != b.size()) {
    return false;
  }

  Policy equal{};

  for (std::size_t i = 0; i < a.size(); ++i) {
    if (!equal(a[i], b[i])) {
      return false;
    }
  }

  return true;
}

// Functor class to compare strings according to a policy, stored as class
// member.
template <class Policy> class CompareString {
public:
  CompareString() : compare{} {}

  bool operator()(const std::string &a, const std::string &b) const {
    if (a.size() != b.size()) {
      return false;
    }

    for (std::size_t i = 0; i < a.size(); ++i) {
      if (!compare(a[i], b[i])) {
        return false;
      }
    }

    return true;
  }

private:
  Policy compare;
};

#endif /* COMPARE_POLICY_HPP__ */
