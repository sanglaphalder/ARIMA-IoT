# ARIMA-IoT: Automated Real-time Intelligence for Machine Anomalies

A **Digital Twin** inspired predictive maintenance system that bridges Arduino-based IoT hardware with a Machine Learning pipeline to monitor industrial conveyor health.

---

## 📁 Repository Structure

* **`Arduino Codes/`**: Firmware for sensor data extraction and hardware diagnostics.
* **`ML Model/`**: Jupyter Notebook, trained Random Forest model (`.joblib`), and the training dataset.
* **`Circuit Diagram.pdf`**: Schematic for hardware assembly and pin configurations.

---

## ⚙️ Working Principles

The system operates through a three-stage intelligent loop:

1.  **Data Acquisition**: Sensors monitor belt displacement (Ultrasonic), motor heat (Thermal), and rotation (Tachometer).
2.  **AI Classification**: A Random Forest model analyzes telemetry to distinguish between **Healthy** and **Faulty** states.
3.  **Directional Diagnostics**: If a fault is detected, the system calculates the specific drift direction (**Left/Right**) based on historical sway trends.



---

## 📊 Operational Constraints

The model enforces the following safety boundaries to maintain system integrity:

### **Belt Sway (Ultrasonic)**
* **Safe Zone:** 130cm – 170cm
* **Anomaly:** `< 130cm` (Right drift) or `> 170cm` (Left drift)

### **Thermal Health**
* **Safe Zone:** 20°C – 40°C
* **Anomaly:** `> 40°C` (Indicates friction or motor overload)


---

## 🛠️ Key Features

* **Predictive Alerts**: Identifies "Drift Trends" before mechanical failure occurs.
* **Interactivity**: Includes a Jupyter-based dashboard for real-time parameter testing.
* **Modularity**: Clearly separated hardware and software modules for easy scaling and maintenance.

---

## 💻 Tech Stack

| Category | Tools / Components |
| :--- | :--- |
| **Hardware** | Arduino, Ultrasonic (HC-SR04), Thermistor, DC Motor |
| **Software** | Python (Pandas, Scikit-learn), Jupyter Notebook, Joblib |

---

**Focus:** IoT & Machine Learning Engineering