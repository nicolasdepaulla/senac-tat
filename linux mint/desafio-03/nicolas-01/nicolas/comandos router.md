ip ssh version 2
ip ssh authentication-retries 2
no ip domain-lookup
ip domain-name senac.intra
!
!
spanning-tree mode pvst
!
!
!
!
!
!
interface GigabitEthernet0/0
 description interface de gateway da rede lan router rt-1941-1
 ip address 192.168.1.254 255.255.255.0
 duplex auto
 speed auto
!
interface GigabitEthernet0/1
 no ip address
 duplex auto
 speed auto
 shutdown
!
interface Vlan1
 no ip address
 shutdown
!
ip classless
!
ip flow-export version 9
!
!
ip access-list extended sl_def_acl
 deny tcp any any eq telnet
 deny tcp any any eq www
 deny tcp any any eq 22
 permit tcp any any eq 22
!
banner motd ^CAVISO; acesso autorizado somente a funcionarios^C
!
!
!
!
line con 0
 exec-timeout 5 30
 speed 115200
 password 7 08701E1D290A00191308
 logging synchronous
 login local
!
line aux 0
!
line vty 0 4
 password 7 08701E1D290A00191308
 logging synchronous
 login local
 transport input ssh
!
!
!
end


rt-1941-1#show ip inter
rt-1941-1#show ip interface brief
Interface              IP-Address      OK? Method Status                Protocol 
GigabitEthernet0/0     192.168.1.254   YES manual up                    up 
GigabitEthernet0/1     unassigned      YES unset  administratively down down 
Vlan1                  unassigned      YES unset  administratively down down
rt-1941-1#show inter
rt-1941-1#show interface gigabi
rt-1941-1#show interface gigabitEthernet 0/0
GigabitEthernet0/0 is up, line protocol is up (connected)
  Hardware is CN Gigabit Ethernet, address is 0005.5e59.7801 (bia 0005.5e59.7801)
  Description: interface de gateway da rede lan router rt-1941-1
  Internet address is 192.168.1.254/24
  MTU 1500 bytes, BW 1000000 Kbit, DLY 10 usec,
     reliability 255/255, txload 1/255, rxload 1/255
  Encapsulation ARPA, loopback not set
  Keepalive set (10 sec)
  Full-duplex, 100Mb/s, media type is RJ45
  output flow-control is unsupported, input flow-control is unsupported
  ARP type: ARPA, ARP Timeout 04:00:00, 
  Last input 00:00:08, output 00:00:05, output hang never
  Last clearing of "show interface" counters never
  Input queue: 0/75/0 (size/max/drops); Total output drops: 0
  Queueing strategy: fifo
  Output queue :0/40 (size/max)
  5 minute input rate 0 bits/sec, 0 packets/sec
  5 minute output rate 0 bits/sec, 0 packets/sec
     0 packets input, 0 bytes, 0 no buffer
     Received 0 broadcasts, 0 runts, 0 giants, 0 throttles
     0 input errors, 0 CRC, 0 frame, 0 overrun, 0 ignored, 0 abort
     0 watchdog, 1017 multicast, 0 pause input
     0 input packets with dribble condition detected
     0 packets output, 0 bytes, 0 underruns
     0 output errors, 0 collisions, 1 interface resets
     0 unknown protocol drops
     0 babbles, 0 late collision, 0 deferred
     0 lost carrier, 0 no carrier
     0 output buffer failures, 0 output buffers swapped out

rt-1941-1#show ip route
Codes: L - local, C - connected, S - static, R - RIP, M - mobile, B - BGP
       D - EIGRP, EX - EIGRP external, O - OSPF, IA - OSPF inter area
       N1 - OSPF NSSA external type 1, N2 - OSPF NSSA external type 2
       E1 - OSPF external type 1, E2 - OSPF external type 2, E - EGP
       i - IS-IS, L1 - IS-IS level-1, L2 - IS-IS level-2, ia - IS-IS inter area
       * - candidate default, U - per-user static route, o - ODR
       P - periodic downloaded static route

Gateway of last resort is not set

     192.168.1.0/24 is variably subnetted, 2 subnets, 2 masks
C       192.168.1.0/24 is directly connected, GigabitEthernet0/0
L       192.168.1.254/32 is directly connected, GigabitEthernet0/0

rt-1941-1#ping 192.168.1.254

Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 192.168.1.254, timeout is 2 seconds:
!!!!!
Success rate is 100 percent (5/5), round-trip min/avg/max = 1/5/12 ms

rt-1941-1#ping 192.168.1.250

Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 192.168.1.250, timeout is 2 seconds:
..!!!
Success rate is 60 percent (3/5), round-trip min/avg/max = 0/0/0 ms

rt-1941-1#ping 192.168.1.251

Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 192.168.1.251, timeout is 2 seconds:
..!!!
Success rate is 60 percent (3/5), round-trip min/avg/max = 0/0/0 ms

rt-1941-1#ping 192.168.1.10

Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 192.168.1.10, timeout is 2 seconds:
.!!!!
Success rate is 80 percent (4/5), round-trip min/avg/max = 0/2/8 ms

rt-1941-1#ssh -l admin 192.168.1.254

Password: 

AVISO; acesso autorizado somente a funcionarios

rt-1941-1#enable
rt-1941-1#show version
Cisco IOS Software, C1900 Software (C1900-UNIVERSALK9-M), Version 15.1(4)M4, RELEASE SOFTWARE (fc2)
Technical Support: http://www.cisco.com/techsupport
Copyright (c) 1986-2007 by Cisco Systems, Inc.
Compiled Wed 23-Feb-11 14:19 by pt_team

ROM: System Bootstrap, Version 15.1(4)M4, RELEASE SOFTWARE (fc1)
cisco1941 uptime is 21 minutes, 31 seconds
System returned to ROM by power-on
System image file is "flash0:c1900-universalk9-mz.SPA.151-1.M4.bin"
Last reload type: Normal Reload

This product contains cryptographic features and is subject to United
States and local country laws governing import, export, transfer and
use. Delivery of Cisco cryptographic products does not imply
third-party authority to import, export, distribute or use encryption.
Importers, exporters, distributors and users are responsible for
compliance with U.S. and local country laws. By using this product you
agree to comply with applicable laws and regulations. If you are unable
to comply with U.S. and local laws, return this product immediately.

A summary of U.S. laws governing Cisco cryptographic products may be found at:
http://www.cisco.com/wwl/export/crypto/tool/stqrg.html

If you require further assistance please contact us by sending email to
export@cisco.com.
Cisco CISCO1941/K9 (revision 1.0) with 491520K/32768K bytes of memory.
Processor board ID FTX152400KS
2 Gigabit Ethernet interfaces
DRAM configuration is 64 bits wide with parity disabled.
255K bytes of non-volatile configuration memory.
249856K bytes of ATA System CompactFlash 0 (Read/Write)

License Info:

License UDI:

-------------------------------------------------
Device#   PID                   SN
-------------------------------------------------
*0        CISCO1941/K9          FTX1524VB84-


Technology Package License Information for Module:'c1900'

----------------------------------------------------------------
Technology    Technology-package          Technology-package
              Current       Type          Next reboot
-----------------------------------------------------------------
ipbase        ipbasek9      Permanent     ipbasek9
security      None          None          None
data          None          None          None

Configuration register is 0x2102


rt-1941-1#show boot
               ^
% Invalid input detected at '^' marker.
	
rt-1941-1#show boot
               ^
% Invalid input detected at '^' marker.
	
rt-1941-1#show bo
rt-1941-1#show boo
rt-1941-1#show boot 
               ^
% Invalid input detected at '^' marker.
	
rt-1941-1#showboot 
Translating "showboot"
% Unknown command or computer name, or unable to find computer address

rt-1941-1#show-boot 
Translating "show-boot"
% Unknown command or computer name, or unable to find computer address

rt-1941-1#show version
Cisco IOS Software, C1900 Software (C1900-UNIVERSALK9-M), Version 15.1(4)M4, RELEASE SOFTWARE (fc2)
Technical Support: http://www.cisco.com/techsupport
Copyright (c) 1986-2007 by Cisco Systems, Inc.
Compiled Wed 23-Feb-11 14:19 by pt_team

ROM: System Bootstrap, Version 15.1(4)M4, RELEASE SOFTWARE (fc1)
cisco1941 uptime is 22 minutes, 45 seconds
System returned to ROM by power-on
System image file is "flash0:c1900-universalk9-mz.SPA.151-1.M4.bin"
Last reload type: Normal Reload

This product contains cryptographic features and is subject to United
States and local country laws governing import, export, transfer and
use. Delivery of Cisco cryptographic products does not imply
third-party authority to import, export, distribute or use encryption.
Importers, exporters, distributors and users are responsible for
compliance with U.S. and local country laws. By using this product you
agree to comply with applicable laws and regulations. If you are unable
to comply with U.S. and local laws, return this product immediately.

A summary of U.S. laws governing Cisco cryptographic products may be found at:
http://www.cisco.com/wwl/export/crypto/tool/stqrg.html

If you require further assistance please contact us by sending email to
export@cisco.com.
Cisco CISCO1941/K9 (revision 1.0) with 491520K/32768K bytes of memory.
Processor board ID FTX152400KS
2 Gigabit Ethernet interfaces
DRAM configuration is 64 bits wide with parity disabled.
255K bytes of non-volatile configuration memory.
249856K bytes of ATA System CompactFlash 0 (Read/Write)

License Info:

License UDI:

-------------------------------------------------
Device#   PID                   SN
-------------------------------------------------
*0        CISCO1941/K9          FTX1524VB84-


Technology Package License Information for Module:'c1900'

----------------------------------------------------------------
Technology    Technology-package          Technology-package
              Current       Type          Next reboot
-----------------------------------------------------------------
ipbase        ipbasek9      Permanent     ipbasek9
security      None          None          None
data          None          None          None

Configuration register is 0x2102


rt-1941-1#
rt-1941-1#
rt-1941-1#
rt-1941-1#
rt-1941-1#
rt-1941-1#
rt-1941-1#ping 192.168.1.1

Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 192.168.1.1, timeout is 2 seconds:
.!!!!
Success rate is 80 percent (4/5), round-trip min/avg/max = 0/0/0 ms

rt-1941-1#copy star
rt-1941-1#copy startup-config tftp
Address or name of remote host []? 192.168.1.1
Destination filename [rt-1941-1-confg]? 

Writing startup-config...!!
[OK - 1455 bytes]

1455 bytes copied in 0 secs
rt-1941-1#192.168.1.254
Trying 192.168.1.254 ...Open

[Connection to 192.168.1.254 closed by foreign host]
rt-1941-1#192.168.1.1
Trying 192.168.1.1 ...
% Connection refused by remote host
rt-1941-1#show runnin
rt-1941-1#show running-config 
Building configuration...

Current configuration : 1455 bytes
!
version 15.1
service timestamps log datetime msec
service timestamps debug datetime msec
service password-encryption
security passwords min-length 8
!
hostname rt-1941-1
!
login block-for 120 attempts 2 within 60
!
!
enable secret 5 $1$mERr$3O.pM7PScAETpkhlqaEiE.
!
!
!
!
!
!
ip cef
no ipv6 cef
!
!
!
username admin privilege 15 password 7 08701E1D290A00191308
username depaula secret 5 $1$mERr$3O.pM7PScAETpkhlqaEiE.
username nicolas secret 5 $1$mERr$3O.pM7PScAETpkhlqaEiE.
!
!
license udi pid CISCO1941/K9 sn FTX1524VB84-
!
!
!
!
!
!
!
!
!
ip ssh version 2
ip ssh authentication-retries 2
no ip domain-lookup
ip domain-name senac.intra
!
!
spanning-tree mode pvst
!
!
!
!
!
!
interface GigabitEthernet0/0
 description interface de gateway da rede lan router rt-1941-1
 ip address 192.168.1.254 255.255.255.0
 duplex auto
 speed auto
!
interface GigabitEthernet0/1
 no ip address
 duplex auto
 speed auto
 shutdown
!
interface Vlan1
 no ip address
 shutdown
!
ip classless
!
ip flow-export version 9
!
!
ip access-list extended sl_def_acl
 deny tcp any any eq telnet
 deny tcp any any eq www
 deny tcp any any eq 22
 permit tcp any any eq 22
!
banner motd ^CAVISO; acesso autorizado somente a funcionarios^C
!
!
!
!
line con 0
 exec-timeout 5 30
 speed 115200
 password 7 08701E1D290A00191308
 logging synchronous
 login local
!
line aux 0
!
line vty 0 4
 password 7 08701E1D290A00191308
 logging synchronous
 login local
 transport input ssh
!
!
!
end


rt-1941-1#
rt-1941-1#
rt-1941-1#
rt-1941-1#ssh -l admin 192.168.1.254

Password: 

AVISO; acesso autorizado somente a funcionarios

rt-1941-1#show fla
rt-1941-1#show flash: 

System flash directory:
File  Length   Name/status
  3   33591768 c1900-universalk9-mz.SPA.151-4.M4.bin
  2   28282    sigdef-category.xml
  1   227537   sigdef-default.xml
[33847587 bytes used, 221896413 available, 255744000 total]
249856K bytes of processor board System flash (Read/Write)


rt-1941-1#copy running-
rt-1941-1#copy running-config star
rt-1941-1#copy running-config startup-config 
Destination filename [startup-config]? 
Building configuration...
[OK]
rt-1941-1#star
rt-1941-1#startup-con
rt-1941-1#startup-config flash
                         ^
% Invalid input detected at '^' marker.
	
rt-1941-1#startup-config flash
                         ^
% Invalid input detected at '^' marker.
	
rt-1941-1#startup-config fla
rt-1941-1#startup-config flash
                         ^
% Invalid input detected at '^' marker.
	
rt-1941-1#copy star
rt-1941-1#copy startup-config flash
Destination filename [startup-config]? 

1455 bytes copied in 0.416 secs (3497 bytes/sec)
rt-1941-1#show fla
rt-1941-1#show flash: 

System flash directory:
File  Length   Name/status
  3   33591768 c1900-universalk9-mz.SPA.151-4.M4.bin
  2   28282    sigdef-category.xml
  1   227537   sigdef-default.xml
  4   1455     startup-config
[33849042 bytes used, 221894958 available, 255744000 total]
249856K bytes of processor board System flash (Read/Write)


rt-1941-1#ping 192.168.1.1

Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 192.168.1.1, timeout is 2 seconds:
!!!!!
Success rate is 100 percent (5/5), round-trip min/avg/max = 0/4/21 ms

rt-1941-1#copy star
rt-1941-1#copy startup-config tftp
Address or name of remote host []? 192.168.1.1
Destination filename [rt-1941-1-confg]? 

Writing startup-config...!!
[OK - 1455 bytes]

1455 bytes copied in 0 secs
rt-1941-1#show runnin
rt-1941-1#show running-config 
Building configuration...

Current configuration : 1455 bytes
!
version 15.1
service timestamps log datetime msec
service timestamps debug datetime msec
service password-encryption
security passwords min-length 8
!
hostname rt-1941-1
!
login block-for 120 attempts 2 within 60
!
!
enable secret 5 $1$mERr$3O.pM7PScAETpkhlqaEiE.
!
!
!
!
!
!
ip cef
no ipv6 cef
!
!
!
username admin privilege 15 password 7 08701E1D290A00191308
username depaula secret 5 $1$mERr$3O.pM7PScAETpkhlqaEiE.
username nicolas secret 5 $1$mERr$3O.pM7PScAETpkhlqaEiE.
!
!
license udi pid CISCO1941/K9 sn FTX1524VB84-
!
!
!
!
!
!
!
!
!
ip ssh version 2
ip ssh authentication-retries 2
no ip domain-lookup
ip domain-name senac.intra
!
!
spanning-tree mode pvst
!
!
!
!
!
!
interface GigabitEthernet0/0
 description interface de gateway da rede lan router rt-1941-1
 ip address 192.168.1.254 255.255.255.0
 duplex auto
 speed auto
!
interface GigabitEthernet0/1
 no ip address
 duplex auto
 speed auto
 shutdown
!
interface Vlan1
 no ip address
 shutdown
!
ip classless
!
ip flow-export version 9
!
!
ip access-list extended sl_def_acl
 deny tcp any any eq telnet
 deny tcp any any eq www
 deny tcp any any eq 22
 permit tcp any any eq 22
!
banner motd ^CAVISO; acesso autorizado somente a funcionarios^C
!
!
!
!
line con 0
 exec-timeout 5 30
 speed 115200
 password 7 08701E1D290A00191308
 logging synchronous
 login local
!
line aux 0
!
line vty 0 4
 password 7 08701E1D290A00191308
 logging synchronous
 login local
 transport input ssh
!
!
!
end