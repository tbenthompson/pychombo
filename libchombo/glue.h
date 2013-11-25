#ifndef _LIBCHOMBOGLUE_H_
#define _LIBCHOMBOGLUE_H_
#define CH_SPACEDIM 2 
#define CH_Linux 1
#define CH_USE_SETVAL 1
#define CH_USE_COMPLEX 1
#define CH_USE_MEMORY_TRACKING 1
#define CH_USE_64 1
#define CH_USE_DOUBLE 1
#define CH_USE_HDF5 1
#define H5_USE_16_API 1
#define CH_FORT_UNDERSCORE 1
#define CH_LANG_CC 1
#include <Python.h>
double returnRealVal(PyObject* object, char* method);
#endif
