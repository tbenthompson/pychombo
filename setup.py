from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

chombo_dir = '/home/tbent/packages/Chombo-3.1/lib'
extensions = [
        Extension("main_cython",
                  ["main_cython.pyx"],
                  libraries=['chombo'],
                  library_dirs=['/home/tbent/packages/pychombo/chombolib'],
                  include_dirs=[chombo_dir + '/include'])
]

setup(
    name="mc",
    ext_modules = cythonize(extensions),
)
