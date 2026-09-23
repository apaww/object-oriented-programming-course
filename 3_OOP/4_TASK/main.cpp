#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <random>
#include <ctime>
#include <iterator>
#include <fstream>

#include "Add.hpp"

int main() {
	std::srand(std::time(0));
  std::uniform_real_distribution<double> unif(-200, 200);
  std::default_random_engine re;

  std::array<double, 10> arr1;
  std::vector<double> vec1;
  std::list<double> li1;
  std::deque<double> deq1;

  for (int i = 0; i < 10; ++i) {
    arr1[i] = unif(re);
    vec1.push_back(unif(re));
    li1.push_back(unif(re));
    deq1.push_back(unif(re));
  }

  std::array<double, 10> arr = arr1;
  std::vector<double> vec = vec1;
  std::list<double> li = li1;
  std::deque<double> deq = deq1;

  std::array<int, 10> arr2;
  std::vector<int> vec2;
  std::list<int> li2;
  std::deque<int> deq2;
  deq2.resize(10);

  double arg = unif(re);

  for (int i = 0; i < 10; ++i) {
      vec2.push_back(modded::add<int, double>(arr1[i], arg));
      arr2[i] = modded::add<int, double>(vec1.back(), arg);
      vec1.pop_back();
  }

  std::list<double>::iterator iter1 = li1.begin();
  for (std::deque<int>::iterator iter2 = deq2.begin();
       (iter1 != li1.end()) && (iter2 != deq2.end()); ++iter1, ++iter2) {
      *iter2 = modded::add<int, double>(*iter1, arg);
  }

  for (const double& el1 : deq1) {
      li2.push_back(modded::add<int, double>(el1, arg));
  }

  std::vector<std::string> output;

  output.push_back("| arr1 | arr2 | vec1 | vec2 | li1 | li2 | deq1 | deq2 |");
  output.push_back("| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |");

  for (int i = 0; i < 10; ++i) {
      output.push_back("| " + std::to_string(arr1[i]) + " | " + std::to_string(arr2[i]) +
                       " | " + std::to_string(vec.back()) + " | " + std::to_string(vec2.back()) +
                       " | " + std::to_string(li.back()) + " | " + std::to_string(li2.back()) +
                       " | " + std::to_string(deq.back()) + " | " + std::to_string(deq2.back()) + " |");

      vec.pop_back();
      vec2.pop_back();
      li.pop_back();
      li2.pop_back();
      deq.pop_back();
      deq2.pop_back();
  }

  std::ofstream out;
  out.open("result.md");

  for (std::size_t i = 0; i < output.size(); ++i) {
    out << output[i] << std::endl;
  }

  out.close();

  return 0;
}
