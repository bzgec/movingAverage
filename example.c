#include "movingAverage.h"
#include <stdio.h>

int main(int argc, char **argv) {
    movingAvg_handle_by_S SMvgAvg_handle_by1;
    uint8_t abyData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 11, 10, 10, 10, 12, 10, 10, 10, 20, 10, 10, 10};
    uint8_t i;

    if(movingAvg_init_by(&SMvgAvg_handle_by1, 10) == TRUE) {
        printf("Filter strength too high!\n\r");
        return 1;
    }

    printf("Filter strength: %u\n\r", SMvgAvg_handle_by1.wFilterStrength);

    for(i = 0; i < sizeof(abyData)/sizeof(abyData[0]); i++) {
        movingAvg_calc_by(&SMvgAvg_handle_by1, abyData[i]);
        printf("i: %2u\t CurrNumb: %2u\t Avg: %2u\t Sum: %u\n\r", i, abyData[i], SMvgAvg_handle_by1.byAverage, SMvgAvg_handle_by1.dwSum);
    }

}