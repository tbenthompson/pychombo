from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

here = '/home/tbent/packages/pychombo'
chombo_dir = '/home/tbent/packages/Chombo-3.1/lib'
extensions = [
        Extension("main_cython",
                  ["main_cython.pyx"],
                  libraries=['chombo'],
                  library_dirs=[here],
                  include_dirs=[here + '/libchombo',
                                chombo_dir + '/include',
                                '/usr/include/openmpi'],
                  # WARNING: THIS TURNS OFF WARNINGS
                  # DID I JUST TYPE A METAWARNING?!
                  extra_compile_args=['-w'])
]

setup(
    name="pychombo",
    ext_modules = cythonize(extensions),
)
