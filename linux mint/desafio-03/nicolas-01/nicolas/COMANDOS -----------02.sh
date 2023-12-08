COMANDOS ----------
enable
disable
=====================
configuração de data e hora do switch
clock set 14:18:00 14 august 2023
configure terminal
hostname sw-l2-2960-1
service password-encryption
service timestamps log datetime msec
no ip domain-lookup
banner motd #AVISO; acesso autorizado somente para funcionarios#
enable secret 123@senac
end
copy running-config startup-config
username senac secret 123@senac
line console 0 
login local 
password 123@senac
logging synchronous
exec-timeout 5 30
end
enable
configure terminal
line vty 0 4 
login local 
password 123@senac 
logging synchronous 
exec-timeout 5 30 
transport input all 
end 
write
"até agora a linha vty não serve pra NADA"
o que é ethernet?10 mps/sec 
R-protocolo de rede/switch
o que é fast ethernet?100 mps/sec
R-é a conexão que pode ser chamada de 10/100
o que é gigabite ethernet? tudo que for maior que 1000mps/sec
R-é uma conexão com suporte para velocidades mais rápidas de dados
===================================================================
enable
show running-config 
-=====================
enable 
configure terminal
ip default-gateway 192.168.1.254
interface vlan 1 
description interface de service
ip address 192.168.1.250 255.255.255.0
no shutdown 
end
write
-------------------
show running-config
show ip interface brief
============================
enable 
configure terminal
ip domain-name senac.intra 
crypto key generate rsa general-keys modulus 1024
ip ssh version 2 
ip ssh time-out 60
ip ssh authentication-retries 2
line vty 0 4 
transport input ssh 
end 
write
=================================
enable
clock set 14:28:00 18 august 2023 
configure terminal
hostname rt-1941-1
service password-encryption
service timestamps log datetime msec
service timestamps debug datetime msec
no ip domain-lookup 
banner motd #AVISO; acesso autorizado somente a funcionarios#
security password min-length 8
enable secret 123@senac
username nicolas secret 123@senac
username de paula secret 123@senac
username admin privilege 15 password 123@senac 
ip domain-name senac.intra 
crypto key generate rsa general-keys modulus 1024
ip ssh version 2 
ip ssh time-out 60
ip ssh authentication-retries 2 
login block-for 120 attempts 2 within 60
line console 0 
login local 
password 123@senac
logging synchronous
exec-timeout 5 30 
exit 
login local
password 123@senac
logging synchronous
exec-timeout 5 30 
speed 115200
flowcontrol hardware
exit 
line vty 0 4 
login local 
password 123@senac
logging synchronous
exec time-out 5 30 
transport input ssh 
end
write 
show running-config
show line

-l admin 192.168.1.254