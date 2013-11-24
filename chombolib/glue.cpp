// These will need to be edited for other compilations of Chombo
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
#include <AMR.H>
#include <stdio.h>


void filler()
{
    cout << "The chombolib file is just a filler so that I can link all the \
        chombo static libs into one big dynamic library and attach from \
        python.\n";
}
