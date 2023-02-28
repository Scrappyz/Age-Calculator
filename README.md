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
* -h, --help            Displays help text
* -a, --all             Displays all info 
* -y, --years           Displays age in years
* -m, --months          Displays age in months
* -d, --days            Displays age in days
* -hh, --hours          Displays age in hours
* -mm, --minutes        Displays age in minutes
* -s, --seconds         Displays age in seconds
### Examples
##### Example 1
```
AgeCalculator.exe -a 7/28/2022 12:30:30am
Past date: July 28, 2022 12:30:30 am
Present date: February 28, 2023 02:20:48 pm
You are 0 years, 7 months, 0 days, 1 hours, 50 minutes, 18 seconds old...
```
In this example, the future date and time was not specified. So future date defaults to the time the program was executed, which is Feb 28, 2023 2023 02:20:48 pm
