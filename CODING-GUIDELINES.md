# Coding guidelines #

This document defines some simple guidelines for the project. Currently this
is just a document with suggestions. So editing is open for all. Just inform
the group if you have some good ideas about how the code should be structured.

## Writing output to terminal ##

We use the C++ iostream library for this. Try to avoid "using namespace std;"
because this can overload functions such as sort() which might be implemented
in certain classes. Rather, write code with std::cout and std::endl or insert
"using namespace std;" locally in functions where you use std a lot.

## Including headers ##

Class header first. Local second. Shared last. This is to avoid unnoticed
dependencies that are solved only because the compiler runs in a certain order.

#include "myheader.h"
#include "otherclass.h"
#include <somelib.h>
