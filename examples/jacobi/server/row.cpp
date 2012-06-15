
//  Copyright (c) 2012 Thomas Heller
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "row.hpp"

namespace jacobi
{
    namespace server
    {
        void row::init(std::size_t nx, double init)
        {
            values.reset(new double[nx]);
            //std::cout << this->get_gid() << "constructing row ...\n";
            // TODO: replace with hpx::for_each
            row_range range(values, 0, nx);
            BOOST_FOREACH(double & v, range)
            {
                v = init;
            }
        }
    }
}

typedef hpx::components::managed_component<
    jacobi::server::row
> row_type;

HPX_REGISTER_MINIMAL_GENERIC_COMPONENT_FACTORY(row_type, row);

HPX_REGISTER_ACTION_EX(
    jacobi::server::row::init_action
  , jacobi_server_row_init_action
)

HPX_REGISTER_ACTION_EX(
    jacobi::server::row::get_action
  , jacobi_server_row_get_action
)
