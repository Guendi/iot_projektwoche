#!/usr/bin/env python3
#author: sven

#reads RFID ids from serial port, 
#logs them with timestamp on console and file

import serial #requires pyserial 
import io, os
import datetime

class rfid_card:
    rfid = ""
    last_fail_login = None
    counter_login_fails = 0
    pin = ""
    
    def __init__(self,rfid, pin):
        self.rfid = rfid
        self.pin = pin
        self.last_fail_login=datetime.datetime(2000,1,1,0,0)
        
    def provePin(self,pin):
        acc_blocked = False;
        # wait time after account got blocked + too much failed logins already
        if (self.last_fail_login - datetime.datetime.now()).seconds/60 < 5 and self.counter_login_fails > 2:
            acc_blocked = True
            
        if not(acc_blocked) and self.pin==pin:
            self.last_fail_login = datetime.datetime(2000,1,1,0,0)
            self.counter_login_fails = 0
            return True

        #for any failed login, update stats
        self.counter_login_fails += 1
        self.last_fail_login = datetime.datetime.now()
        if self.counter_login_fails > 2:
            return "card locked"
        
        return "fail"
    

class access_server:
    log=[]
    ports = ['/dev/ttyACM0','/dev/ttyACM1','/dev/ttyACM2']
    ard = None # serial port
    sio = None # buffered reader/writer
    rfid_cards = [rfid_card('71 85 C5 75','001'), rfid_card('15 17 5 6D','002') ]
    

    def isInList(self,uid):
        result = len([x[1] for x in self.log if uid == x[1]])>0
        print(uid+' is in list: '+str(result))
        print(self.log)
        return result        
        
    def checkLogin(self,rfid,pin):
        x = [x for x in self.rfid_cards if x.rfid==rfid]
        if len(x):
            card = x[0]
            return card.provePin(pin)
            
        return "Invalid card"

    def init(self):
        result = False
        for port in self.ports:
            try:
                self.ard = serial.Serial(port,115200,timeout=5)
                print(port+" valid, moving on")
                self.sio = io.TextIOWrapper(io.BufferedRWPair(self.ard, self.ard))
                result = True;
                break;
            except:
                print(port+" invalid")
        return result

    def serve(self):
        with open('rfid_data','w') as fil:
            try:
                while True:
                    #try to do proper length now
                    msg = self.sio.readline()
                    #str_msg = msg.decode();#byte to string conversion
                    if len(msg)>1:
                        print("rcv: "+msg)
                    if msg.strip()=="Login request":
                        print('inside... '+msg)
                        rfid = self.sio.readline().strip()
                        pin = self.sio.readline().strip()
                        print("login: "+rfid+"::"+pin)
                        retVal = self.checkLogin(rfid,pin)
                        if retVal==True:
                            print('login ok')
                            self.ard.write(b'OK \n')
                            fil.write("GRANT;"+rfid+";"+str(datetime.datetime.now())+";"+"\n")
                        else:
                            print('login nok:'+retVal)
                            self.ard.write(str.encode(retVal+'\n'))
                            fil.write("DENY;"+rfid+";"+str(datetime.datetime.now())+";"+retVal+"\n")
            
            except Exception as ex:
                print(ex)
                self.ard.close()

if __name__=="__main__":
    server = access_server();
    if server.init()==True:
        server.serve();
    else:
        print('Please connect/troubleshoot Arduino :-)')