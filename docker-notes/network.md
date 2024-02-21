# Network: 

- The concept is that using `network` two separately running containers can interact with one another.

For example, if you have a server called `backend` running, and you want it to interact with the database's container (called, say, `mongodb1`), you can simulate interaction using `docker network`.

## Steps: 

1. Create a network using: 
```sh 
➜ docker network create <network_name>
```

Example: 
```sh 
➜ docker network create network1
```

2. Restart docker containers by specifying the network they're running in: 
For `backend` container: 
```sh 
➜ docker run -p 3000:3000 --network network1 --name backend test_img

```
For `mongodb1` container: 
```sh
➜ docker run -p 27017:27017 --network network1 --name mongodb1 mongo 
```

3. Find out IP Addresses of the containers: 
```sh
➜ docker inspect -f '{{range .NetworkSettings.Network}}{{.IPAddress}}{{end}}' <container_name>
```

So, in our example ->
For `backend` container: 
```sh 
➜ docker inspect -f '{{range .NetworkSettings.Network}}{{.IPAddress}}{{end}}' backend 
172.19.0.2 
```

For `mongodb1` container: 
```sh 
➜ docker inspect -f '{{range .NetworkSettings.Network}}{{.IPAddress}}{{end}}' mongodb1
172.19.0.3
```

4. Try pinging one container from another: 

*Disclaimer:* I could be wrong but when I tried pinging using mac directly, it showed `100% packet loss`. I think that could be because my host machine (mac) wasn't there on the network the two containers were communicating on. So, as a workaround, I followed the following steps: 

  a) Opened `backend` container's shell: 
```sh 
➜ docker exec -it backend bash
root@ffddc39c7a7d:/usr/src/app# hostname
ffddc39c7a7d
```
0 kB/s)
debconf: delaying package configuration, since apt-utils is not installed
Selecting previously unselected package libcap2-bin.
(Reading database ... 23259 files and directories currently installed.)
Preparing to unpack .../libcap2-bin_1%3a2.66-4_amd64.deb ...
Unpacking libcap2-bin (1:2.66-4) ...
Selecting previously unselected package iputils-ping.
Preparing to unpack .../iputils-ping_3%3a20221126-1_amd64.deb ...
Unpacking iputils-ping (3:20221126-1) ...
Selecting previously unselected package libpam-cap:amd64.
Preparing to unpack .../libpam-cap_1%3a2.66-4_amd64.deb ...
Unpacking libpam-cap:amd64 (1:2.66-4) ...
Setting up libcap2-bin (1:2.66-4) ...
Setting up libpam-cap:amd64 (1:2.66-4) ...
debconf: unable to initialize frontend: Dialog
debconf: (No usable dialog-like program is installed, so the dialog based frontend cannot be used. at /usr/share/perl5/Debconf/FrontEnd/Dialog.pm line 78.)
debconf: falling back to frontend: Readline
Setting up iputils-ping (3:20221126-1) ...
  b) `apt update`
```sh 
root@ffddc39c7a7d:/usr/src/app# apt update
```

  c) Installed `ping` 
```sh
root@ffddc39c7a7d:/usr/src/app# apt install iputils-ping

Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
The following additional packages will be installed:
  libcap2-bin libpam-cap
The following NEW packages will be installed:
  iputils-ping libcap2-bin libpam-cap
0 upgraded, 3 newly installed, 0 to remove and 2 not upgraded.
Need to get 96.2 kB of archives.
After this operation, 311 kB of additional disk space will be used.
Do you want to continue? [Y/n] Y
Get:1 http://deb.debian.org/debian bookworm/main amd64 libcap2-bin amd64 1:2.66-4 [34.7 kB]
Get:2 http://deb.debian.org/debian bookworm/main amd64 iputils-ping amd64 3:20221126-1 [47.1 kB]
Get:3 http://deb.debian.org/debian bookworm/main amd64 libpam-cap amd64 1:2.66-4 [14.5 kB]
Fetched 96.2 kB in 0s (108
```

  d) Used ping and voila! 
```sh 
root@ffddc39c7a7d:/usr/src/app# ping 172.19.0.3

PING 172.19.0.3 (172.19.0.3) 56(84) bytes of data.
64 bytes from 172.19.0.3: icmp_seq=1 ttl=64 time=0.065 ms
64 bytes from 172.19.0.3: icmp_seq=2 ttl=64 time=0.062 ms
64 bytes from 172.19.0.3: icmp_seq=3 ttl=64 time=0.081 ms
^C
--- 172.19.0.3 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 2037ms
rtt min/avg/max/mdev = 0.062/0.069/0.081/0.008 ms
```

:)
