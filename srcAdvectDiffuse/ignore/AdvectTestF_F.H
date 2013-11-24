#ifndef _ADVECTTESTF_F_H_
#define _ADVECTTESTF_F_H_

#include "FORT_PROTO.H"
#include "CH_Timer.H"
#include "REAL.H"

extern "C"
{

#ifndef GUARDADVECTINITF 
#define GUARDADVECTINITF 
// Prototype for Fortran procedure advectinitf ...
//
void FORTRAN_NAME( ADVECTINITF ,advectinitf )(
      CHFp_FRA1(u)
      ,CHFp_CONST_REALVECT(center)
      ,CHFp_CONST_REAL(size)
      ,CHFp_CONST_REAL(dx)
      ,CHFp_BOX(box) );

#define FORT_ADVECTINITF FORTRAN_NAME( inlineADVECTINITF, inlineADVECTINITF)
#define FORTNT_ADVECTINITF FORTRAN_NAME( ADVECTINITF, advectinitf)

inline void FORTRAN_NAME(inlineADVECTINITF, inlineADVECTINITF)(
      CHFp_FRA1(u)
      ,CHFp_CONST_REALVECT(center)
      ,CHFp_CONST_REAL(size)
      ,CHFp_CONST_REAL(dx)
      ,CHFp_BOX(box) )
{
 CH_TIMELEAF("FORT_ADVECTINITF");
 FORTRAN_NAME( ADVECTINITF ,advectinitf )(
      CHFt_FRA1(u)
      ,CHFt_CONST_REALVECT(center)
      ,CHFt_CONST_REAL(size)
      ,CHFt_CONST_REAL(dx)
      ,CHFt_BOX(box) );
}
#endif  // GUARDADVECTINITF 

}

#endif
