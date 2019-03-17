#include "movingAverage.h"

// code copied and modified from from https://gist.github.com/bmccormack/d12f4bf0c96423d03f82

#ifdef USING_WORD
WORD movingAvg_word(WORD wNextNum)
{
  static WORD s_awOldNumbers[MOVING_AVERAGE_FILTER_STRENGTH_WORD] = {0};
  static DWORD s_dwSum = 0;
  static BYTE s_byPos = 0;
  static BYTE s_byStartPos = 0;

  //Subtract the oldest number from the prev sum, add the new number
  s_dwSum = s_dwSum - s_awOldNumbers[s_byPos] + wNextNum;
  //Assign the wNextNum to the position in the array
  s_awOldNumbers[s_byPos] = wNextNum;
  //return the average
  s_byPos++;
  if (s_byPos >= MOVING_AVERAGE_FILTER_STRENGTH_WORD)
  {
    s_byPos = 0;
  }

  if(s_byStartPos < MOVING_AVERAGE_FILTER_STRENGTH_WORD)
  {
    s_byStartPos++;
    return s_dwSum / s_byStartPos;
  }
  else
  {
    return s_dwSum / MOVING_AVERAGE_FILTER_STRENGTH_WORD;
  }
}
#endif  // USING_WORD

#ifdef USING_FLOAT
float movingAvg_float(float fNextNum)
{
  static float s_afOldNumbers[MOVING_AVERAGE_FILTER_STRENGTH_FLOAT] = {0};
  static float s_fSum = 0;
  static BYTE s_byPos = 0;
  static BYTE s_byStartPos = 0;

  //Subtract the oldest number from the prev sum, add the new number
  s_fSum = s_fSum - s_afOldNumbers[s_byPos] + fNextNum;
  //Assign the fNextNum to the position in the array
  s_afOldNumbers[s_byPos] = fNextNum;
  //return the average
  s_byPos++;
  if (s_byPos >= MOVING_AVERAGE_FILTER_STRENGTH_FLOAT)
  {
    s_byPos = 0;
  }

  if(s_byStartPos < MOVING_AVERAGE_FILTER_STRENGTH_FLOAT)
  {
    s_byStartPos++;
    return s_fSum / s_byStartPos;
  }
  else
  {
    return s_fSum / MOVING_AVERAGE_FILTER_STRENGTH_FLOAT;
  }
  
}
#endif  // USING_FLOAT
