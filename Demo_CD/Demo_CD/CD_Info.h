#pragma once
#include "CD.h"

// Read a CSV file of CD info and create the corresponding CDs
// at location specified by the caller.  
// Return count of CDs created.
int get_CDs(CD** cds, int max);