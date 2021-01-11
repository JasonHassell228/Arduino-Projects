import serial
from serial.tools import list_ports
import sys
import glob
import pynput
from pynput.keyboard import Key, Controller
import time
import pyvjoy

keyboard = Controller()
portNum = 5



def serial_ports():
    """ Lists serial port names

        :raises EnvironmentError:
            On unsupported or unknown platforms
        :returns:
            A list of the serial ports available on the system
    """
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result

ports = serial_ports()
print(ports)

port = serial.Serial(port=ports[0], baudrate=9600, bytesize=8, timeout=None, stopbits=serial.STOPBITS_ONE)

port.ReadTimeout = 500
port.WriteTimeout = 500

while (True):
    line = port.readline()
    line = line.decode('utf-8')
    split = line.split()

    chr1 = split[0]
    turnAxis = split[1]

    if chr1 == 'f':
        #forward
        keyboard.release("s")
        keyboard.press("w")
    elif chr1 == 'b':
        #back
        keyboard.release("w")
        keyboard.press("s")
    else:
        #stop
        keyboard.release("w")
        keyboard.release("s")
        
    j = pyvjoy.VJoyDevice(1)
    j.data.wAxisX = int(turnAxis) #0x2000
    #j.set_axis(pyvjoy.HID_USAGE_X, 0x1)#turnAxis)

    print(chr1, turnAxis)
    """ - Old turning
    if chr2 == 'l':
        #left
        keyboard.release("d")
        keyboard.press("a")
    elif chr2 == 'r':
        #right
        keyboard.release("a")
        keyboard.press("d")
    else:
        #straight
        keyboard.release("a")
        keyboard.release("d")
    """
