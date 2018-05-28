#include <cmath>
#include <cstdint>
#include <iostream>
#include <valarray>

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  if (argc == 1) {
    std::cout << "Usage: " << *argv << " [number]\n" <<
                 "[number] is a positive number." << std::endl;
    return 1;
  }

  const std::uintmax_t limit {std::stoull(argv[1])}; // get search limit.
  if (limit <= 1) return 0;

  std::valarray<bool> prims(true, limit + 1); // array of [0] to [limit]
  prims[std::slice(0, 2, 1)] = false; // 0 and 1 aren't primes. (not needed)

  const std::uintmax_t search_limit {static_cast<std::uintmax_t>(std::floor(std::sqrt(static_cast<long double>(limit)))) + 1};
  for (std::uintmax_t i {2}; i < search_limit; ++i)
    if (prims[i])
      prims[std::slice(i*i, limit / i - (i - 1), i)] = false;

  for (std::uintmax_t i {2}; i <= limit; ++i)
    if (prims[i])
      std::cout << i << '\n';
}
