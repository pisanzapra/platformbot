import serial
import time

# Raspberry Pi üzerindeki Arduino'nun bağlı olduğu seri portu belirtin
arduino_port = "/dev/ttyUSB1"  # Bu port ismini Arduino'nun bağlandığı porta göre güncelleyin

# Arduino ile iletişim için seri portu açın
ser = serial.Serial(arduino_port, 9600, timeout=5)

if ser.is_open:
    print("Arduino ile bağlantı kuruldu.")
else:
    print("Arduino ile bağlantı kurulamadı. Portu kontrol edin.")
    exit(1)

try:
    while True:
        # Kullanıcıdan komut al
        command = input("Enter command (F,B,R,L,M ; P to stop vehicle and Q to quit program): ")

        if command.upper() == 'Q':
            # Eğer 'Q' tuşuna basılırsa programı sonlandır
            break

        # Arduino'ya komut gönder
        ser.write(command.encode())
        time.sleep(0.1)  # İsteğe bağlı olarak gecikme ekleyebilirsiniz

except KeyboardInterrupt:
    print("\nProgram kullanıcı tarafından sonlandırıldı.")

finally:
    # Seri portu kapat
    ser.close()
    print("Seri port kapatıldı.")

