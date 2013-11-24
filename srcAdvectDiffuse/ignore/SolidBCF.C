#include "REAL.H"
#include "SPACE.H"
#include "CONSTANTS.H"

#include "CONSTANTS.H"
      subroutine SOLIDBCF(
     &           Wgdnv
     &           ,iWgdnvlo0,iWgdnvlo1
     &           ,iWgdnvhi0,iWgdnvhi1
     &           ,nWgdnvcomp
     &           ,Wextrap
     &           ,iWextraplo0,iWextraplo1
     &           ,iWextraphi0,iWextraphi1
     &           ,nWextrapcomp
     &           ,W
     &           ,iWlo0,iWlo1
     &           ,iWhi0,iWhi1
     &           ,nWcomp
     &           ,lohisign
     &           ,dir
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      integer nWgdnvcomp
      integer iWgdnvlo0,iWgdnvlo1
      integer iWgdnvhi0,iWgdnvhi1
      REAL_T Wgdnv(
     &           iWgdnvlo0:iWgdnvhi0,
     &           iWgdnvlo1:iWgdnvhi1,
     &           0:nWgdnvcomp-1)
      integer nWextrapcomp
      integer iWextraplo0,iWextraplo1
      integer iWextraphi0,iWextraphi1
      REAL_T Wextrap(
     &           iWextraplo0:iWextraphi0,
     &           iWextraplo1:iWextraphi1,
     &           0:nWextrapcomp-1)
      integer nWcomp
      integer iWlo0,iWlo1
      integer iWhi0,iWhi1
      REAL_T W(
     &           iWlo0:iWhi0,
     &           iWlo1:iWhi1,
     &           0:nWcomp-1)
      integer lohisign
      integer dir
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      real_t s
      integer i0,i1
      
      do i1 = iboxlo1,iboxhi1
      do i0 = iboxlo0,iboxhi0

         Wgdnv(i0,i1, 0) = Wextrap(i0,i1, 0)
      
      enddo
      enddo
      return
      end
