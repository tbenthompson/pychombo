#include "glue.h"
#include <Python.h>
#include <boost/python.hpp>
#include <IntVect.H>
#include <Box.H>
#include <ProblemDomain.H>
#include <PhysIBC.H>
using namespace boost::python;

BOOST_PYTHON_MODULE(libpychombo)
{
    class_<IntVect>("IntVect", init<D_DECL6(const int, const int, const int, 
                const int, const int, const int)>())
        .add_static_property("Zero", make_getter(&IntVect::Zero, 
                    return_value_policy<reference_existing_object>()));

    class_<Box>("Box", init<IntVect, IntVect>())
        .def("smallEnd", (const IntVect& (Box::*)(void) const)&Box::smallEnd,
                return_internal_reference<>())
        .def("bigEnd", (const IntVect& (Box::*)(void) const)&Box::bigEnd,
                return_internal_reference<>());

    class_<ProblemDomain>("ProblemDomain", init<const IntVect&, const IntVect&>());
    class_<PhysIBC, boost::noncopyable>("PhysIBC", no_init)
        .def("new_physIBC", pure_virtual(&PhysIBC::new_physIBC),
                return_value_policy<manage_new_object>())
        .def("initialize", pure_virtual(&PhysIBC::initialize))
        .def("primBC", pure_virtual(&PhysIBC::primBC))
        .def("setBdrySlopes", pure_virtual(&PhysIBC::setBdrySlopes))
        .def("artViscBC", pure_virtual(&PhysIBC::artViscBC))
        .def("getBoundaryFaces", pure_virtual(&PhysIBC::getBoundaryFaces));
}
