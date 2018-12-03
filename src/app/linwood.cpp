#include "linwood.hpp"
#include "exceptions.hpp"

bool scratch::app::is_prime(unsigned int number) {

    bool is_prime = true;

    if(2 > number) {
        is_prime = false;
    }
    else if(100 > number) {
        for(unsigned int i = 2; i < number; ++i) {
            if(0 == number % i) {
                is_prime = false;
                break;
            }
        }
    }
    else {
        throw FooException("Entered number might be prime. Might not be prime. It's too big");
    }

    return is_prime;
}
