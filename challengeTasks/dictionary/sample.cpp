#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char** argv)
{
  std::vector<std::string> names {"apple", "apricot", "cherry", "kiwi fruit", "kumquat", "persimmon", "pomegranate", "strawberry"};
  // above is correct order.

  std::shuffle(names.begin(), names.end(), std::default_random_engine{std::random_device{}()});

  std::cout << "before:\n";
  std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>{std::cout, " "});
  std::cout.put('\n');

  std::sort(names.begin(), names.end(), [](const auto& lhs, const auto& rhs){
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  });
  // But default operator< is lexicograhical less than.
  // 訳: lexicographical_compareで辞書順比較してますが、元々std::stringは辞書順にソートされます。

  std::cout << "after:\n";
  std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>{std::cout, " "});
  std::cout.put('\n');
  return 0;
}
