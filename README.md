# **Age Calculator**
Find someone's exact age by their date of birth. Have you ever forgotten your age before? Because I have.
## **How to Use**
```
AgeCalculator.exe <OPTIONS> <PAST_DATE> <PAST_TIME>
AgeCalculator.exe <OPTIONS> <PAST_DATE> <PAST_TIME> - <FUTURE_DATE> <FUTURE_TIME> 
```
Date format to be used is **MM/DD/YYYY** <br>
If the future date and time is not specified, future date and time will default to the date and time on your machine. 
## **Options**
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
### **Examples**
***
#### **Example 1**
Input:
```
AgeCalculator.exe -a 7/28/2022 12:30:30am
```
Output:
```
Past date: July 28, 2022 12:30:30am
Future date: February 28, 2023 02:20:48pm
You are 0 years, 7 months, 0 days, 1 hours, 50 minutes, 18 seconds old...
```
In this example, the future date and time was not specified. So future date defaults to the time the program was executed, which is
Feb 28, 2023 02:20:48 pm.

***

#### **Example 2**
Input:
```
AgeCalculator.exe -a 8/28/2021 12:00:00am - 7/28/2022 12:30:30pm
```
Output:
```
Past date: August 28, 2021 12:00:00am
Future date: July 28, 2022 12:30:30am
You are 0 years, 10 months, 29 days, 12 hours, 30 minutes, 30 seconds old...
```
In this example, the future date is specified.

***

#### **Example 3**
Input:
```
AgeCalculator.exe -a 8/28/2021 - 7/28/2022
```
Output:
```
Past date: August 28, 2021 12:00:00am
Future date: July 28, 2022 12:00:00am
You are 0 years, 11 months, 0 days, 0 hours, 0 minutes, 0 seconds old...
```
In this example, both dates are specified but their times are not. If the time is not specified, it will default to <br> 12:00:00am.

***

#### **Example 4**
Input:
```
AgeCalculator.exe -a September 30, 2002 2:30am - Dec 31, 2022 3:25:10am
```
Output:
```
Past date: September 30, 2002 02:30:00am
Future date: December 31, 2022 03:25:10am
You are 20 years, 3 months, 1 days, 0 hours, 55 minutes, 10 seconds old...
```
We can also use words for the months like "March" or their shorter version "Mar". It is not case sensitive so "sep" or even "sEpTemBer" will work.

***