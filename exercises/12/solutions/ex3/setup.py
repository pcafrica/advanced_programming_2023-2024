# Importing necessary modules for the script
import os  # Operating system-specific functionalities.
import sys  # Provides access to some variables used or maintained by the Python interpreter.
import subprocess  # Allows you to spawn new processes, connect to their input output/error pipes, and obtain their return codes.
import shutil  # High-level file operations.

# Command to check if ninja-build is installed
command = "ninja"

# Check if ninja-build is available
if shutil.which(command) is None:
    print("Ninja-build is not installed. Installing...")
    # Command to install ninja-build
    install_command = "sudo apt-get install ninja-build"
    # Run the installation command
    subprocess.run(install_command, shell=True)
    print("Ninja-build has been installed.")
else:
    print("Ninja-build is already installed.")

from setuptools import setup, Extension  # Used for package setup and creating C extension modules.
from setuptools.command.build_ext import build_ext  # Extends the build process to compile C/C++ code.

# A CMakeExtension needs a sourcedir instead of a file list.
# The name must be the _single_ output extension from the CMake build.
# If you need multiple extensions, see scikit-build.
class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=""):
        # Call the constructor of the parent class (Extension)
        Extension.__init__(self, name, sources=[])
        # Set the source directory for the CMake extension
        self.sourcedir = os.path.abspath(sourcedir)

# Define a custom extension class CMakeExtension that inherits from Extension.
# It is used to handle CMake extensions, specifying the source directory.

class CMakeBuild(build_ext):
    # Define a custom build class CMakeBuild, inheriting from build_ext.
    # It customizes the build process for the CMake extension.

    def build_extension(self, ext):
        # Get the absolute path of the directory containing the extension
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))

        # Ensure extdir ends with the appropriate separator
        if not extdir.endswith(os.path.sep):
            extdir += os.path.sep

        # Set the configuration type based on whether it is a debug or release build
        cfg = "Debug" if self.debug else "Release"

        # Get the CMake generator from the environment or use an empty string
        cmake_generator = os.environ.get("CMAKE_GENERATOR", "")

        # Set up CMake arguments
        cmake_args = [
            "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={}".format(extdir),
            "-DPYTHON_EXECUTABLE={}".format(sys.executable),
            "-DCMAKE_BUILD_TYPE={}".format(cfg),
        ]
        build_args = []

        # Check for the availability of Ninja for faster builds
        try:
            subprocess.check_output(["ninja", "--version"])
            cmake_args += ["-GNinja"]
        except (subprocess.CalledProcessError, FileNotFoundError):
            print("Ninja not found. Falling back to default make.")

        # Handle the case when the compiler is not MSVC
        if self.compiler.compiler_type != "msvc":
            if not cmake_generator:
                cmake_args += ["-GNinja" if shutil.which("ninja") else ""]
        else:
            # Handle MSVC-specific configurations
            single_config = any(x in cmake_generator for x in {"NMake", "Ninja"})
            contains_arch = any(x in cmake_generator for x in {"ARM", "Win64"})

            if not single_config and not contains_arch:
                cmake_args += ["-A", PLAT_TO_CMAKE[self.plat_name]]

            if not single_config:
                cmake_args += [
                    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}".format(cfg.upper(), extdir)
                ]
                build_args += ["--config", cfg]

        # Set CMAKE_BUILD_PARALLEL_LEVEL to control the parallel build level
        if "CMAKE_BUILD_PARALLEL_LEVEL" not in os.environ:
            if hasattr(self, "parallel") and self.parallel:
                build_args += ["-j{}".format(self.parallel)]

        # Create the build directory if it doesn't exist
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        # Run CMake to configure the build
        subprocess.check_call(
            ["cmake", ext.sourcedir] + cmake_args, cwd=self.build_temp
        )

        # Run the build command
        subprocess.check_call(
            ["cmake", "--build", "."] + build_args, cwd=self.build_temp
        )

# Setup configuration for the package
setup(
    name="eigen_ops",
    version="0.0.1",
    description="A test project using pybind11 and CMake",
    long_description="",
    ext_modules=[CMakeExtension("eigen_ops")],
    cmdclass={"build_ext": CMakeBuild},
    zip_safe=False,
)
