#ifdef CH_LANG_CC
/*
 *      _______              __
 *     / ___/ /  ___  __ _  / /  ___
 *    / /__/ _ \/ _ \/  V \/ _ \/ _ \
 *    \___/_//_/\___/_/_/_/_.__/\___/
 *    Please refer to Copyright.txt, in Chombo's root directory.
 */
#endif

#ifndef _AMRLEVELADVECTDIFFUSE_H_
#define _AMRLEVELADVECTDIFFUSE_H_

#include "glue.h"
#include <Python.h>
#include <MayDay.H>
#include <FArrayBox.H>
#include <Box.H>
#include <ProblemDomain.H>
#include <AMRLevel.H>

#include <NamespaceHeader.H>

/// AMRLevel for advection-diffusion
/**
*/
class AMRLevelGlue : public AMRLevel
{
    public:
        PyObject* m_callback;

        /// Default constructor
        AMRLevelGlue()
        {
            MayDay::Error("Empty constructor is not acceptable for \
                    glue classes. You must provide a python object.");
        }


        AMRLevelGlue(PyObject* a_callback);

        virtual ~AMRLevelGlue();

        virtual void define(AMRLevel* a_coarserLevelPtr,
                const Box& a_problemDomain,
                int        a_level,
                int        a_refRatio)
        {
            MayDay::Error("never called--historical");
        }

        virtual void define(
                AMRLevel*            a_coarserLevelPtr,
                const ProblemDomain& a_problemDomain,
                int                  a_level,
                int                  a_refRatio);

        /// Advance by one timestep
        virtual Real advance();

        /// Things to do after a timestep
        virtual void postTimeStep();

        /// Create tags for regridding
        virtual void tagCells(IntVectSet& a_tags) ;

        /// Create tags at initialization
        virtual void tagCellsInit(IntVectSet& a_tags) ;

        /// Set up data on this level after regridding
        virtual void regrid(const Vector<Box>& a_newGrids);

        /// Initialize grids
        virtual void initialGrid(const Vector<Box>& a_newGrids);

        /// Initialize data
        virtual void initialData();

        /// Things to do after initialization
        virtual void postInitialize();

#ifdef CH_USE_HDF5
        /// Write checkpoint header
        virtual void writeCheckpointHeader(HDF5Handle& a_handle) const;

        /// Write checkpoint data for this level
        virtual void writeCheckpointLevel(HDF5Handle& a_handle) const;

        /// Read checkpoint header
        virtual void readCheckpointHeader(HDF5Handle& a_handle);

        /// Read checkpoint data for this level
        virtual void readCheckpointLevel(HDF5Handle& a_handle);

        /// Write plotfile header
        virtual void writePlotHeader(HDF5Handle& a_handle) const;

        /// Write plotfile data for this level
        virtual void writePlotLevel(HDF5Handle& a_handle) const;
#endif

        /// Returns the dt computed earlier for this level
        virtual Real computeDt();

        /// Compute dt using initial data
        virtual Real computeInitialDt();
};

#include "NamespaceFooter.H"

#endif
