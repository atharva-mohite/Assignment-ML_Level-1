import subprocess
import re

def traceroute(host):
    try:
        # Run the traceroute command
        result = subprocess.run(['tracert', host], capture_output=True, text=True)
        output = result.stdout

        # Parse the output to count the number of hops and total time
        hops = len(re.findall(r'\d+ ms', output))
        total_time = sum([int(time.split()[0]) for time in re.findall(r'(\d+) ms', output)])

        return hops, total_time
    except Exception as e:
        print(f"Error performing traceroute to {host}: {e}")
        return None, None

def main():
    try:
        with open('hosts.txt', 'r') as file:
            hosts = file.readlines()

        with open('traceroute_results.txt', 'w') as output_file:
            for host in hosts:
                host = host.strip()
                if host:
                    hops, total_time = traceroute(host)
                    if hops is not None:
                        output_file.write(f"{host}: {hops} hops, {total_time} ms total time\n")
                        print(f"Traceroute to {host}: {hops} hops, {total_time} ms total time")
                    else:
                        output_file.write(f"{host}: Traceroute failed\n")
                        print(f"Traceroute to {host} failed.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
