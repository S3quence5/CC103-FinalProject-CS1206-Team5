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
- The user selects an option

If adding a patient:











