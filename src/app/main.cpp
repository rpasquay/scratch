/**
 * \file main.cpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Main file of executable "app".
 * \version 1.0
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 * 
 * \ingroup app
 * \addtogroup app
 * @{
 */


#include <iostream> // std::cout, etc.
#include <memory> // std::unique_ptr
#include "ernest.hpp"
#include "linwood.hpp"
#include "exceptions.hpp"
#include "scratch/lib_ruben/ruben.hpp"
#include "scratch/lib_ruben/exceptions.hpp"
#include "scratch/lib_stanley/stanley.hpp"
#include "scratch/lib_rockwell/rockwell.hpp"

/**
 * \brief Main entry point to this small template app.
 * 
 * \param argc
 *  Number of arguments passed. 
 * \param argv
 *  Pointer to array of pointers pointing at strings representing arguments.
 * \returns int
 *  Applications return code.
 */
int main(int argc, char** argv) {

    // Static library "Ruben"

    scratch::ruben::Ruben ruben;
    ruben.set_secrect(36);

    std::cout << "Ruben's secret is " << ruben.get_secrect() << std::endl;

    try{
        ruben.throw_secrect();
    } catch(const scratch::ruben::RubenException& e) {
        std::cout << "He can also throw it: " << e.what() << std::endl;
    }

    // Shared library "Stanley"

    std::unique_ptr<scratch::stanley::Stanley> stanley(scratch::stanley::create_stanley());
    std::unique_ptr<scratch::stanley::StanleysContainer> container(stanley->get_container());

    std::cout << "Stanley's secret is " << container->get_secret() << std::endl;
    std::cout << "He also has a message: ";
    container->print_message();

    // Header-only library "Rockwell"

    scratch::rockwell::Rockwell<int> rockwell(123);
    std::cout << "Rockwell knows the numer " << rockwell.get_value() << "and can name his type: "
        << rockwell.name_type() << "!" << std::endl;

    // "Ernest"

    try {
        std::cout << "Ernest says, 5! is " << scratch::app::factorial(5) << std::endl;
        std::cout << "And 42! is ... " << scratch::app::factorial(42) << std::endl;
    } catch (const scratch::app::FooException& e) {
        std::cout << e.what() << std::endl;
    }

    // "Linwood"
    
    try {
        std::cout << "Linwood knows about primes." << std::endl;
        std::cout << "Is 17 prime ? "
            << ( scratch::app::is_prime(17) ? "Yes!" : "No!" ) << std::endl;
        std::cout << "He's lazy though... prime(1234) causes an exception: "
            << ( scratch::app::is_prime(1234) ? "Yes!" : "No!" ) << std::endl;
    } catch(const scratch::app::FooException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

/** @} */
