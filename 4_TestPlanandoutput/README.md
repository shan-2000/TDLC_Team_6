# TEST PLAN:
### - It is a detailed document that catalogs the test strategy, objectives, schedule, estimations, deadlines, and the resources required for completing that particular project.

### High Level Test plan:

| ID    | Description                             | Expected O/P | Actual O/P | Type of Test |
|-------|-----------------------------------------| ------------ | ---------- | ------------ |
| H_01  |Detect Human eye blinking                |Detecting     |SUCCESS     | Requirement  |
| H_02  |Display  detected message in LCD board   |Displaying    |SUCCESS     | Scenario     |
| H_03  |If GSM got failure it won't send messages|failed        |Work processing| Future  |
| H_04  |Heart beat sensor have to record rate of heart beat|Recoring         |Activate GSM to send message| Implemented  |
| H_05  |Process Off                              |stop          |SUCCESS     | Implemented  |


### Low Level Test Plan:

| ID    | Description                               | Expected O/P                            | Actual O/P | Type of Test | 
|-------|-----------------------                    | ------------                            | -----------| ------------ |
| L_01  |Identify and sense alcohol gas             | gas sensor Detected                     |SUCCESS      | Requirement  |
| L_02  |Fire sensor senses temperature             | high pass input to ignition relay       |SUCCESS      | Scenario     |
| L_03  |IR sensor senses the objects attitude      | Detecting Drowsy by eye blik rate       |SUCCESS      | Scenario     |
| L_04  |Heart beat sensor to sense heart beat rate | Heart beat rate high/low                |SUCCESS      | Scenario     |
| L_05  |if every sensor activate and results found | Automatically stop vehicle              |SUCCESS      | Implemented  |
