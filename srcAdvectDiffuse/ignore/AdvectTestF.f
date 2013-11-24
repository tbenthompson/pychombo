/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* Define __STDC_IEC_559__ and other similar macros.  */
/* Copyright (C) 2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
      subroutine ADVECTINITF(
     & u
     & ,iulo0,iulo1
     & ,iuhi0,iuhi1
     & ,center
     & ,size
     & ,dx
     & ,iboxlo0,iboxlo1
     & ,iboxhi0,iboxhi1
     & )
      implicit none
      integer iulo0,iulo1
      integer iuhi0,iuhi1
      REAL*8 u(
     & iulo0:iuhi0,
     & iulo1:iuhi1)
      REAL*8 center(0:1)
      REAL*8 size
      REAL*8 dx
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      REAL*8 x,y
      REAL*8 radsqr, rad, val, normrad
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0
         x = (i + (0.500d0))*dx
         y = (j + (0.500d0))*dx
         radsqr =
     $ (x - center(0))**2 +
     $ (y - center(1))**2
         rad = sqrt(radsqr)
         normrad = sin((0.500d0)*(3.14159265358979323846264338327950288d
     &0)*rad/size)
         if (rad.lt.size) then
            val = ((1.0d0)-(normrad*normrad*normrad))
         else
            val = (0.0d0)
         endif
         u(i,j) = val
      enddo
      enddo
      return
      end
