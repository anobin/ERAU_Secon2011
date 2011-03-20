/** Contains utility functions and global defines
 *
 * @file Utils.h
 */
#ifndef UTILS_H
#define UTILS_H

// always needed..
#include <inttypes.h>

// for malloc and free
#include <stdlib.h>

// the buad rate to use for serial comms
static const int BAUD_RATE = 9600;

inline void* operator new(size_t size) { return malloc(size); }
inline void operator delete(void* ptr) { if (ptr) free(ptr); } 

#define ABS(x) (((x)<0) ? (-1*(x)) : (x))









#endif






