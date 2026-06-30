# 42 Cursus - Common Core

This repository serves as a centralized archive for my journey through the **42 Cursus**. It tracks my progression from basic C programming to complex systems and network architecture.

---

## Project Roadmap

### Milestone 0

| Project | Language | Description | Folder | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Libft** | C | My own implementation of C standard library functions. | [`/Milestone_0/libft`](./Milestone_0/libft) | Finished |

### Milestone 1

| Project | Language | Description | Folder | Status |
| :--- | :--- | :--- | :--- | :--- |
| **ft_printf** | C | Recreating the printf function using variadic functions. | [`/Milestone_1/ft_printf`](./Milestone_1/ft_printf) | Finished |
| **get_next_line** | C | Developing a function to read lines from a file descriptor. | [`/Milestone_1/get_next_line`](./Milestone_1/get_next_line) | Finished |
| **push_swap** | C | Optimized stack sorting using a limited set of operations and complex algorithms. | [`/Milestone_1/push_swap`](./Milestone_1/push_swap) | Finished |

### Milestone 2

| Project | Language | Description | Folder | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Exam Rank 02**   | C      | | [`/Milestone_2/Exam_Rank_02`](./Milestone_2/Exam_Rank_02/) | Finished |
| **Python Piscina** | Python | | [`/Milestone_2/Piscina_Python`](./Milestone_2/Python_Piscina/)| Finished |
| **A-Maze-ing**     | Python | A configuration-driven maze generator and visualizer that exports perfect, hexadecimal-encoded structures.| [`/Milestone_2/A-Maze-ing`](./Milestone_2/A-Maze-ing/) | Finished |
| **Born2beroot**    | Shell  | A strictly secured Debian server deployed on a VirtualBox VM featuring encrypted LVM partitioning, SSH, and a UFW firewall. | [`/Milestone_2/Born2beroot`](./Milestone_2/Born2beroot/) | Finished |

### Milestone 3

| Project | Language | Description | Folder | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Fly-in**         | Python | An optimization system that routes a multi-drone fleet through network zones while minimizing simulation turns. | [`/Milestone_3/`](./Milestone_3/Fly-in/) | In progress |



---

## About 42 Madrid

The **42 Cursus** is a rigorous software engineering program based on peer-to-peer learning and practical, project-based evaluation. There are no teachers or classrooms; students progress by solving increasingly difficult challenges and defending their code in peer reviews.

### Core Competencies Developed:
* **Memory Management:** Mastery of stack/heap allocation and leak prevention using Valgrind.
* **Unix/Linux Systems:** Understanding system calls, signals, and process management.
* **Algorithm Design:** Implementing sorting, searching, and optimization logic.
* **The Norm:** Writing standardized, readable code according to strict 42 guidelines.

---

## Repository Management

I maintain this repository using the `git subtree` method. This allows me to pull my original work from the 42 internal system (**vogsphere**) while preserving the full commit history and original timestamps.

### Compilation
To compile any project, navigate to its subdirectory and use the provided `Makefile`:
```bash
cd libft && make
```
