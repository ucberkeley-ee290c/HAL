import serial

ser = serial.Serial(port="/dev/ttyUSB1", baudrate=115200)

while True:
    print(ser.read())
