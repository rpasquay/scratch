#include <limits> // std::numeric_limits<>
#include "ernest.hpp"
#include "exceptions.hpp"

unsigned int scratch::app::factorial(unsigned int num) {

    if(0 == num) {
        return 1;
    }

    unsigned int result = 1;

    while(num > 0) {
        if(std::numeric_limits<unsigned int>::max() / num < result) {
            throw FooException("Number exceeds numerical limits.");
        }
        result *= num--;
    }

    return result;
}
