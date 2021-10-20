
struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
void emailAlerter();
void ledAlerter();

struct Stats
{
  float average;
  float min;
  float max;
};

extern int emailAlertCallCount;
extern int ledAlertCallCount;
