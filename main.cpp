#include <assert.h>
#include <boost/bimap.hpp>
#include <iostream>

auto main() -> int
{
    std::vector<std::pair<int, std::string>> number_word_pairs = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
    };

    boost::bimap<int, std::string> number_to_word_bimap;
    for (auto &number_word_pair : number_word_pairs)
    {
        number_to_word_bimap.insert({number_word_pair.first, std::move(number_word_pair.second)});
    }

    auto findLeftIter = number_to_word_bimap.left.find(7);
    assert(findLeftIter != number_to_word_bimap.left.end());

    // This should print "seven"
    std::cout << findLeftIter->get_right() << '\n';

    auto findRightIter = number_to_word_bimap.right.find("three");
    assert(findRightIter != number_to_word_bimap.right.end());

    // This should print "3"
    std::cout << findRightIter->get_left() << '\n';

    return 0;
}