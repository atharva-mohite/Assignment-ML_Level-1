### Task-1:
Windows Powershell bash ommand to scan your network:
```bash
nmap -sP 192.168.1.x/24
```
To check open ports on each detected host:
```bash
nmap -p 1-65535 192.168.1.x/24
```
To save the scan results to a file:
```bash
nmap -sP 192.168.1.x/24 > network_scan_results.txt
nmap -p 1-65535 192.168.1.x/24 > open_ports_results.txt
```
The masked scan results are [network_scan_results.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/fbf4aad80d1048c10ca72f04d67080a5e6f815ba/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_scan_results.txt) and [open_ports_results.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/70cbf0416a220e673b5423132fbc58bd0a30dfb9/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_scan_results.txt)
### Task-2:
