# distutils: language = c++


cdef extern from "AMR.H" namespace "Chombo":
    pass
cdef extern from "ProblemDomain.H" namespace "Chombo":
    pass

cdef extern from "UsingNamespace.H":
    pass

# I think this avoids some Cython error? WEIRD!
abc = 123


def run(params):
    pass
