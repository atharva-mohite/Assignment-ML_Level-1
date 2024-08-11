#!/bin/bash

# Host Availability Check Script

echo "Host Availability Check"

# Read hosts from the hosts.txt file
while IFS= read -r host
do
  echo -e "\nPinging $host..."
  
  # Ping the host (4 packets)
  if ping -c 4 "$host" &> /dev/null
  then
    echo "$host is reachable."
  else
    echo "$host is not reachable."
  fi
done < hosts.txt

echo -e "\nHost availability check completed."