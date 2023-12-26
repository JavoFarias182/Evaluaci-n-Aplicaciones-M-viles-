import serial
import time
from firebase import firebase

firebase = firebase.FirebaseApplication('https://app-movil-arduino-default-rtdb.firebaseio.com/')

arduino = serial.Serial('COM3', 9600)

# Tiempo de espera
time.sleep(2)

while True:
    # Leer datos del puerto serie
    sensorValue = arduino.readline().decode().strip()  # Decodificar y eliminar caracteres no deseados
    dato = float(sensorValue)  # Convertir a valor flotante
    
    data = {"Humedad": dato}  # Estructurar los datos a enviar a Firebase
    print(data)
    
    # Actualizar los datos en Firebase
    result = firebase.put('/datos', 'humedad', data)  # Ajustar la ruta y el campo a actualizar
