/**
 * Don't be confused by this file. It is a way of moving template implementations out of header-
 * files so that these header files don't appear to cluttered.
 * 
 * Since template function/class implementation cannot live in *.cpp files they usually have to go
 * into the header files where they're declared. But there is this "trick" that you put them in
 * another file and include this file *in the bottom* of the header files (check the last lines
 * of rockwell.hpp ;)).
 */

namespace scratch { namespace rockwell {

template<typename T>
Rockwell<T>::Rockwell(T value) : value_(value) {}

template<typename T>
T Rockwell<T>::get_value() const {
    return this->value_;
}

template<typename T>
std::string Rockwell<T>::name_type() const {
    return name_a_type(this->value_);
}

}}