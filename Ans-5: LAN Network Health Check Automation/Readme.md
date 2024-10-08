### Task-1: Port Scan on LAN
After installing [nmap](https://nmap.org/), windows powershell bash ommand to scan your network:
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
The masked scan results are [network_scan_results.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/fbf4aad80d1048c10ca72f04d67080a5e6f815ba/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_scan_results.txt) and [open_ports_results.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/7779e046685da1b8908d2dfe73697c2a37bbc689/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/open_ports_results.txt)
### Task-2: Network Health Check Bash Script
Open git bash and navigate to your desired directory using ```cd``` command. Install ```speedtest-cli``` if not installed.

To automate checking various aspects of network health and performance, run the [network_health_check.sh](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/65d508d61cee2266a86fb2997f5734f280b9ff3b/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_health_check.sh) bash file in git bash:
```bash
chmod +x network_health_check.sh
./network_health_check.sh
```
To run the above file and also save the results to a file:
```bash
./network_health_check.sh > network_health_report.txt
```
The output file is [network_health_report.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/e3810234723c5f15ced072f0303d68d0f8ec2477/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_health_report.txt)
### Task-3: Host Availability Check
After ensuring that ICMP (ping) requests are enabled on the public network, navigate to the directory (using ```cd``` command) where the [host_check.sh](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/bbdd948b65054f574384c06854a78d68f4fa5cf8/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/host_check.sh) bash file and the [hosts.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/bbdd948b65054f574384c06854a78d68f4fa5cf8/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/hosts.txt) file are saved

Make the bash script executable and run it on git bash:
```bash
chmod +x host_check.sh
./host_check.sh
```
To save the output to a text file, run the script as follows:
```bash
./host_check.sh > host_availability_output.txt
```
The output file is [host_availability_output.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/bbdd948b65054f574384c06854a78d68f4fa5cf8/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/host_availability_output.txt)
### Task-4: Network Latency Test
In windows powershell, navigate to your desired directory using ```cd``` command.

Run the python script [traceroute_script.py](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/260f22b0341790c43f31bef31be66df24210b724/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/traceroute_script.py):
```bash
python traceroute_script.py
```
The results will be saved in a text file [traceroute_results.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/260f22b0341790c43f31bef31be66df24210b724/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/traceroute_results.txt)
### Task-5: Logging and Reporting
In git bash, navigate to your desired directory using ```cd``` command.

Make the bash script [log_and_report.sh](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/e18f3d92aeb870f930cea81c822449acaabc3d73/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/log_and_report.sh) executable and run it:
```bash
chmod +x log_and_report.sh
./log_and_report.sh
```
A log file [network_log.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/e18f3d92aeb870f930cea81c822449acaabc3d73/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_log.txt) and a summary report [network_summary.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/e18f3d92aeb870f930cea81c822449acaabc3d73/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_summary.txt) will be generated.

Other result files will be saved as mentioned in the [network_log.txt](https://github.com/atharva-mohite/Assignment-ML_Level-1/blob/e18f3d92aeb870f930cea81c822449acaabc3d73/Ans-5%3A%20LAN%20Network%20Health%20Check%20Automation/network_log.txt) file.
