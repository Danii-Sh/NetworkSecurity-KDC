
 
import socket   #for sockets
import sys  #for exit
import time


 
try:
    #create an AF_INET, STREAM socket (TCP)
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)      #icmp ::    s = socket.socket(socket.AF_INET, socket.SOCK_RAW , socket.getprotobyname("icmp"))
except socket.error as msg:
    print ('Failed to create socket. Error code: ' + str(msg[0]) + ' , Error message : ' + msg[1])
    sys.exit();
 
print ('Socket Created')


###########     part 2 : DNS resolve and connect#############



host = 'google.com'
port = 80    # https : 443 , http 80 
 
try:
    remote_ip = socket.gethostbyname( host )
    print (type(remote_ip),remote_ip)
 
except socket.gaierror:
    #could not resolve
    print ('Hostname could not be resolved. Exiting')
    sys.exit()
     
print ('Ip address of ' + host + ' is ' + remote_ip)
 
#Connect to remote server
s.connect((remote_ip  , port))      # another example : s.connect(('172.217.18.68'  , 80))


 
print ('Socket Connected to ' + host + ' on ip ' + remote_ip)




###########     part 3 : some useful methodes for manipulation and reading info#############

#s.setsockopt(socket.SOL_IP,  socket.IP_TTL , 50)     ## tanzime optionhaye socket
#print (s.getsockopt(socket.SOL_IP, socket.IP_TTL))   ## khundane optionhaye socket
#print ( socket.getprotobyname('icmp'))               ## tabdile esmhaye reserve be codehaye ghabele tashkhishe lib socket

s.setsockopt(socket.SOL_IP,  socket.IP_TTL , 5)
s.settimeout(2)

#Send some data to remote server
message = 'GET / HTTP/1.1\r\n\r\n'.encode()

try :
    #Set the whole string
    s.send(message)
except socket.error:
    #Send failed
    print ('Send failed')
    sys.exit()
 
print ('Message sent successfully')
start_time = time.time()
 

#s.setsockopt(socket.SOL_IP,  socket.IP_TTL , 2)



try:
	_, curr_addr = s.recvfrom(0)
	finished = True
	try:
		curr_name = socket.gethostbyaddr(str(curr_addr))
	except socket.error:
		curr_name = curr_addr
except socket.error as msg:     # socket.error : an alias for main OS error class, has some subclasses like socket.timeout or ... - meaning general error class
	print("*   error is "+ str(msg))  #difference between repr and str





#Now receive data
try:
	reply = s.recv(4096)   #number = buffer size
	print("from send to rcv :  %s miliseconds " % ((time.time() - start_time)*1000))
	print (reply.decode())
except socket.error as msg:    # ...error as x means capture error message and maybe use it later for printing or ...
	print("*   error is '"+ str(msg)+"'")
	print(msg)
	print(type(msg))
	if msg=='timed out\r\n':
		print('timeout detected')
	print("from send to rcv error:  %s miliseconds " % ((time.time() - start_time)*1000))
#print('###############')
#print (reply)












