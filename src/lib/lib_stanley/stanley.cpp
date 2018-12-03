#include "scratch/lib_stanley/stanley.hpp"
#include "stanley_impl.hpp"

extern "C" scratch::stanley::Stanley* scratch::stanley::create_stanley() {
    return new StanleyImpl;
}
