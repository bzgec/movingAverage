#ifndef __movingAverage_h
#define __movingAverage_h

#include "Types.h"

// Which type of variables are you using:
//#define USING_WORD
#define USING_FLOAT


#ifdef __cplusplus
extern "C" {
#endif

#ifdef USING_WORD
#define MOVING_AVERAGE_FILTER_STRENGTH_WORD 10  // how much "pipes" it should be
WORD  movingAvg_word(WORD wNextNum);
#endif  // USING_WORD

#ifdef USING_FLOAT
#define MOVING_AVERAGE_FILTER_STRENGTH_FLOAT 10  // how much "pipes" it should be
float movingAvg_float(float fNextNum);
#endif  // USING_FLOAT

#ifdef __cplusplus
}
#endif




#endif  // __movingAverage_h