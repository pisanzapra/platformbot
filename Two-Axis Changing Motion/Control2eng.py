import serial
import random
import time

# Specify the serial port where Arduino is connected on the Raspberry Pi
# Update this port name based on the port to which Arduino is connected
arduino_port = "/dev/ttyUSB0"
# Start the connection for serial communication
ser = serial.Serial(arduino_port, 9600, timeout=2)

if ser.is_open:
    print("Connection established with Arduino.")
else:
    print("Connection with Arduino failed. Check the port.")
    exit(1)

def send_random_command():
    try:
        time.sleep(1)
        commands = ['F', 'R', 'L']
        random_command = random.choice(commands)
        ser.write(random_command.encode())
        print(f"Sent command: {random_command}")
        time.sleep(5)
    except KeyboardInterrupt:
        # Stop motors when Ctrl+C is pressed
        print("\nCtrl+C detected. Stopping the motors...")
        ser.write('P'.encode())  # Send the stop command to Arduino
        time.sleep(5)
        raise  # Reload KeyboardInterrupt to ensure the program exits gracefully

try:
    print("Program started. Sending random commands. Use Ctrl+C to exit.")
    while True:
        send_random_command()

except KeyboardInterrupt:
    print("Ctrl+C detected. Closing the program...")

finally:
    # Close the serial port
    ser.close()
    print("Serial port closed.")

