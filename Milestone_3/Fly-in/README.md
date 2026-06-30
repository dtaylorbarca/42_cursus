*This project has been created as part of the 42 curriculum by dtaylor-.*

## Description

**Fly-in** is an optimization and simulation system designed to route a fleet of autonomous drones through a dynamic network of zones from a starting hub to a target destination in the fewest possible simulation turns. The project models a graph network where vertices represent distinct operational zones (with varying passage costs and drone capacities) and edges represent bidirectional connections between them. 

The core challenge lies in maximizing throughput and preventing deadlocks under tight movement constraints, such as localized zone capacity limits (`max_drones`) and connection bottleneck limitations (`max_link_capacity`).

---

## Instructions

### Prerequisites
* **Python**: Version 3.10 or later is strictly required.
* **Quality & Standards**: The codebase adheres to the `flake8` coding standard and uses `mypy` for mandatory, static type safety.

### Installation
To install the required environment dependencies, run:
```bash
make install
```
## Execution

To execute the main simulation interpreter:
```bash
make run
```

To run the project in debug mode utilizing Python's built-in debugger (`pdb`):  
```bash
make debug
```

To cear temporary caches, pre-compiled bytecode (__pycache__), or mypy artifacts:

```bash
make clean
```
## Linting & Static Typing

To verify code compliance using flake8 and strict mypy checks:

```bash
make lint
```

## Algorithm Choice & Implementation Strategy

### Pathfinding Architecture: Time-Expanded A* Algorithm
To successfully route multiple drones simultaneously without collision or capacity breaches, this implementation adapts the classic **A* Search Algorithm** into a time-expanded state space.  

* **State Representation**: Instead of evaluating nodes purely as static physical locations, a state is evaluated as a tuple of `(zone_name, simulation_turn)`. This allows the pathfinder to dynamically account for zone occupancy changes over discrete time intervals.  
* **Heuristic Function**: We utilize a pre-calculated, standard spatial distance or Dijkstra look-ahead from every node to the `end_hub` to serve as an admissible and consistent heuristic ($h(n)$), ensuring optimal path selection.  

### Handling Zone Mechanics
* **Normal & Priority Zones**: Path costs are factored into the $g(n)$ score calculation. `priority` zones cost 1 turn but are heavily weighted in ties to prioritize high-throughput thoroughfares.  
* **Restricted Zones**: Modeled by mapping a 2-turn movement cost. Drones entering a connection to a restricted zone are locked into an "in-flight" state for 1 turn before claiming space in the destination zone on the subsequent turn.  
* **Capacity Allocation & Conflict Avoidance**: A global reservation table tracks drone positions for every turn. When a drone plans a path, it reserves space within a zone up to its `max_drones` capacity. If a capacity limit or connection link limit (`max_link_capacity`) is reached for a given turn, subsequent drones are forced to evaluate alternative paths or perform strategic wait actions in place until space frees up.  

---

## Visual Representation
To enhance the transparency of the simulation and help evaluate path distribution, this system features a **Colored Terminal Output** interface.  

* **Dynamic Space Visualization**: Zones change structural highlights based on their real-time state (e.g., highlighting bottlenecks when a zone reaches its maximum `max_drones` threshold).  
* **Drone Telemetry Tracker**: Every discrete turn clearly displays space-separated active movements using the standardized `D<ID>-<zone>` syntax (or `D<ID>-<connection>` for transit towards restricted zones), using distinct color blocks to easily distinguish separate paths.  

---

## Resources

### Academic & Technical References
* **A* Search Mechanics**: Amit’s Notes on A* Pathfinding and Heuristics.
* **Multi-Agent Pathfinding (MAPF)**: Conflict-Based Search (CBS) and Time-Expanded Graph routing concepts for multi-agent systems.  
* **Python Standards**: PEP 257 (Docstring Conventions) and PEP 484 (Type Hints).  

### AI Usage Disclosure
AI tools were used strictly as an assistant to reduce tedious formatting tasks and boilerplate logic in compliance with the course guidelines.  

* **Design & Optimization**: AI was used to draft edge-case testing schemas for checking handling of nested `try-except` blocks.  
* **Parsing Mechanics**: AI code-generation patterns helped structure structural tokenization in the input parser to ensure validation of strict configuration syntax rules.
