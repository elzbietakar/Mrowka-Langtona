#ifndef _READ_WRITE_H
#define _READ_WRITE_H

#include "board.h"

Board readFromFile (FILE *in);

void writeToFile (FILE *out, Board *B);

#endif
