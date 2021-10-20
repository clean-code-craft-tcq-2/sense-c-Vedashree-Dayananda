#include "stats.h"
#include "alerter.h"
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    float sum = 0;
    int i = 0;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    if(setlength)
    {
        s.min = numberset[0];
        s.max = numberset[0];
        sum = numberset[0];
        for(i=1;i<setlength;i++)
        {
            if(numberset[i] < s.min)
            {
                s.min = numberset[i];
            }
            else if(numberset[i] > s.max)
            {
                s.max = numberset[i];
            }
            sum = sum + numberset[i];
        }
        s.average = sum/setlength;
    }
    else
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
    }
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    int i=0;
    if ( computedStats.max > maxThreshold)
    {
        while(alerters[i])
        {
            alerters[i++]();
        }
    }
}
