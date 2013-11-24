#include "REAL.H"
#include "SPACE.H"
#include "CONSTANTS.H"

#include "CONSTANTS.H"
      subroutine ADVECTINITF(
     &           u
     &           ,iulo0,iulo1
     &           ,iuhi0,iuhi1
     &           ,center
     &           ,size
     &           ,dx
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      integer iulo0,iulo1
      integer iuhi0,iuhi1
      REAL_T u(
     &           iulo0:iuhi0,
     &           iulo1:iuhi1)
      REAL_T center(0:1)
      REAL_T size
      REAL_T dx
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      real_t x,y
      real_t radsqr, rad, val, normrad
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

         
         x = (i + half)*dx
         y = (j + half)*dx
         radsqr = 
     $        (x - center(0))**2 +
     $        (y - center(1))**2
         rad = sqrt(radsqr)
         normrad = sin(half*Pi*rad/size)
         if (rad.lt.size) then
            val = (one-(normrad*normrad*normrad))
         else
            val = zero
         endif
         u(i,j) = val
      
      enddo
      enddo
      return
      end
