SimD (Simple Dds) is an API that makes it much simpler to program DDS in C++. This API is also being considered for standardization at the OMG (http://www.omg.org) and in any case is influencing the way in which the upcoming C++ API for DDS will look like.

The current release of SimD works off the shelf with OpenSplice DDS (http://www.opensplice.org), this version was chosen because it is a full implementation of the OMG DDS Standard and in addition it is Open Source.

# Getting Started #
SimD is  available for Linux and Windows Operating Systems. A tutorial on how to get started with DDS and SimD is available at http://bit.ly/dhQCDb

## Downloading SimD ##
The latest SimD distribution can be downloaded at http://code.google.com/p/simd-cxx/downloads/list

## Building SimD ##
To install the SimD source distribution you'll need to ensure that BOOST (see  www.boost.org) is properly installed in your machine and that two environment variable are pointing to the include and libraries directory for BOOST. Namely:

BOOST\_INCLUDE\_DIR: points at the include directory
BOOST\_LIB\_DIR: points at the library directory

Once BOOST is properly installed and configured, simply do the following:

$ mkdir build

$ cd build

$ cmake ..

$ make; make install


