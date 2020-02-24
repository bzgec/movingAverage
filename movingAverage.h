#ifndef __movingAverage_h
#define __movingAverage_h

#include <stdint.h>

#ifndef NULL
#define NULL 0
#endif  // NULL

#ifndef TRUE
#define TRUE 1
#endif  // TRUE

#ifndef FALSE
#define FALSE 0
#endif  // FALSE

// Which type of variables are you using:
#define USING_BYTE
#define USING_WORD
#define USING_FLOAT


#define MOVING_AVERAGE_FILTER_STRENGTH_BYTE 10  // how much "pipes" it should be
typedef struct movingAvg_handle_by_STRUCTURE {
    uint8_t abyOldNumbers[MOVING_AVERAGE_FILTER_STRENGTH_BYTE];
    uint8_t byAverage;
    uint16_t wSum;
    uint8_t byPos;
    uint8_t byStartPos;   
    uint8_t bIsInitialized;
} movingAvg_handle_by_S;

#define MOVING_AVERAGE_FILTER_STRENGTH_WORD 10  // how much "pipes" it should be
typedef struct movingAvg_handle_w_STRUCTURE {
    uint16_t awOldNumbers[MOVING_AVERAGE_FILTER_STRENGTH_WORD];
    uint16_t wAverage;
    uint32_t dwSum;
    uint8_t byPos;
    uint8_t byStartPos;   
    uint8_t bIsInitialized;
} movingAvg_handle_w_S;

#define MOVING_AVERAGE_FILTER_STRENGTH_FLOAT 10  // how much "pipes" it should be
typedef struct movingAvg_handle_f_STRUCTURE {
    float afOldNumbers[MOVING_AVERAGE_FILTER_STRENGTH_FLOAT];
    float fAverage;
    float fSum;
    uint8_t byPos;
    uint8_t byStartPos;
    uint8_t bIsInitialized;
} movingAvg_handle_f_S;


#if (MOVING_AVERAGE_FILTER_STRENGTH_BYTE  > 255 || \
     MOVING_AVERAGE_FILTER_STRENGTH_WORD  > 255 || \
     MOVING_AVERAGE_FILTER_STRENGTH_FLOAT > 255)
#error 'MOVING_AVERAGE_FILTER_STRENGTH_x' should not be hihger than 255!
#endif

#if (MOVING_AVERAGE_FILTER_STRENGTH_BYTE  < 2 || \
     MOVING_AVERAGE_FILTER_STRENGTH_WORD  < 2 || \
     MOVING_AVERAGE_FILTER_STRENGTH_FLOAT < 2)
#error 'MOVING_AVERAGE_FILTER_STRENGTH_x' should not be smaller than 2!
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USING_BYTE
void movingAvg_init_by(movingAvg_handle_by_S *pHandle);
uint8_t movingAvg_calc_by(movingAvg_handle_by_S *pHandle, uint8_t byNewValue);
#endif  // USING_BYTE

#ifdef USING_WORD
void movingAvg_init_w(movingAvg_handle_w_S *pHandle);
uint16_t movingAvg_calc_w(movingAvg_handle_w_S *pHandle, uint16_t wNewValue);
#endif  // USING_WORD

#ifdef USING_FLOAT
void movingAvg_init_f(movingAvg_handle_f_S *pHandle);
float movingAvg_calc_f(movingAvg_handle_f_S *pHandle, float fNewValue);
#endif  // USING_FLOAT

#ifdef __cplusplus
}
#endif




#endif  // __movingAverage_h