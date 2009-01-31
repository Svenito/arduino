#!/Library/Frameworks/Python.framework/Versions/Current/bin/python
import serial, sys, twitter, time, getopt

try:
    opts, args = getopt.getopt(sys.argv[1:], "u:p:", ["username=", "password="])
except getopt.GetoptError, err:
    print str(err);
    sys.exit(2);

for o, a in opts:
    print o;
    if (o == "-u", "--username"):
        user = a
    elif (o == "-p", "--password"):
        passwd = a
    else:
        assert False, "Unhandled option"


api = twitter.Api(username=user, password=passwd)

SERIALPORT = "/dev/tty.usbserial-A7007bFO" 

LEAVING = 1
ENTERING = 0

cats_in_house = 2

# Set up serial port
try:
	ser = serial.Serial(SERIALPORT, 9600)
except serial.SerialException:
	print "no device connected - exiting"
	sys.exit()
count = 0;
while (1):
    val = ser.read()
    if val == '1':
        print "inner flap open."
        cat_status = LEAVING;
        cats_in_house = cats_in_house - 1;
#        post_status = api.PostUpdate("Cat leaving house. There are now "+str(cats_in_house)+" cats in the house");
#        print post_status.text;
    
    if val == '2':
        print "outer flap open.";
        cat_status = ENTERING;
        cats_in_house = cats_in_house + 1;
        #post_status = api.PostUpdate("Cat flapused house. There are now "+str(cats_in_house)+" cats in the house");
        post_status = api.PostUpdate("Cat flap used "+str(count)+" times today");
        print post_status.text;
        count = count + 1;

    time.sleep(3); 

# Close serial port
ser.close()
 
