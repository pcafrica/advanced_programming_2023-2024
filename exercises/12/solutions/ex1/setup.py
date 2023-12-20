from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "data_processor",
        ["data_processor.cpp"]
    ),
]

setup(
    name="data_processor",
    version="1.0",
    author="Pasquale Claudio Africa",
    author_email="pafrica@sissa.it",
    description="A simple data processor module using C++ and pybind11",
    long_description="",
    ext_modules=ext_modules,
    install_requires=["pybind11>=2.5.0"],
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
