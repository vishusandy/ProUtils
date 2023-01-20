#if defined _pro_utils_common_included
    #endinput
#endif
#define _pro_utils_common_included


stock int Clamp(int val, int min, int max) {
    return (val < min)? min:(val > max)? max: val;
}

stock void Swap(any &a, any &b) {
    any tmp = b;
    a = b;
    b = tmp;
}
