#if defined _pro_utils_strings_included
    #endinput
#endif
#define _pro_utils_strings_included

stock void StringToLower(char[] string) {
    int len = strlen(string);
    for(int i=0; i < len; i++) {
        string[i] = CharToLower(string[i]);
    }
}

// Source: https://forums.alliedmods.net/showthread.php?t=191743
stock void AddComma(char[] sString, iSize, iPosition ) {
    char sTemp[32];
    FormatEx( sTemp, iPosition + 1, "%s", sString ), 
    Format( sTemp, 31, "%s,", sTemp );
    Format( sTemp, 31, "%s%s", sTemp, sString[ iPosition ] );
    FormatEx( sString, iSize, "%s", sTemp );
}

// Source: https://forums.alliedmods.net/showthread.php?t=191743
stock void NumberFormat( iNumber, char[] sNumber, iSize ) {
    bool bNegative = iNumber < 0 ? true : false;
    
    if( bNegative ) {
        iNumber *= -1;
    }
    
    FormatEx( sNumber, iSize, "%d", iNumber );
    
    for( int i = strlen( sNumber ) - 3; i > 0; i -= 3 ) {
        AddComma( sNumber, iSize, i );
    }
    
    if( bNegative ) {
        Format( sNumber, iSize, "-%s", sNumber );
    }
}


