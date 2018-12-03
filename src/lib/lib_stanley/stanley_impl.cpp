#include "stanley_impl.hpp"
#include <iostream>

// StanleysContainerImpl

const unsigned int scratch::stanley::StanleysContainerImpl::secret = 42;

scratch::stanley::StanleysContainerImpl::StanleysContainerImpl(
    const std::string& message) : message(message) {}

void scratch::stanley::StanleysContainerImpl::print_message() const {
    std::cout << message << std::endl;
}

unsigned int scratch::stanley::StanleysContainerImpl::get_secret() const{
    return secret;
}

// StanleyImpl

scratch::stanley::StanleysContainer* 
scratch::stanley::StanleyImpl::get_container() const {
    
    return new StanleysContainerImpl("Hello World, says Stanley.");

}