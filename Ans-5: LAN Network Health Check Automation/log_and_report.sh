#!/bin/bash

# Define file names
log_file="network_log.txt"
summary_file="network_summary.txt"

# Clear previous log files
> $log_file
> $summary_file

echo "Starting Network Analysis..." | tee -a $log_file

# Task 1: Port Scan on LAN
echo -e "\nTask 1: Port Scan on LAN" | tee -a $log_file
nmap -sP 192.168.1.x/24 > network_scan_results.txt
nmap -p 1-65535 192.168.1.x/24 > open_ports_results.txt
echo -e "Network scan and open ports results saved.\n" | tee -a $log_file

# Task 2: Network Health Check
echo -e "\nTask 2: Network Health Check" | tee -a $log_file
chmod +x network_health_check.sh
./network_health_check.sh > network_health_report.txt
cat network_health_report.txt | tee -a $log_file
echo -e "Network health check completed.\n" | tee -a $log_file

# Task 3: Host Availability Check
echo -e "\nTask 3: Host Availability Check" | tee -a $log_file
chmod +x host_check.sh
./host_check.sh > host_availability_output.txt
cat host_availability_output.txt | tee -a $log_file
echo -e "Host availability check completed.\n" | tee -a $log_file

# Task 4: Network Latency Test
echo -e "\nTask 4: Network Latency Test" | tee -a $log_file
python traceroute_script.py > traceroute_results.txt
cat traceroute_results.txt | tee -a $log_file
echo -e "Network latency test completed.\n" | tee -a $log_file

# Generate Summary Report
echo -e "\nGenerating Summary Report..." | tee -a $log_file

reachable_hosts=$(grep -c "reachable" host_availability_output.txt)
total_hosts=$(wc -l < hosts.txt)
open_ports=$(grep -c "open" open_ports_results.txt)
total_ports=$(grep -oP '\d+(?=/tcp)' open_ports_results.txt | wc -l)

echo -e "\nNetwork Summary Report:" | tee -a $summary_file
echo -e "Total Hosts Checked: $total_hosts" | tee -a $summary_file
echo -e "Reachable Hosts: $reachable_hosts" | tee -a $summary_file
echo -e "Open Ports Detected: $open_ports" | tee -a $summary_file
echo -e "Network Latency: See traceroute results\n" | tee -a $summary_file

# Append summary to log file
cat $summary_file | tee -a $log_file

echo "Network analysis completed. Full details are available in $log_file and summary in $summary_file."
