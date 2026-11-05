#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <iterator>

int main() {
        std::ifstream in;
        in.open("s04_v1_42_1.txt");

        std::vector<int> first;
        std::string line {};
        while (std::getline(in, line)) {
                std::istringstream iss_line(line);
                std::string snum {};

                while (std::getline(iss_line, snum, ',')) {
                        std::istringstream iss_num(snum);
                        std::string num{};

                        while (std::getline(iss_num, num, ' ')) {
                                try {
                                        first.push_back(std::stoi(num));
                                } catch (...) {}
                        }
                }
        }

        in.close();
        in.open("s04_v1_42_2.txt");

        std::vector<int> second;
        while (std::getline(in, line)) {
                std::istringstream iss_line(line);
                std::string snum {};

                while (std::getline(iss_line, snum, ',')) {
                        std::istringstream iss_num(snum);
                        std::string num{};

                        while (std::getline(iss_num, num, ' ')) {
                                try {
                                        second.push_back(std::stoi(num));
                                } catch (...) {}
                        }
                }
        }

        in.close();

        std::cout << "First file had " << first.size() <<
                  " numbers, and the second one " << second.size() <<
                  " numbers" << std::endl;

        std::map<int, int> first_map;
        for (const int& el: first) {
                first_map[el]++;
        }

        std::vector<int> second_counter;
        for (int i = 0; i < second.size(); ++i) {
                second_counter.push_back(std::count(second.begin(), second.end(), second[i]));
        }

        int first_bin = std::accumulate(first.begin(), first.end(), 0,
                [](int current_sum, const int& num) {
                  return (num % 2) ? (-num) : (num);
        });
        int second_bin = std::accumulate(second.begin(), second.end(), 0,
                [](int current_sum, const int& num) {
                  return (num % 2) ? (-num) : (num);
        });

        std::cout << "First binary op = " << first_bin << std::endl <<
                      "Second binary op = " << second_bin << std::endl;

        std::vector<int> first_popular;
        std::copy_if(first.begin(), first.end(), std::back_inserter(first_popular),
                [first_map](int num) {
                  return first_map.at(num) > 3;
        });

        std::vector<int> second_popular;
        int idx = 0;
        std::copy_if(second.begin(), second.end(), std::back_inserter(second_popular),
                [second_counter, &idx](int num) {
                  return second_counter[idx++] > 1;
        });

        std::cout << "Using FOR loop to return numerbs that are in second vector" <<
                      "> 1 times and > 3 times in first one." << std::endl;
        for (const int& el: second_popular) {
                std::cout << "Number " << el << " is in second vector " <<
                          second_counter[std::find(second.begin(), second.end(), el) - second.begin()]
                          << " times, and " << first_map[el] << " in first." << std::endl;
        }

        std::cout << std::endl << "Using ALGORITHM to return numerbs that are in second vector" <<
                      "> 1 times and > 3 times in first one." << std::endl;
        std::for_each(second_popular.begin(), second_popular.end(),
                [first_popular, first_map, second_counter, second](int num) {
                  std::cout << "Number " << num << " is in second vector " <<
                            second_counter[std::find(second.begin(), second.end(), num) - second.begin()]
                            << " times, and " << first_map.at(num) << " in first." << std::endl;
        });

        return 0;
}
