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
      subroutine SOLIDBCF(
     & Wgdnv
     & ,iWgdnvlo0,iWgdnvlo1
     & ,iWgdnvhi0,iWgdnvhi1
     & ,nWgdnvcomp
     & ,Wextrap
     & ,iWextraplo0,iWextraplo1
     & ,iWextraphi0,iWextraphi1
     & ,nWextrapcomp
     & ,W
     & ,iWlo0,iWlo1
     & ,iWhi0,iWhi1
     & ,nWcomp
     & ,lohisign
     & ,dir
     & ,iboxlo0,iboxlo1
     & ,iboxhi0,iboxhi1
     & )
      implicit none
      integer nWgdnvcomp
      integer iWgdnvlo0,iWgdnvlo1
      integer iWgdnvhi0,iWgdnvhi1
      REAL*8 Wgdnv(
     & iWgdnvlo0:iWgdnvhi0,
     & iWgdnvlo1:iWgdnvhi1,
     & 0:nWgdnvcomp-1)
      integer nWextrapcomp
      integer iWextraplo0,iWextraplo1
      integer iWextraphi0,iWextraphi1
      REAL*8 Wextrap(
     & iWextraplo0:iWextraphi0,
     & iWextraplo1:iWextraphi1,
     & 0:nWextrapcomp-1)
      integer nWcomp
      integer iWlo0,iWlo1
      integer iWhi0,iWhi1
      REAL*8 W(
     & iWlo0:iWhi0,
     & iWlo1:iWhi1,
     & 0:nWcomp-1)
      integer lohisign
      integer dir
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      REAL*8 s
      integer i0,i1
      do i1 = iboxlo1,iboxhi1
      do i0 = iboxlo0,iboxhi0
         Wgdnv(i0,i1, 0) = Wextrap(i0,i1, 0)
      enddo
      enddo
      return
      end
