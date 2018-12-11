/**
 * \file stanley_impl.hpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Private header of dynamic class "Stanley".
 * \version 1.0
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 * \ingroup lib_stanley
 * \addtogroup lib_stanley
 * @{
 */

#ifndef SCRATCH_INCLUDE_GUARD__LIB_STANLEY_STANLEY_IMPL_HPP
#define SCRATCH_INCLUDE_GUARD__LIB_STANLEY_STANLEY_IMPL_HPP

#include <string> // std::string
#include "scratch/lib_stanley/stanley.hpp"

namespace scratch { namespace stanley {

/**
 * \brief Class implementing interface StanleysContainer.
 */
class StanleysContainerImpl : public StanleysContainer {

public:

    /**
     * \brief Construct a new StanleysContainerImpl object.
     * 
     * \param message
     *  Message.
     */
    StanleysContainerImpl(const std::string& message);

    StanleysContainerImpl(const StanleysContainerImpl& other) = default;

    StanleysContainerImpl(StanleysContainerImpl&& other) = default;

    StanleysContainerImpl& operator=(const StanleysContainerImpl& other) = default;

    StanleysContainerImpl& operator=(StanleysContainerImpl&& other) = default;

    ~StanleysContainerImpl() = default;

    void print_message() const override;

    unsigned int get_secret() const override;

private:

    std::string message; /**< Message Stanley has for the world. */
    static const unsigned int secret; /**< Secret number of Stanley. */

};

/**
 * \brief Class implementing interface Stanley.
 */
class StanleyImpl : public Stanley {

public:

    StanleysContainer* get_container() const override;

};

}}

/** @} */

#endif // SCRATCH_INCLUDE_GUARD__LIB_STANLEY_STANLEY_IMPL_HPP
