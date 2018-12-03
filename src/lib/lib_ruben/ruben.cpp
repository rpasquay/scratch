#include <sstream>
#include "scratch/lib_ruben/ruben.hpp"
#include "scratch/lib_ruben/exceptions.hpp"

scratch::ruben::Ruben::Ruben() : rubens_secret(42) {}

unsigned int scratch::ruben::Ruben::get_secrect() const {
    return rubens_secret;
}

void scratch::ruben::Ruben::set_secrect(const unsigned int secret) {
    rubens_secret = secret;
}

void scratch::ruben::Ruben::throw_secrect() const {
    std::stringstream msg;
    msg << "My secret number is " << rubens_secret << "." << std::endl;
    throw SecretException(msg.str().c_str());
}
