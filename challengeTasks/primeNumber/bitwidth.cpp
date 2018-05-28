#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>
#include <valarray>

using namespace std;

template<typename T>
constexpr auto check(const vector<uint32_t>& pflag, const T& n)
{
  return pflag[n >> 6] & (1 << ((n >> 1) & 0x1f));
}

template<typename T>
constexpr void set(vector<uint32_t>& pflag, const T& n)
{
  pflag[n >> 6] |= (1 << ((n >> 1) & 0x1f));
}

vector<uint64_t> sieve(uint64_t n) {
  vector<uint64_t> primes(50847534L);
  vector<uint32_t> pflag((n >> 6) + 1);

  uint64_t lmt = sqrt(n);
  for (uint64_t i = 3; i <= lmt; i += 2)
    if (!check(pflag, i))
      for (uint64_t j = i * i, k = i << 1; j < n; j += k)
        set(pflag, j);

  primes[0] = 2;
  uint64_t index = 0;
  for (uint64_t i = 3; i < n; i += 2)
    if (!check(pflag, i))
      primes[++index] = i;

  primes.resize(index + 1);
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

  const auto startTime = chrono::system_clock::now();
  auto primes = sieve(target);
  const auto endTime = chrono::system_clock::now();
  const auto timeSpan = endTime - startTime;
  auto len = primes.size();
  cout << "Prime count=" << len << ", last value=" << primes[len-1] << '\n';
  cout << "Elapsed: " << chrono::duration_cast<chrono::milliseconds>(timeSpan).count() << " ms" << endl;
  return 0;
}
