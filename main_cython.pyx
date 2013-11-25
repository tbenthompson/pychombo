# distutils: language = c++
# cython: experimental_cpp_class_def=True
from cython.operator cimport dereference as deref
from libcpp cimport bool
from libcpp.vector cimport vector

cdef extern from "glue.h":
    pass

cdef extern from "REAL.H":
    ctypedef double Real

cdef extern from "IntVect.H":
    cdef cppclass IntVect:
        IntVect(int, int) except +
    cdef const IntVect IntVectZero "IntVect::Zero"

cdef extern from "IntVectSet.H":
    cdef cppclass IntVectSet:
        IntVectSet()

cdef extern from "Box.H":
    cdef cppclass Box:
        Box(IntVect&, IntVect&) except +
        const IntVect& smallEnd()
        const IntVect& bigEnd()

cdef extern from "ProblemDomain.H":
    cdef cppclass ProblemDomain:
        ProblemDomain(IntVect&, IntVect&, const bool*)

cdef extern from "AMRLevel.H":
    cdef cppclass AMRLevel:
        AMRLevel()
        define(AMRLevel*, const Box&, int, int)
        define(AMRLevel*, const ProblemDomain&, int, int)
        advance()
        postTimeStep()
        tagCells(IntVectSet&)
        tagCellsInit(IntVectSet&)
        preRegrid(int, const vector[vector[Box]]&)

cdef public cppclass MyFactory(AMRLevelFactory):
    MyFactory():
        pass
    AMRLevel* new_amrlevel():
        print "Hi"
        return NULL

cdef extern from "AMR.H":
    cdef cppclass AMR:
        define(int, vector[int]&, const ProblemDomain&,
               const AMRLevelFactory*)
        setupForNewAMRRun()
        run(double, int)

def run(params):
    cdef IntVect* list = new IntVect(100,100)
    cdef Box* box = new Box(IntVectZero, deref(list))
    cdef bool periodic = True
    cdef ProblemDomain* prob_domain = \
        new ProblemDomain(box.smallEnd(), box.bigEnd(), &periodic)
    cdef AMRLevelFactory* my_factory = new MyFactory()
    my_factory.new_amrlevel()
    del list, box, prob_domain
