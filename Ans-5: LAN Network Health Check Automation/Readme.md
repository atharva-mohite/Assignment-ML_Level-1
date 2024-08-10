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
