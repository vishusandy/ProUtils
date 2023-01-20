#if defined _pro_utils_random_included
    #endinput
#endif
#define _pro_utils_random_included

#if !defined INT_MAX
    #define INT_MAX 2147483647
#endif

#include <pro_utils/common.inc>

// maximum number of samples to take before resorting to modulo bias
#define MAX_RAND_SAMPLES 20



/**
 * Better random numbers?
 * 
 * @param min     minimum value to return
 * @param max     maximum value to return
 * @return        Returns a number from min..max (inclusive)
 */
stock int rand_int(int min, int max) {
    if(min > max) {
        Swap(min, max);
    }
    
    int spread = max - min + 1;
    if(spread <= 0) return 0;
    
    int sample_max = INT_MAX - (INT_MAX % spread);
    
    return rand_int_internal(min, spread, sample_max);
}


/**
 * Simple Fisher-Yates shuffle
 * 
 * @param arr      Param description
 * @param size     Param description
 * @return         Return description
 */
stock void shuffle_array(any[] arr, int size) {
    int sample_max = INT_MAX - (INT_MAX % size);
    
    any tmp;
    for(int i=size-1; i>0; i--) {
        int r = rand_int_internal(0, size, sample_max);
        tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }
}




int rand_int_internal(int min, int spread, int sample_max) {
    int rand = GetURandomInt();
    for(int i=0; i < MAX_RAND_SAMPLES; i++, rand = GetURandomInt()) {
        if(rand > sample_max) {
            continue;
        }
        return (rand % spread) + min;
    }
    
    return (rand % spread) + min;
}
