#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <stdexcept>

enum class Hand : int
{
  rock = 0,
  paper = 1,
  scissors = 2,
};

const std::unordered_map<std::string, Hand> valid_input_map { // ユーザ入力マップ
    {"r", Hand::rock}, {"rock", Hand::rock}, {"gu", Hand::rock}, // specify of rock
    {"p", Hand::paper}, {"paper", Hand::paper}, {"pa", Hand::paper}, // specify of paper
    {"s", Hand::scissors}, {"scissors", Hand::scissors}, {"choki", Hand::scissors} // specify of choki
};
const std::unordered_map<int, std::string> result_message {{0, "tie"}, {1, "win"}, {2, "lose"}}; // リザルトマップ
std::random_device seed_generator {}; // 乱数(動作が遅い)
std::default_random_engine rand_engine {seed_generator()}; // 擬似乱数(早い)　乱数で擬似乱数を初期化することで乱数とみなせる
std::uniform_int_distribution<> dist {0, 2}; // 一様分布 [0, 2]

int main(int argc, char** argv)
{
  while (true) { // forever
    std::cout << "Input your hand!\n > " << std::flush; // ユーザに入力を促す
    std::string your_input {};
    std::cin >> your_input; // 入力を受け取る

    auto it = valid_input_map.find(your_input); // valid_input_mapから入力された手を探す
    if (it == vaild_input_map.end()) // not found
      continue; // back to "Input your hand!"

    auto user_hand = *it; // get your input.

    auto enemy_hand {dist(rand_engine)}; // 擬似乱数を用いて一様分布を生成

    auto judge {(static_cast<int>(user_hand) + 3 - enemy_hand) % 3}; // 結果を計算
    std::cout << "You " << result_message.at(judge) << '\n' << std::endl; // リザルトマップで結果を表示
  }
  return 0;
}
