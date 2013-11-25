#ifdef CH_LANG_CC
/*
 *      _______              __
 *     / ___/ /  ___  __ _  / /  ___
 *    / /__/ _ \/ _ \/  V \/ _ \/ _ \
 *    \___/_//_/\___/_/_/_/_.__/\___/
 *    Please refer to Copyright.txt, in Chombo's root directory.
 */
#endif
#include "AMRLevelGlue.h"
#include <NamespaceHeader.H>
AMRLevelGlue::AMRLevelGlue(PyObject* a_callback)
{
    Py_INCREF(a_callback);
    this->m_callback = a_callback; 
}

AMRLevelGlue::~AMRLevelGlue()
{
    Py_DECREF(this->m_callback);
}
void AMRLevelGlue::define(AMRLevel* a_coarserLevelPtr,
                                   const ProblemDomain& a_problemDomain,
                                   int                  a_level,
                                   int                  a_refRatio)
{
    PyObject_CallMethod(this->m_callback, "define", a_coarserLevelPtr,
            a_problemDomain, a_level, a_refRatio);
}

Real
AMRLevelGlue::
advance()
{
    return returnRealVal(this->m_callback, "advance");
}

void
AMRLevelGlue::
postTimeStep()
{
    PyObject_CallMethod(this->m_callback, "postTimeStep");
}

void
AMRLevelGlue::
tagCells(IntVectSet& a_tags)
{
    PyObject_CallMethod(this->m_callback, "postTimeStep", a_tags);
}

void
AMRLevelGlue::
tagCellsInit(IntVectSet& a_tags)
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_tags);
}

void
AMRLevelGlue::
regrid(const Vector<Box>& a_newGrids)
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_newGrids);
}

void
AMRLevelGlue::
initialGrid(const Vector<Box>& a_newGrids)
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_newGrids);
}

void
AMRLevelGlue::
initialData()
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", NULL);
}

void
AMRLevelGlue::
postInitialize()
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", NULL);
}

#ifdef CH_USE_HDF5
void
AMRLevelGlue::
writeCheckpointHeader(HDF5Handle& a_handle) const
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_handle);
}


void
AMRLevelGlue::
writeCheckpointLevel(HDF5Handle& a_handle) const
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_handle);
}


void
AMRLevelGlue::
readCheckpointHeader(HDF5Handle& a_handle)
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_handle);
}


void
AMRLevelGlue::
readCheckpointLevel(HDF5Handle& a_handle)
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_handle);
}


void
AMRLevelGlue::
writePlotHeader(HDF5Handle& a_handle) const
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_handle);
}


void
AMRLevelGlue::
writePlotLevel(HDF5Handle& a_handle) const
{
    PyObject_CallMethod(this->m_callback, "tagCellsInit", a_handle);
}
#endif


Real
AMRLevelGlue::
computeDt()
{
    return returnRealVal(this->m_callback, "computeDt");
}


Real
AMRLevelGlue::
computeInitialDt()
{
    return returnRealVal(this->m_callback, "computeInitialDt");
}

#include "NamespaceFooter.H"
