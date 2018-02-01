#pragma once
#include <string>
#include "CD.h"

// Read track info from specified CSV file.
// Create a Track object and add it to the CD
// specified by the first parameter.
void get_tracks(CD& cd, string& track_file_name);
