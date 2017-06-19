import serial
import time

arduino = serial.Serial('/dev/ttyUSB0', 9600) #ttyUSB0 para arduino nano , ttyACMo para arduino uno
arduino.open

txt = ''
print("........Bienvenido.......\n")
print("Configuracion:\n")
times = int(raw_input('Cuantas veces al dia desea alimentar a su perrito? ')) #cuantas veces al dia
horarios = []  #lista para agregar horarios

while (times > 0):
      hora = raw_input('Horario formato 24h (HH:MM): ') #Input
      horarios.append(hora)
      times = times - 1

porcion = int(raw_input("Tamanio de la porcion? 1=Chica, 2=Mediana, 3=Grande ")) #porcion
      
print("........Configuracion completa.......\n")
print("........Horarios: \n")
for i in horarios:
      print "horario: %s" % i

print("........Porcion: \n")
if porcion == 1:
      print("Porcion: Chica \n")
if porcion == 2:
      print("Porcion: Mediana \n")
if porcion == 3:
      print("Porcion: Grande \n")


while True:
      hora_sys = time.strftime("%H:%M")
      #comando = raw_input('Introduce un comando: ') #Input
      #arduino.write(comando) #Mandar un comando hacia Arduino
      if hora_sys == "20:46":
            arduino.write("H") #Mandar un comando hacia Arduino
            print ("hora")
            
      time.sleep(0.1)
      print hora_sys
      while arduino.inWaiting() > 0:
            txt = arduino.read(1)
            print txt
            txt = ''
arduino.close() #Finalizamos la comunicacion
