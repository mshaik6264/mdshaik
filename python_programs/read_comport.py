import serial

# Open the COM port
ser = serial.Serial('COM3', 9600, timeout=1)  # Replace 'COM3' with your actual port

# Read data in a loop
try:
    while True:
        if ser.in_waiting > 0:
            data = ser.readline().decode('utf-8').strip()
            print(f"Received: {data}")
except KeyboardInterrupt:
    print("Stopped by user.")
finally:
    ser.close()

