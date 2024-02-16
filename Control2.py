import serial
import time
import random

# Raspberry Pi üzerindeki Arduino'nun bağlı olduğu seri portu belirtin
arduino_port = "/dev/ttyUSB0"  # Bu port ismini Arduino'nun bağlandığı porta göre güncelleyin

# Arduino ile iletişim için seri portu açın
ser = serial.Serial(arduino_port, 9600, timeout=5)

if ser.is_open:
    print("Arduino ile bağlantı kuruldu.")
else:
    print("Arduino ile bağlantı kurulamadı. Portu kontrol edin.")
    exit(1)

def send_random_command():
    commands = ['F', 'B', 'R', 'L', 'M']
    random_command = random.choice(commands)
    ser.write(random_command.encode())
    print(f"Sent command: {random_command}")
    time.sleep(5)  # İsteğe bağlı, arduino'nun komutu işlemesi için bir süre bekleyebilirsiniz

try:
    print("Program başladı. Rastgele komutlar gönderiliyor. Çıkış için Ctrl+C kullanabilirsiniz.")
    while True:
        send_random_command()

except KeyboardInterrupt:
    print("\nCtrl+C algılandı. Program kapatılıyor.")
    commands.upper() == 'P'
            # Eğer 'Ctrl+C' tuşuna basılırsa aracı durdurur.

finally:
    # Seri portu kapat
    ser.close()
    print("Seri port kapatıldı.")

