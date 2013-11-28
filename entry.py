from libpychombo import IntVect, Box, ProblemDomain, PhysIBC

class TestIBC(PhysIBC):
    def __init__(self):
        pass
    def new_physIBC(self):
        pass
    def initialize(self):
        pass
    def primBC(self):
        pass
    def setBdrySlopes(self):
        pass
    def getBoundaryFaces(self):
        pass
if __name__ == "__main__":
    list = IntVect(100,100)
    print IntVect.Zero
    box = Box(IntVect.Zero, list)
    prob_domain = ProblemDomain(box.smallEnd(), box.bigEnd())
    ibc = TestIBC()
