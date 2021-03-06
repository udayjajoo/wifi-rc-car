import socket

""" Definition """
UDP_IP="169.254.1.1"
UDP_PORT=9761

""" Definition des commandes"""
STOP     		= '\x00'
FORWARD  		= '\x01'
BACKWARD 		= '\x02'
SPEED_UP_ON 	= '\x01'
SPEED_UP_OFF	= '\x00'
SPEED_DOWN_ON 	= '\x01'
SPEED_DOWN_OFF	= '\x00'
DIR_UP_ON 		= '\x01'
DIR_UP_OFF    	= '\x00'
DIR_DOWN_ON 	= '\x01'
DIR_DOWN_OFF    = '\x00'


MESSAGE=FORWARD+SPEED_UP_ON+SPEED_DOWN_OFF+DIR_UP_OFF+DIR_DOWN_OFF

print "UDP target IP : ", UDP_IP
print "UDP target PORT : ", UDP_PORT
print "UDP target Message : ", MESSAGE

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
sock.sendto(MESSAGE,(UDP_IP,UDP_PORT))
