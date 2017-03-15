#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void show_help(const char* prog_name)
{
  std::cout << "Usage: " << prog_name << " [number]\n" <<
               "[number] is max number of display numbers" << std::endl;
}

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false); // for runtime speed.

  if (argc < 2) { // need argv[1] for search limit.
    show_help(*argv);
    return 0;
  }

  std::uintmax_t limit {std::stoull(argv[1])}; // get search limit.
  if (limit < 2) return 0; // non-exist prime.

  std::vector<std::uintmax_t> primes {2}; // 2 is prime.
  std::cout << "2\n";

  for (std::uintmax_t i {3}; i <= limit; i += 2) // search prime. (if limit is 2, not into loop)
    if (std::all_of(primes.begin(), primes.end(), [i](auto prime){return i % prime;})) {
      // above mean every prime are that (i % prime) is not 0.
      // 訳:今まで見つかった全ての素数で割り切れなければ素数.
      primes.push_back(i); // add found prime
      std::cout << i << '\n'; // tell the prime.
    }
  std::cout << std::flush;
  return 0;
}
