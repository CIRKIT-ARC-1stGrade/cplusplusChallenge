#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false); // for runtime speed.

  if (argc == 1) { // need argv[1] for search limit.
    std::cout << "Usage: " << *argv << " [number]\n" <<
                 "[number] is max number of display numbers" << std::endl;
    return 0;
  }

  std::uintmax_t limit {std::stoull(argv[1])}; // get search limit.
  if (limit <= 1) return 0; // non-exist prime.

  std::vector<std::uintmax_t> primes {2}; // 2 is prime.

  for (std::uintmax_t i {3}; i <= limit; i += 2) // search prime. (if limit is 2, not into loop)
    if (std::all_of(primes.begin(), std::upper_bound(primes.begin(), primes.end(), std::sqrt(static_cast<long double>(i))),
                    [i](auto prime){return i % prime;})) {
      // above mean every prime are that (i % prime) is not 0.
      // 訳:今まで見つかった全ての素数で割り切れなければ素数.
      primes.push_back(i); // add found prime
    }

  std::copy(primes.begin(), primes.end(), std::ostream_iterator<std::uintmax_t>{std::cout, "\n"});
  std::cout << std::flush;
  return 0;
}
