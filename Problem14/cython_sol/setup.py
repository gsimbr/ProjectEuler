from distutils.core import setup
from Cython.Build import cythonize

requires = [
    'Cython',
    'numpy',
    ]


setup(
    name='libprob14',
    requires=requires,
    ext_modules=cythonize(
        "libprob14/*.pyx"),
    package_data={
        'libprob14': ['*.pxd']}
)