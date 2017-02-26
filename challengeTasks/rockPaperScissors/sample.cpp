#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <stdexcept>

enum class Hand : char
{
  rock = 0,
  paper = 1,
  scissor = 2,
};

int main() {
  const std::unordered_map<std::string, Hand> valid_input_map { // ユーザ入力マップ
      {"r", Hand::rock}, {"rock", Hand::rock}, {"gu", Hand::rock}, // specify of rock
      {"p", Hand::paper}, {"paper", Hand::paper}, {"pa", Hand::paper}, // specify of paper
      {"s", Hand::scissor}, {"scissor", Hand::scissor}, {"choki", Hand::scissor} // specify of choki
  };
  const std::unordered_map<int, std::string> result_message {{0, "tie"}, {1, "win"}, {2, "lose"}}; // リザルトマップ
  std::random_device seed_generator {}; // 乱数(動作が遅い)
  std::default_random_engine rand_engine {seed_generator()}; // 擬似乱数(早い)　乱数で擬似乱数を初期化することで乱数とみなせる
  std::uniform_int_distribution<> dist {0, 2}; // 一様分布 [0, 2]

  while (true) { // forever
    Hand user_hand;

    {
      std::cout << "Input your hand!\n > " << std::flush; // ユーザに入力を促す
      std::string your_input {};
      std::cin >> your_input; // 入力を受け取る

      try {
        user_hand = valid_input_map.at(your_input); // valid_input_mapから入力された手を探す
      } catch(const std::out_of_range&) { // もしvalid_input_mapに存在しなければこっち
        std::cout << "Your input is wrong" << std::endl;
        continue; // continue "Input your hand!\n > "
      }
    }

    auto enemy_hand {dist(rand_engine)}; // 擬似乱数を用いて一様分布を生成

    auto judge {(static_cast<int>(user_hand) + 3 - enemy_hand) % 3}; // 結果を計算
    std::cout << "You " << result_message.at(judge) << '\n' << std::endl; // リザルトマップで結果を表示
  }
  return 0;
}
