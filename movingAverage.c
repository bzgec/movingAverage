#include "movingAverage.h"

// code copied and modified from from https://gist.github.com/bmccormack/d12f4bf0c96423d03f82

static void my_memset(void *pDest, char cValue, uint16_t wLen);


static void my_memset(void *pDest, char cValue, uint16_t wLen) {
    uint8_t *pbyDest;
    if(pDest != NULL) {
        pbyDest = pDest;
        while(wLen > 0) {
            *pbyDest = cValue;
            pbyDest++;
            wLen--;
        }
    }
}

#ifdef USING_BYTE
void movingAvg_init_by(movingAvg_handle_by_S *pHandle) {
    if(pHandle != NULL) {
        my_memset(pHandle, 0, sizeof(movingAvg_handle_by_S));
        pHandle->bIsInitialized = TRUE;
    }
}

uint8_t movingAvg_calc_by(movingAvg_handle_by_S *pHandle, uint8_t byNewValue) {
    if(pHandle != NULL) {
        if(pHandle->bIsInitialized == TRUE) {
            // Subtract the oldest number from previous sum and add new number
            pHandle->wSum = pHandle->wSum - pHandle->abyOldNumbers[pHandle->byPos] + byNewValue;

            // Assign the new value to the position in the array
            pHandle->abyOldNumbers[pHandle->byPos++] = byNewValue;

            if(pHandle->byPos >= MOVING_AVERAGE_FILTER_STRENGTH_BYTE) {
                pHandle->byPos = 0;
            }

            // Calculate the average
            if(pHandle->byStartPos < MOVING_AVERAGE_FILTER_STRENGTH_BYTE) {
                pHandle->byStartPos++;
                pHandle->byAverage = pHandle->wSum / pHandle->byStartPos;
            } else {
                pHandle->byAverage = pHandle->wSum / MOVING_AVERAGE_FILTER_STRENGTH_BYTE;
            }
        } else {
            pHandle->byAverage = 0;
        }
    }  
    
    return pHandle->byAverage;
}
#endif  // USING_BYTE


#ifdef USING_WORD
void movingAvg_init_w(movingAvg_handle_w_S *pHandle) {
    if(pHandle != NULL) {
        my_memset(pHandle, 0, sizeof(movingAvg_handle_w_S));
        pHandle->bIsInitialized = TRUE;
    }
}

uint16_t movingAvg_calc_w(movingAvg_handle_w_S *pHandle, uint16_t wNewValue) {
    if(pHandle != NULL) {
        if(pHandle->bIsInitialized == TRUE) {
            // Subtract the oldest number from previous sum and add new number
            pHandle->dwSum = pHandle->dwSum - pHandle->awOldNumbers[pHandle->byPos] + wNewValue;

            // Assign the new value to the position in the array
            pHandle->awOldNumbers[pHandle->byPos++] = wNewValue;

            if(pHandle->byPos >= MOVING_AVERAGE_FILTER_STRENGTH_WORD) {
                pHandle->byPos = 0;
            }

            // Calculate the average
            if(pHandle->byStartPos < MOVING_AVERAGE_FILTER_STRENGTH_WORD) {
                pHandle->byStartPos++;
                pHandle->wAverage = pHandle->dwSum / pHandle->byStartPos;
            } else {
                pHandle->wAverage = pHandle->dwSum / MOVING_AVERAGE_FILTER_STRENGTH_WORD;
            }
        } else {
            pHandle->wAverage = 0;
        }

    }
    
    return pHandle->wAverage;
}
#endif  // USING_WORD

#ifdef USING_FLOAT
void movingAvg_init_f(movingAvg_handle_f_S *pHandle) {
    if(pHandle != NULL) {
        my_memset(pHandle, 0, sizeof(movingAvg_handle_f_S));
        pHandle->bIsInitialized = TRUE;
    }
}

float movingAvg_calc_f(movingAvg_handle_f_S *pHandle, float fNewValue) {
    if(pHandle != NULL) {
        if(pHandle->bIsInitialized == TRUE) {
            // Subtract the oldest number from previous sum and add new number
            pHandle->fSum = pHandle->fSum - pHandle->afOldNumbers[pHandle->byPos] + fNewValue;

            // Assign the new value to the position in the array
            pHandle->afOldNumbers[pHandle->byPos++] = fNewValue;

            if(pHandle->byPos >= MOVING_AVERAGE_FILTER_STRENGTH_FLOAT) {
                pHandle->byPos = 0;
            }

            // Calculate the average
            if(pHandle->byStartPos < MOVING_AVERAGE_FILTER_STRENGTH_FLOAT) {
                pHandle->byStartPos++;
                pHandle->fAverage = pHandle->fSum / pHandle->byStartPos;
            } else {
                pHandle->fAverage = pHandle->fSum / MOVING_AVERAGE_FILTER_STRENGTH_FLOAT;
            }
        } else {
            pHandle->fAverage = 0;
        }
    }  
    
    return pHandle->fAverage;
}
#endif  // USING_FLOAT
