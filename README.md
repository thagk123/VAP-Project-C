# 🛤️ Route Data Management System

📚 University project for the course **Basic Programming Principles**.  

This project manages **route data**, including distance, elevation changes, travel time, and other parameters.  
The program supports sorting, searching, and saving data, with capabilities to read from a file or from user input.

---

## ✨ Key Features

### 📋 Route Data Display
- Show routes with details such as starting point, destination, length, elevation changes, and estimated time.

### 🔍 Search
- Search for routes based on length, location, or elevation.  
- Find routes with more uphill or downhill sections.  

### 📊 Sorting
- Sort routes by length (in descending order).  

### 💾 Saving and Reading
- Read route data from a file.  
- Save sorted data to a file.  

---

## 🛠️ Class and Function Descriptions

### 📌 Data Structure
- **`struct route`**: Represents a route, with fields:  
  - `ekk`: Starting point  
  - `term`: Ending point  
  - `mikos`: Route length  
  - `ana`: Uphill elevation  
  - `kata`: Downhill elevation  
  - `meg`: Maximum altitude  
  - `el`: Minimum altitude  

### ⚙️ Main Functions
- **`print1`** and **`print2`**: Print route details  
- **`taksinomisi`**: Sort routes by length  
- **`readFromInput`**: Read route data from user input  
- **`readFromFile`**: Read route data from a file  
- **`saveData`**: Save route data to a file  
- **`findShort`**: Find routes shorter than or equal to a given length  
- **`findLocation`**: Find routes containing a specific location  
- **`findAltitude`**: Find routes within a specific altitude range  
- **`findUpHill`** and **`findDownHill`**: Find routes with more uphill or downhill sections  
- **`findTimely`**: Find routes that can be completed within a specific time  

---
