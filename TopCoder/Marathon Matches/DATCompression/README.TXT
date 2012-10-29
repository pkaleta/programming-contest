This code has been compiled and tested under MS-DOS and Windows
95 using Borland and Microsoft compilers.

The code also seems to work with g++ and cfront based compilers
under UNIX.  In order to build properly, the code must be
built with the constant 'unix' defined.  g++ does this
automatically.  If your compiler doesn't, add -Dunix to the
command line.

With some UNIX C++ compilers, you may need to change the file's
suffixes from cpp to C or cxx.

This code works under UNIX only because of the support and review
of these fine folks:

    o   Quincey Koziol
    o   Philipp Knirsch
    o   Leo Broukhis

Thanks guys!

BWTA.CPP is an alternate version of BWT.CPP that does its
sorting using the STL. This code has *not* been tested under
UNIX.

Mark Nelson
http://web2.airmail.net/markn

