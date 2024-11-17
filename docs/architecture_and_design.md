# Architecture and Design

---

## 1. **Architecture Paradigm**

### Chosen Paradigm: **Modular, Component-Based Architecture**

This component-based architecture divides the system into distinct modules, each performing a specific function, allowing easy integration, maintenance, and scalability. 

- **Architecture Diagram**: Below is the **Architecture Diagram**, providing a high-level view of the system.

```plaintext
+---------------------------------------------+
|               User Interface                |
|    (Command-Line or GUI for Execution)      |
+---------------------------------------------+
                   |
                   v
+---------------------------------------------+
|           Execution Engine                  |
|  - Algorithm Selector                       |
|  - Parameter Tuning                         |
+---------------------------------------------+
                   |
                   v
+---------------------------------------------+
|       Optimization Layer                    |
| - Quantum Algorithms                        |
|     - QAOA, Grover’s, VQE, Quantum Annealing|
|     - QSVM, QMC, QPCA                       |
| - Classical Algorithms                      |
|     - Markowitz, Black-Litterman, Risk Parity|
|     - Genetic Algorithms, Simulated Annealing|
+---------------------------------------------+
                   |
                   v
+---------------------------------------------+
|      Data Management and Utilities          |
| - DataLoader                                |
| - QUBOFormulation                           |
| - RiskCalculator                            |
+---------------------------------------------+
                   |
                   v
+---------------------------------------------+
|        Evaluation & Visualization           |
| - PerformanceEvaluator                      |
| - Visualizer                                |
+---------------------------------------------+
```

### Explanation:

- **Data Management and Utilities** handles data import, transformation, and QUBO preparation.
- **Optimization Layer** provides implementations of quantum and classical algorithms.
- **Execution Engine** controls algorithm selection, tuning, and execution.
- **Evaluation & Visualization** presents comparative performance results and insights.

---

## 2. **Component Diagram**

The **Component Diagram** shows individual components and their connections, highlighting the interactions among the algorithms and data management.

```plaintext
+------------------------+        +--------------------------+
|      DataLoader        |        |      QUBOFormulation     |
+------------------------+        +--------------------------+
             |                           |
             v                           v
+------------------------+        +--------------------------+
|     RiskCalculator     |<------>|      QuantumAlgorithm    |
+------------------------+        |       (QAOA, VQE, QSVM)  |
                                  +--------------------------+
                                           |
                                           |
+------------------------+                  |
|  ClassicalAlgorithms   |<----------------+
|  (Markowitz, etc.)     | 
+------------------------+  
             |
             |
             v
+------------------------+            +----------------------+
|   PerformanceEvaluator |<---------->|      Visualizer      |
+------------------------+            +----------------------+
```

### Explanation:

- **DataLoader**: Loads and preprocesses financial data.
- **QUBOFormulation**: Transforms data into QUBO format for quantum optimization.
- **RiskCalculator**: Computes portfolio risk metrics and constraints.
- **QuantumAlgorithm**: Executes quantum algorithms (e.g., QAOA, VQE, QSVM).
- **ClassicalAlgorithms**: Provides classical optimization alternatives.
- **PerformanceEvaluator** and **Visualizer**: Analyzes and displays results, comparing quantum and classical outputs.

---

## 3. **Package Diagram**

The **Package Diagram** organizes components into logical groupings for modular development and integration.

```plaintext
+------------------------+        +--------------------------+
|    quantum_algorithms  |        |    classical_algorithms  |
|  - QAOA                |        |  - MarkowitzOptimizer    |
|  - VQE                 |        |  - BlackLitterman        |
|  - QSVM                |        |  - RiskParity            |
|  - QPCA                |        |  - GeneticAlgorithm      |
+------------------------+        +--------------------------+

+------------------------+        +--------------------------+
|         utils          |        |         tests            |
|  - DataLoader          |        |  - test_QuantumPortfolio |
|  - QUBOFormulation     |        |    Optimization.cpp      |
|  - RiskCalculator      |        +--------------------------+
+------------------------+        
```

### Package Descriptions:

- **quantum_algorithms**: Implements quantum algorithms (QAOA, VQE, QSVM, QPCA).
- **classical_algorithms**: Provides classical optimization algorithms (Markowitz, Black-Litterman).
- **utils**: Common utilities (data loading, QUBO formulation, risk calculation).
- **tests**: Contains test cases to validate system functionality.

---

## 4. **Workflow Diagram**

The **Workflow Diagram** outlines the sequence of steps from data ingestion through optimization and visualization.

```plaintext
+------------------------+
|    DataLoader          |
+------------------------+
             |
             v
+------------------------+
|     RiskCalculator     |
+------------------------+
             |
             v
+------------------------+
|   QUBOFormulation      |
+------------------------+
             |
             v
+------------------------+            +----------------------+
| QuantumAlgorithm       |            | ClassicalAlgorithm   |
| (QAOA, QSVM, etc.)     |            | (Markowitz, etc.)    |
+------------------------+            +----------------------+
             |                           |
             v                           v
+------------------------+       +--------------------------+
|   PerformanceEvaluator |<----->|        Visualizer        |
+------------------------+       +--------------------------+
```

### Workflow Explanation:

1. **DataLoader** reads and preprocesses data.
2. **RiskCalculator** computes risk-related metrics.
3. **QUBOFormulation** prepares data in QUBO format.
4. **Optimization Algorithm** (quantum or classical) performs portfolio optimization.
5. **PerformanceEvaluator** assesses and compares results.
6. **Visualizer** displays the efficient frontier and other relevant visualizations.

---

## 5. **Detailed Sequence Diagrams**

### Example: **Quantum Algorithm Execution (QAOA)**

```plaintext
User              Execution Engine     DataLoader     RiskCalculator   QUBOFormulation   QuantumAlgorithm  PerformanceEvaluator   Visualizer
 |---------------->|                       |                 |                |                  |                  |                    |
 |   select QAOA   |                       |                 |                |                  |                  |                    |
 |                 |---------------------> |                 |                |                  |                  |                    |
 |                 |   loadData()          |                 |                |                  |                  |                    |
 |                 |                       |---------------->|                |                  |                  |                    |
 |                 |                       |   calculateRisk |--------------->|                  |                  |                    |
 |                 |                       |                 |                |                  |                  |                    |
 |                 |                       |                 |     quboTransform()              |                  |                    |
 |                 |                       |                 |                |----------------->|                  |                    |
 |                 |                       |                 |                |                  | optimize()       |                    |
 |                 |                       |                 |                |                  |----------------->|                    |
 |                 |                       |                 |                |                  |                  | evaluate()         |
 |                 |                       |                 |                |                  |                  |------------------->|
```

---

## 6. **Class Diagrams**

```plaintext
+----------------------+
|      DataLoader      |
+----------------------+
| - dataSource         |
| - historicalData     |
+----------------------+
| + loadData()         |
| + preprocessData()   |
+----------------------+

+----------------------+
|     QUBOFormulation  |
+----------------------+
| - quboMatrix         |
| - constraints        |
+----------------------+
| + transformToQUBO()  |
+----------------------+

+----------------------+
|   QuantumAlgorithm   |
+----------------------+
| # optimize()         |
| # tuneParameters()   |
+----------------------+
| - QAOA               |
| - VQE                |
| - QSVM               |
+----------------------+

+----------------------+
| ClassicalAlgorithm   |
+----------------------+
| + optimize()         |
+----------------------+
| - Markowitz          |
| - BlackLitterman     |
+----------------------+

+----------------------+
|  PerformanceEvaluator|
+----------------------+
| - metrics            |
| + evaluate()         |
+----------------------+

+----------------------+
|      Visualizer      |
+----------------------+
| + plotEfficientFrontier() |
| + displayMetrics()   |
+----------------------+
```

---

## 7. **Deployment Diagram**

The **Deployment Diagram** outlines where components are deployed.

```plaintext
                +-----------------------------+
                |        User System          |
                |   (Command-line or GUI)     |
                +-----------------------------+
                          |
                          |
                          v
 +-------------------------------+       +-----------------------------+
 |      Local Server             |       |      Quantum Processor      |
 |  - DataLoader                 |       | - Executes Quantum Algs     |
 |  - ClassicalAlgorithm         |       |   (API or Local Access)     |
 |  - PerformanceEvaluator       |       +-----------------------------+
 +-------------------------------+
                          |
                          v
                +-----------------------------+
                |     Visualization Engine     |
                | - Visualizer                 |
                +-----------------------------+
```

### Deployment Details:

- **Local Server**: Hosts classical algorithms, data processing, and evaluation.
- **Quantum Processor**: Executes quantum algorithms, accessed locally or via API.
- **Visualization Engine**: Displays results via local or web-based interface.

---

## 8. **Use Case Diagram**

The **Use Case Diagram** outlines user interactions with the application.

```plaintext
                +----------------------------+
               

 |         User               |
                +----------------------------+
                          |
               +---------------------------+
               | Run Portfolio Optimization|
               +---------------------------+
                          |
                          v
               +---------------------------+
               | View Portfolio Performance|
               +---------------------------+
                          |
                          v
               +---------------------------+
               | Save Results              |
               +---------------------------+
                          |
                          v
               +---------------------------+
               | Compare Quantum and       |
               | Classical Results         |
               +---------------------------+
``` 
