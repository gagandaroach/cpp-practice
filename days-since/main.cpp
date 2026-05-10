#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    // Get current time
    time_t now = time(nullptr);
    tm* now_tm = localtime(&now);
    // Save a copy for printing today's date (without time changes)
    tm today_tm = *now_tm;

    // Adjust now_tm to noon for calculation to avoid DST issues
    now_tm->tm_hour = 12;
    now_tm->tm_min = 0;
    now_tm->tm_sec = 0;
    time_t today_noon = mktime(now_tm);

    // Get target date from user
    int year, month, day;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;

    // Create target tm struct and set to noon
    tm target_tm = {};
    target_tm.tm_year = year - 1900;
    target_tm.tm_mon = month - 1;
    target_tm.tm_mday = day;
    target_tm.tm_hour = 12;
    target_tm.tm_min = 0;
    target_tm.tm_sec = 0;
    target_tm.tm_isdst = -1; // let mktime determine daylight saving
    time_t target_noon = mktime(&target_tm);

    // Calculate difference in seconds and convert to days
    double seconds = difftime(today_noon, target_noon);
    int days = static_cast<int>(seconds / (60 * 60 * 24));

    // Print today's date
    cout << "Today's date: "
         << setfill('0')
         << setw(4) << (today_tm.tm_year + 1900) << '-'
         << setw(2) << (today_tm.tm_mon + 1) << '-'
         << setw(2) << today_tm.tm_mday << endl;

    // Print target date (normalized by mktime)
    cout << "Target date: "
         << setfill('0')
         << setw(4) << (target_tm.tm_year + 1900) << '-'
         << setw(2) << (target_tm.tm_mon + 1) << '-'
         << setw(2) << target_tm.tm_mday << endl;

    // Print days since
    cout << "Days since target date: " << days << endl;

    return 0;
}