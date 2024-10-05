import serial
import time
import subprocess

# Use the correct COM port (COM12)
ser = serial.Serial('COM12', 9600, timeout=1)
time.sleep(2)

def run_python_script():
    print("Running Python script...")
    # Replace with the correct path to your Python script
    subprocess.run(["python", "D:\\kpr\\Emotion-Dection-main\\Emotion-Dection-main\\main.py"])

try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(f"Received: {line}")

            if line == "Button Pressed":
                run_python_script()

except KeyboardInterrupt:
    ser.close()
    print("Serial connection closed.")
