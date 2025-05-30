#include <bitset>
#include <iostream>

using namespace std;

void set_clock(int hour, int minute, int second, bool PM)
{
   // address 00h:  bit 0-3 seconds, bit 4-6 10 seconds, bit 7 = 0
   string secondTens = bitset<3>(second / 10).to_string();
   string secondOnes = bitset<4>(second % 10).to_string();
   string binarySeconds = "0" + secondTens + secondOnes;

   // address 01h:  bit 0-3 minutes, bit 4-6 10 minutes, bit 7 = 0
   string minuteTens = bitset<3>(minute / 10).to_string();
   string minuteOnes = bitset<4>(minute % 10).to_string();
   string binaryMinutes = "0" + minuteTens + minuteOnes;

   // address 02h:  bit 0-3 hour, bit 4 10 hour, bit 5 (high is PM), bit 6 (high is 12-hour mode), bit 7 = 0)
   string hourTens = bitset<1>(hour / 10).to_string();
   string hourOnes = bitset<4>(hour % 10).to_string();
   string AMPM = PM ? "1" : "0";
   string binaryHours = "01" + AMPM + hourTens + hourOnes;

   
}

int main()
{
   set_clock(1, 2, 59, false);
   return 0;
}