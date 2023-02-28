# Age-Calculator
Find someone's exact age by inputting their date of birth.
## How to Use
Age-Calculator is used in the command line for quick use.
### Format 
```
AgeCalculator.exe <OPTIONS> <PAST_DATE> <PAST_TIME>
AgeCalculator.exe <OPTIONS> <PAST_DATE> <PAST_TIME> - <FUTURE_DATE> <FUTURE_TIME> 
```
If the future date and time is not specified, future date and time will default to the date and time on your machine.
### Options
```
-h, --help            Displays help text
-a, --all             Displays all info 
-y, --years           Displays age in years
-m, --months          Displays age in months
-d, --days            Displays age in days
-hh, --hours          Displays age in hours
-mm, --minutes        Displays age in minutes
-s, --seconds         Displays age in seconds
```
### Examples
###### Example 1
Input:
```
AgeCalculator.exe -a 7/28/2022 12:30:30am
```
Output:
```
Past date: July 28, 2022 12:30:30 am
Future date: February 28, 2023 02:20:48 pm
You are 0 years, 7 months, 0 days, 1 hours, 50 minutes, 18 seconds old...
```
In this example, the future date and time was not specified. So future date defaults to the time the program was executed, which is <br>
Feb 28, 2023 02:20:48 pm
###### Example 2
Input:
```
AgeCalculator.exe -a 8/28/2021 12:00:00am - 7/28/2022 12:30:30pm
```
Output:
```
Past date: August 28, 2021 12:00:00 am
Future date: July 28, 2022 12:30:30 am
You are 0 years, 10 months, 29 days, 12 hours, 30 minutes, 30 seconds old...
```
In this example, the future date is specified.
