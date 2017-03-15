#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <random>
#include <string>
#include <utility>

template<typename... Args>
std::array<std::string, sizeof...(Args)> make_str_array(Args&&... args)
{
  return {std::forward<Args>(args)...};
}

int main(int argc, char** argv)
{
  auto names {make_str_array("apple", "apricot", "cherry", "kiwi fruit", "kumquat", "persimmon", "pomegranate", "strawberry")}; 
  // above is correct order.

  std::shuffle(names.begin(), names.end(), std::default_random_engine{std::random_device{}()});

  std::cout << "before:\n";
  std::for_each(names.begin(), names.end(), [](const auto& e){std::cout << e << ' ';});
  std::cout << std::endl;

  std::sort(names.begin(), names.end(), [](const auto& lhs, const auto& rhs){
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  });
  // But default operator< is lexicograhical less than.
  // 訳: lexicographical_compareで辞書順比較してますが、元々std::stringは辞書順にソートされます。

  std::cout << "after:\n";
  std::for_each(names.begin(), names.end(), [](const auto& e){std::cout << e << ' ';});
  std::cout << std::endl;
  return 0;
}
