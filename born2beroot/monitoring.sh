#!/bin/bash

#architecure of OS and its kernel version
arch=$(uname -a)
printf "#Architecture: $arch\n"

#number of physical processors
cpuif=$(grep "physical id" /proc/cpuinfo | wc -l)
printf "#CPU physical : $cpuif\n"

#number of virtual processors 
vcpu=$(grep "processor" /proc/cpuinfo | wc -l)
printf "#vCPU : $vcpu\n"

#current RAM available and utilization rate (%)
total_ram=$(free --mega | grep Mem | awk '{print $2}')
used_ram=$(free --mega | grep Mem | awk '{print $3}')
percent_ram=$(free --mega | grep Mem | awk '{print $3/$2 * 100}')
printf "#Memory Usage: $used_ram/$total_ram%s (%.2f%%)\n" "MB" $percent_ram

#current storage available and utilization rate (%)
disk_used=$(df -h --block-size=G --total | tail -n 1 | awk '{print $3}' | cut -d G -f1)
disk_total=$(df -h --block-size=G --total | tail -n 1 | awk '{print $2}' | cut -d G -f1)
disk_percent=$(df -h --block-size=G --total | tail -n 1 | awk '{print $3/$2 * 100}' | cut -d % -f1)
printf "#Disk Usage: $disk_used/$disk_total%s (%.2f%%)\n" "Gb" $disk_percent

#current usage rate of processor (%)
cpu_load=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
printf "#CPU load: %.1f%%\n" $cpu_load

#date and time of the last reboot
last_rb=$(who -b | awk '$1=="system"  {print $3" "$4}')
printf "#Last boot: $last_rb\n"

#Is LVM active?
lvm_use=$(if [ ($lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
printf "#LVM use: $lvm_use\n"

#number of active connections
tcp_conn=$(ss -ta | greb "ESTAB" | wc -l)
printf "#Connections TCP : $tcp_conn ESTABLISHED\n"

#number of users using this server
usr_amount=$(users | wc -w)
printf "#User log: $user_log\n"

#IPv4 and MAC address of server
ip=$(ip address | grep enp | grep inet | awk '{print $2}' | cut -d / -f1)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
printf "#Network: IP $ip ($mac)\n"

#number of command excuted with sudo
sudo_count=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
printf "#Sudo : $sudo_count cmd\n"