#!/bin/bash

# Define the IP address for connectivity check
TARGET_IP="8.8.8.8"  # Google's public DNS server
INTERFACE="Ethernet"  # Change this to your network interface name (as seen in `ipconfig`)

echo "Network Health Check"

# Check if the network interface is up
echo -e "\nChecking network interface status..."
if ipconfig | grep -A 10 "$INTERFACE" | grep "Media disconnected" > /dev/null
then
    echo "$INTERFACE is down."
    exit 1
else
    echo "$INTERFACE is up."
fi

# Ping the target IP to check connectivity
echo -e "\nPinging $TARGET_IP to check connectivity..."
ping -n 4 $TARGET_IP > /dev/null
if [ $? -eq 0 ]
then
    echo "Connectivity to $TARGET_IP is OK."
else
    echo "Failed to connect to $TARGET_IP."
    exit 1
fi

# Check the network speed using `speedtest-cli`
echo -e "\nChecking network speed..."
if command -v speedtest-cli > /dev/null
then
    speedtest-cli --simple
else
    echo "speedtest-cli is not installed. Installing..."
    pip install speedtest-cli
    speedtest-cli --simple
fi

echo -e "\nNetwork health check completed."
