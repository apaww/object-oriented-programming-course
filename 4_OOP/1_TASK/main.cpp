#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>

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

        std::cout << "First file had " << first.size() << " numbers, and the second one " << second.size() << " numbers" << std::endl;

        std::map<int, int> first_map;
        for (const int& el: first) {
                first_map[el]++;
        }

        std::vector<int> second_counter;
        for (int i = 0; i < second.size(); ++i) {
                second_counter.push_back(std::count(second.begin(), second.end(), second[i]));
        }

        std::cout << "First array with counter:" << std::endl;
        for (const int& el: first) {
                std::cout << el << " was found in first " << first_map[el] << " times" << std::endl;
        }

        std::cout << "Second aray with counter:" << std::endl;
        for (int i = 0; i < second.size(); ++i) {
                std::cout << second[i] << " was found in second " << second_counter[i] << " times" << std::endl;
        }

        int first_sum = std::accumulate(first.begin(), first.begin() + 10, 0);
        int second_sum = std::accumulate(second.begin(), second.begin() + 10, 0);

        std::cout << "First sum = " << first_sum << std::endl << "Second sum = " << second_sum << std::endl;

        return 0;
}
