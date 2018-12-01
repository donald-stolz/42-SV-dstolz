1. Get the list of the network interfaces of the machine without displaying any detail for these interfaces. Only the list of names.

```
ifconfig -l
```

2. Identify and display the Ethernet interface characteristics:  
   &nbsp;&nbsp;&nbsp;&nbsp;a. Indentify broadcast address  
   &nbsp;&nbsp;&nbsp;&nbsp;b. Indentify all IP adresses which are part of the same subnet

```
ipconfig getigaddr en0
```

3. Identify the MAC address of the Wi-Fi card

```
ifconfig en1
```

4. Identifiy the default gateway in the routing table

```
netstat -nr | grep -m1 default
```

5. Identify the IP address of the DNS that responds to the following url: slash16.org

```
nslookup slash16.org
```

6. Get the complete path of the file that contains the IP address of the DNS server you’re using

```
/etc/resolv.conf
```

7. Query an external DNS server on the slash16.org domain name (ie. : google 8.8.8.8)

```
nslookup slash16.org 8.8.8.8
```

8. Find the provider of slash16.org

```
whois slash16.org | grep "Name Server"
```

9. Find the external IP of 42.fr

```
nslookup 42.fr
```

10. Identify the network devices between your computer and the slash16.org domain

```
traceroute slash16.org
```

11. Use the output of the previous command to find the name and IP address of the device that makes the link between you (local network) and the outside world

```

```

12. Find the IP that was assigned to you by dhcp server

```

```

13. Thanks previously answer and DNS sever find your hostname

```

```

14. What file contains the local DNS entries?

```
/etc/hosts
```

15. Make the intra.42.fr address reroute to 46.19.122.85

```
Add '46.19.122.85    intra.42.fr' to /etc/hosts
```
