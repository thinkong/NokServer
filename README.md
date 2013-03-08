NokServer
=========

Installation

1. Get boost installed properly with the boost_root properly done so cmake can find it
   a. on windows compile boost with this
   		b2 toolset=msvc-10.0 --with-thread address-model=64 variant=debug link=static runtime-link=static runtime-debugging=on stage
   		* replace msvc-10.0 with whatever your toolset is
2. Get cmake.
3. run cmake to create files
4. build

