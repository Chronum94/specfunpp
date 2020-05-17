from setuptools import setup, Extension
from Cython.Build import cythonize
import glob as g


extension_files = g.glob("specfun/interfaces/*.pyx")
extensions = Extension("bessel", extension_files)
setup(
   name="bessel",
   ext_modules=cythonize(extensions),
   packages=["specfun"],
   py_modules=["bessel"],
   install_requires=[
        "numpy>=1.17.0",
        "mpmath>=1.0.0"
        "cython>=0.29.0",
    ],
)