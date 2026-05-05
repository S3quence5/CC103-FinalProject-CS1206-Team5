# QuickCare: Clinic Patient Management System
#

## Team Details

Team Number: 5  
Team Name: Health 404 Not Found  

| SR-Code | Name | Role |
|--------|------|------|
| 25-06477 | Cabral, Will Geoff D. | System Architect |
| 25-04710 | Lapso, Mon Raven D. | Main Programmer |
| 25-06751 | Moren, Kylle P. | Documenter |

---

## Problem Description
In many clinics, managing patients can be difficult, especially when there are both regular and emergency cases. This can lead to long waiting times and confusion about which patient should be treated first.

---

## Program Description
QuickCare is a C++ console-based program that helps manage patients in a clinic.

It allows the user to:
- Add patients
- Automatically identify if a patient is priority or not
- Process patients
- Undo the last action
- Display all patients

---

## Data Structures Used
We used three main data structures in this project:
| Data Structure | Where it is used | Reason |
|---------------|----------------|--------|
| Queue | Normal patients | Ensures patients are processed in order (FIFO) |
| Priority Queue | Priority patients | Allows urgent patients to be handled first |
| Stack | Undo feature | Reverses the most recent action (LIFO) |

---

## Algorithm
- The program displays a menu using a loop  
- The user selects an option from the menu

When adding a patient:
- Input patient details
- Compute priority level
- Store in priority queue or normal queue

When processing a patient:
- Priority queue is checked first
- If empty, normal queue is used

When undo is selected:
- The last action is retrieved from the stack
- The system reverses that action

When displaying patients:
- Recursive functions are used to display:
  - Priority patients (showPriorityRecursive)
  - Normal patients (showNormalRecursive)

---

## Iterative vs Recursive
| Approach | Usage | Notes |
|---------|------|------|
| Iterative | Menu loop (`while(true)`) | Controls program flow |
| Recursive | Display patients | Cleaner logic but uses more memory |

---

## Features
- Add patient  
- Process patient  
- Undo last action  
- Display all patients  
- Priority-based processing  

---

## Limitations
- No database (data is not saved)
- Undo function is limited in accuracy
- Console-based only

---

## Future Improvements
- Improve undo system
- Add search feature
- Add graphical interface





---

## Acknowledgement

We would like to thank our instructor for guiding us throughout this project and helping us understand how data structures can be applied to real-world problems like our system.

---

## Conclusion

This project demonstrates how Queue, Priority Queue, and Stack can be used together to manage patients in a clinic. It shows how proper use of data structures can improve efficiency and organization in real-life situations.







