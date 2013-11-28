// These will need to be edited for other compilations of Chombo
#include "glue.h"
#include <stdio.h>
#include <Python.h>

double returnRealVal(PyObject* object, char* method)
{
    PyObject *pyresult = PyObject_CallMethod(object, method, NULL);
    if (pyresult == NULL) return -1;
    double cppresult = PyFloat_AsDouble(pyresult);
    Py_DECREF(pyresult);
    if (PyErr_Occurred()) return -1;
    return cppresult;
}
