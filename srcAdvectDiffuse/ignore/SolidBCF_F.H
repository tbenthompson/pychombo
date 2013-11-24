#ifndef _SOLIDBCF_F_H_
#define _SOLIDBCF_F_H_

#include "FORT_PROTO.H"
#include "CH_Timer.H"
#include "REAL.H"

extern "C"
{

#ifndef GUARDSOLIDBCF 
#define GUARDSOLIDBCF 
// Prototype for Fortran procedure solidbcf ...
//
void FORTRAN_NAME( SOLIDBCF ,solidbcf )(
      CHFp_FRA(Wgdnv)
      ,CHFp_CONST_FRA(Wextrap)
      ,CHFp_CONST_FRA(W)
      ,CHFp_CONST_INT(lohisign)
      ,CHFp_CONST_INT(dir)
      ,CHFp_BOX(box) );

#define FORT_SOLIDBCF FORTRAN_NAME( inlineSOLIDBCF, inlineSOLIDBCF)
#define FORTNT_SOLIDBCF FORTRAN_NAME( SOLIDBCF, solidbcf)

inline void FORTRAN_NAME(inlineSOLIDBCF, inlineSOLIDBCF)(
      CHFp_FRA(Wgdnv)
      ,CHFp_CONST_FRA(Wextrap)
      ,CHFp_CONST_FRA(W)
      ,CHFp_CONST_INT(lohisign)
      ,CHFp_CONST_INT(dir)
      ,CHFp_BOX(box) )
{
 CH_TIMELEAF("FORT_SOLIDBCF");
 FORTRAN_NAME( SOLIDBCF ,solidbcf )(
      CHFt_FRA(Wgdnv)
      ,CHFt_CONST_FRA(Wextrap)
      ,CHFt_CONST_FRA(W)
      ,CHFt_CONST_INT(lohisign)
      ,CHFt_CONST_INT(dir)
      ,CHFt_BOX(box) );
}
#endif  // GUARDSOLIDBCF 

}

#endif
