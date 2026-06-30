*This project has been created as part of the 42 curriculum by dtaylor-.*

# Born2beRoot

## 1. Description
[cite_start]**Born2beRoot** is a foundational system administration project in the 42 curriculum designed to introduce the core mechanics of virtualization, operating system configuration, and network security[cite: 191, 204]. [cite_start]The primary objective is to build a fully secure, headless server running either Debian or Rocky Linux from scratch within a virtual machine environment (VirtualBox or UTM)[cite: 205, 206, 264, 269]. 

[cite_start]The project emphasizes rigid architectural constraints: the total absence of graphical interfaces (no X.org or Wayland) [cite: 267, 268][cite_start], precise storage partitioning using encrypted Logical Volume Management (LVM) [cite: 275][cite_start], access control implementation via an audited `sudo` setup [cite: 297][cite_start], structured account security and password policies [cite: 296, 301][cite_start], firewall enforcement [cite: 288][cite_start], and continuous shell-based telemetry scripting monitored via cron daemons[cite: 324, 335].

---

## 2. Project Comparison & Technical Choices

### 2.1 Operating System: Debian vs. Rocky Linux
[cite_start]This implementation utilizes **Debian** as the primary operating system[cite: 269, 270]. Below is a comparative overview highlighting the structural tradeoffs between the two authorized choices:

| Operating System | Advantages | Disadvantages |
| :--- | :--- | :--- |
| **Debian** | [cite_start]• Highly predictable, stable release cycles.<br>• Extensive package repositories and documentation.<br>• Lightweight footprint out of the box.<br>• Highly recommended for beginners in system admin[cite: 270]. | • Ships with older package versions due to exhaustive stability testing cycles.<br>• Less immediate integration with enterprise-level corporate support channels compared to RHEL derivatives. |
| **Rocky Linux** | • Binary-compatible downstream clone of Red Hat Enterprise Linux (RHEL).<br>• Optimized directly for corporate high-availability enterprise server environments.<br>• Advanced security controls built natively into the upstream RHEL codebase. | [cite_start]• Considerably more complex initialization and setup framework [cite: 272][cite_start].<br>• Requires additional configuration overrides (e.g., handling SELinux instead of AppArmor)[cite: 273, 274]. |

### 2.2 Package Management: apt vs. aptitude
* [cite_start]**`apt`**: A streamlined, high-level command-line tool that handles package installation, updates, and removal[cite: 281]. It is fast, intuitive, and the modern standard for general Debian operations.
* [cite_start]**`aptitude`**: A more robust, advanced front-end to APT that includes an interactive text-user interface (TUI)[cite: 281]. It features a superior dependency resolution engine that provides multiple structural options to resolve conflicting packages, and explicitly logs operations and tracks automatically installed dependencies for cleaner purges.

### 2.3 Security Modules: AppArmor vs. SELinux
* [cite_start]**AppArmor (Debian standard)**: A Mandatory Access Control (MAC) system that binds security profiles directly to executable paths[cite: 274, 281]. It uses simple, human-readable text files to define system permissions, making it straightforward to maintain and audit.
* [cite_start]**SELinux (Rocky Linux standard)**: A highly granular MAC system that assigns security contexts (labels) to all system files, processes, and users[cite: 273, 281]. It separates enforcement from identity and relies on a compiled policy matrix, providing immense security resolution at the cost of high configuration complexity.

### 2.4 Firewalls: UFW vs. firewalld
* [cite_start]**UFW (Uncomplicated Firewall)**: A user-friendly front-end interface managing netfilter iptables rules. It focuses on intuitive CLI commands (e.g., `ufw allow 4242/tcp`) and is ideally suited for managing single-host network rules.
* [cite_start]**firewalld**: A dynamic daemon designed for RHEL ecosystems (like Rocky Linux) supporting network "zones" to define trust levels for connections or interfaces[cite: 288, 293]. It applies runtime rules dynamically without breaking existing network sessions.

### 2.5 Hypervisors: VirtualBox vs. UTM
* [cite_start]**VirtualBox**: A mature, feature-rich x86/amd64 type-2 hypervisor with wide platform compatibility, comprehensive snapshot capabilities, and detailed hardware exposure controls[cite: 256].
* [cite_start]**UTM**: A streamlined, macOS-native virtualization platform built directly on Apple's Hypervisor.framework and QEMU[cite: 256]. It provides optimized hardware acceleration for Apple Silicon (ARM M1/M2/M3) architectures.

---

## 3. System Design & Design Choices

### 3.1 Encrypted LVM Partitioning Layout
[cite_start]The system is configured with a strict, encrypted multi-partition schema using **LVM (Logical Volume Management)** to mitigate systemic failures by isolating system directories, preventing log-based denial-of-service vectors, and protecting data-at-rest[cite: 275].

```bash
# Structural framework output using lsblk
NAME                     MAJ:MIN RM  SIZE RO TYPE  MOUNTPOINT
sda                        8:0    0    8G  0 disk  
├─sda1                     8:1    0  487M  0 part  /boot
├─sda2                     8:2    0    1K  0 part  
└─sda5                     8:5    0  7.5G  0 part  
  └─sda5_crypt           254:0    0  7.5G  0 crypt 
    ├─wil--vg-root       254:1    0  2.8G  0 lvm   /
    ├─wil--vg-swap_1     254:2    0  976M  0 lvm   [SWAP]
    └─wil--vg-home       254:3    0  3.8G  0 lvm   /home
```


## 3.2 Security and Access Control Policies

### Password Policy Constraints (`/etc/login.defs` & `libpam-pwquality`)

- **Expiration:** Maximum password age of 30 days; minimum of 2 days between modifications.
- **Warning Window:** Proactive expiration alerts triggered 7 days prior.
- **Complexity:** Minimum length of 10 characters; must contain 1 uppercase letter, 1 lowercase letter, and 1 numeric digit.
- **Structural Restraints:** Maximum of 3 consecutive identical characters allowed. No inclusion of user identity strings.
- **History:** At least 7 characters must differ from the previous password (does not apply to root).

### Sudo Configuration Regulations (`/etc/sudoers.d/custom`)

- **Attempt Limits:** Restricted to 3 consecutive failures before session rejection.
- **Custom Warnings:** Configured with a dedicated alert string shown upon password failure.
- **I/O Log Archiving:** Comprehensive logging of all inputs and operational outputs directed to `/var/log/sudo/`.
- **Terminal Security:** TTY mode explicitly enforced for execution.
- **Path Restrictions:** Execution binaries strictly bounded to: `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`.

---

## 3.3 Networking & Services Deployment

- **Hostname:** Set dynamically as `<login>42` (e.g., `wil42`), capable of being systematically updated via `hostnamectl` during peer evaluations.
- **SSH Service:** Explicitly bounded to run exclusively over Port `4242`. Root authentication login via SSH is disabled natively within `/etc/ssh/sshd_config` via `PermitRootLogin no`.
- **Firewall Enforcement:** Configured utilizing UFW, closing all network vector endpoints by default except for inbound traffic targeting port `4242`.

---

## 4. Monitoring Script (`monitoring.sh`)

A custom automation script written in native Bash captures real-time server telemetry. It runs continuously via an automated system cron schedule, broadcasting diagnostic data to all active terminals every 10 minutes using the `wall` utility.

```bash
#!/bin/bash
arch=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
vcpu=$(grep -c "^processor" /proc/cpuinfo)
mem_used=$(free -m | awk '$1 == "Mem:" {print $3}')
mem_total=$(free -m | awk '$1 == "Mem:" {print $2}')
mem_pct=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
disk_used=$(df -m / | awk 'NR==2 {print $3}')
disk_total=$(df -h / | awk 'NR==2 {print $2}')
disk_pct=$(df -m / | awk 'NR==2 {print $5}')
cpu_l=$(vmstat 1 2 | tail -1 | awk '{print 100 - $15"%"}')
lb=$(who -b | awk '{print $3" "$4}')
lvm_u=$(if [ $(lsblk | grep -c "lvm") -gt 0 ]; then echo "yes"; else echo "no"; fi)
tcpc=$(ss -neopt state established | wc -l)
ulog=$(users | wc -w)
ip_add=$(hostname -I | awk '{print $1}')
mac_add=$(ip link show | grep "link/ether" | awk '{print $2}')
sudo_c=$(journalctl _COMM=sudo | grep -c "COMMAND")

wall "
#Architecture: $arch
#Physical CPU: $pcpu
#vCPU: $vcpu
#Memory Usage: $mem_used/${mem_total}MB ($mem_pct%)
#Disk Usage: $disk_used/${disk_total} ($disk_pct)
#CPU load: $cpu_l
#Last boot: $lb
#LVM use: $lvm_u
#TCP Connections: $tcpc ESTABLISHED
#User log: $ulog
#Network: IP $ip_add ($mac_add)
#Sudo: $sudo_c cmd"
```

---

## 5. Instructions

### 5.1 Compilation & Deployment Execution

Because the project entails server deployment, execution occurs inside the virtualized hypervisor container. To check the system state and ensure runtime stability across evaluation requirements, use the following operational validation workflow:

```bash
# 1. Verify firewall deployment state and active port mapping lists
sudo ufw status numbered

# 2. Check the configuration status of active background service daemons
sudo systemctl status ssh
sudo systemctl status apparmor

# 3. Validate correct encrypted multi-partition configurations
lsblk

# 4. Terminate or manually override the automated background monitoring daemon
sudo crontab -e
# Comment out or remove the active line targeting execution of monitoring.sh
```

### 5.2 Retrieving the Virtual Disk Signature

To generate the necessary verification signature for project submission, run one of the following commands in your host terminal based on your operating system environment:


- **Linux:**

```

sha1sum ~/VirtualBox\ VMs/<folder>/rocky_serv.vdi

```

---

## 6. Bonus Part Configuration (If Applicable)

- **Extended LVM Schema:** Implements decoupled target volume allocation paths separating volatile runtime and persistent content directories (including `/var`, `/var/log`, `/srv`, and `/tmp` templates).
- **Lightweight LNMP Stack Deployment:** Installs and connects `lighttpd` as the web server, `MariaDB` as the localized relational database engine, and `PHP-FPM` processors to serve a standalone active WordPress application deployment.

> ⚠️ **Evaluation Notice:** The bonus components are strictly conditional and will only be evaluated if the mandatory operating system architecture is completely flawless. Any systemic failure on mandatory specifications results in an automatic score of zero for the bonus segment.

---

## 7. Resources & AI Usage Transparency

### 7.1 Standard References

- [Debian Security Hardening Handbook](https://www.debian.org/doc/manuals/debian-handbook/)
- AppArmor Profile Administration Directives: Ubuntu Security Documentation Core.
- Sudoers Configuration and TTY-forcing Manual Specification Sheets (`man sudoers`).

### 7.2 AI Tools Assistance Disclosure

In compliance with **Chapter III AI Regulations**, artificial intelligence tools were utilized strategically as conceptual learning aids rather than a source of direct answers. AI assisted in deciphering underlying regular expression parsing strings within PAM limits (`/etc/security/pwquality.conf`) and validating logic branches within the Bash script pipelines to safely read multi-layered device identifiers without risking syntax errors.
