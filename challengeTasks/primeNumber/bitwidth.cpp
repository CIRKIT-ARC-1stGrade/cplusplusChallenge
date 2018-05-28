#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
constexpr auto check(const vector<bitset<32>>& pflag, const T& n)
{
  return pflag[n >> 6].test((n >> 1) & 0x1f);
}

template<typename T>
constexpr void set(vector<bitset<32>>& pflag, const T& n)
{
  pflag[n >> 6].set((n >> 1) & 0x1f);
}

vector<uint64_t> sieve(uint64_t n) {
  vector<bitset<32>> pflag(((n + 1) >> 6) + 1);

  uint64_t lmt = sqrt(n);
  for (uint64_t i = 3; i <= lmt; i += 2)
    if (!check(pflag, i))
      for (uint64_t j = i * i, k = i << 1; j <= n; j += k)
        set(pflag, j);

  vector<uint64_t> primes {};
  primes.reserve(50847534L);
  primes.emplace_back(2);
  for (uint64_t i = 3; i <= n; i += 2)
    if (!check(pflag, i))
      primes.emplace_back(i);

  primes.shrink_to_fit();
  return primes;
}

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  if (argc < 2) {
    cerr << "Need argument for target\n";
    return 1;
  }

  const auto target {stoull(argv[1])};
  if (target <= 1)
    return 0;

  for (const auto& e : sieve(target))
    cout << e << '\n';
  return 0;
}
