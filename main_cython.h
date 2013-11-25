#ifndef __PYX_HAVE__main_cython
#define __PYX_HAVE__main_cython

struct MyFactory;
struct MyFactory : public AMRLevelFactory {

  /* "main_cython.pyx":49
 *         AMRLevel* new_amrlevel() const
 * 
 * cdef public cppclass MyFactory(AMRLevelFactory):             # <<<<<<<<<<<<<<
 *     MyFactory():
 *         pass
 */
   MyFactory(void);
  virtual AMRLevel *new_amrlevel(void);
};

#ifndef __PYX_HAVE_API__main_cython

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#endif /* !__PYX_HAVE_API__main_cython */

#if PY_MAJOR_VERSION < 3
PyMODINIT_FUNC initmain_cython(void);
#else
PyMODINIT_FUNC PyInit_main_cython(void);
#endif

#endif /* !__PYX_HAVE__main_cython */
