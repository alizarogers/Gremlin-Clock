/*
//   Sets DS3231 RTC time. Enter the correct time, to the second.
//   This only has to be ran when the RTC loses power.
//   Run by:
//    make
//    ./initializeClock <hour> <minute> <second> <"AM" or "PM">
*/


#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

vector<string> get_bitstrings(int hour, int minute, int second, bool PM)
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

   return vector<string>{binaryHours, binaryMinutes, binarySeconds};
}

int main(int argc, char* argv[])
{
   bool isPM = ((string(argv[4]) == "PM") or (string(argv[4]) == "pm"));
   vector<string> bitstrings;

   bitstrings = get_bitstrings(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]), isPM);

   some_function_for_setting the time(bitstrings)


   return 0;
}