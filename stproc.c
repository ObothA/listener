#include <string.h>
#include <stdio.h>

int main()
{
   char str[1024] = "yR?2017-07-11 06:25:32 TZ=UTC UT=1499754332 GW_LAT=0.32920 GW_LON=32.57100 &: TXT=makg2-10m E64=fcc23d00000031a5 PS=1 T=23.88  V_MCU=3.00 V_IN=4.96  V_A3=291   [ADDR=143.156 SEQ=48 TTL=15 RSSI=6 LQI=255 DRP=0.00 DELAY=0]";
   const char s[2] = " ";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}
