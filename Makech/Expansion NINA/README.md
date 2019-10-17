# Upgrade All-in-One ESP32 Firmware

## Uploading Serial Passthrough Code

Lo primero que se debe realizar es instalar la biblioteca "WiFiNINA" en el arduino library manager y cargar al Escornabot el ejemplo **"Serial Passthrough"**, una vez terminada la carga del firmware continue en el siguiente paso


## Subiendo nina-fw con esptool

¡Esta sección asume que usted sabe cómo usar 'esptool' para cargar firmware a su ESP! Si no está seguro, consulte https://github.com/espressif/esptool y busque tutoriales.
Haga clic en el siguiente enlace para descargar el último archivo .bin de nina-fw. Descomprimir que y guardar el archivo .bin a su escritorio .

Si está utilizando macOS o Linux , ejecute el siguiente comando, reemplazándolo /dev/ttys6con el puerto serie de su placa y  NINA_W102-1.3.0con el archivo binario que está actualizando al ESP32.

esptool.py --port /dev/ttyS6 --before no_reset --baud 115200 write_flash 0 NINA_W102-1.3.0.bin

Si está utilizando Windows , ejecute el siguiente comando, reemplazándolo COM7con el puerto serie de su placa y  NINA_W102-1.3.0con el archivo binario que está actualizando al ESP32

esptool.py --port COM7 --before no_reset --baud 115200 write_flash 0 NINA_W102-1.3.0.bin

El comando debería detectar el ESP32 y tardará uno o dos minutos en cargar el firmware. El NeoPixel en su placa parpadeará y parpadeará a medida que se carga el firmware. 

Si ESPTool no detecta el ESP32 , asegúrese de haber subido el archivo .UF2 correcto al gestor de arranque.

![](https://cdn-learn.adafruit.com/assets/assets/000/081/481/medium800/wireless_fish___Users_brent_Desktop__fish_.png?1569525510)

Una vez que el firmware está completamente cargado, el ESP32 se reiniciará y el NeoPixel se iluminará en azul. 

## Verificación de la versión de firmware actualizada

Para verificar que todo funcione correctamente, cargaremos un boceto Arduino o un código CircuitPython. 

Si anteriormente estaba usando su ESP32 con Arduino, debe cargar un boceto de Arduino para verificar que todo funcione correctamente y que la versión del nina-fw se correlaciona con la versión que lee el boceto.

Abra Archivo-> Ejemplos-> WiFiNINA-> ScanNetworks y cargue el boceto. Luego, abra el Monitor de serie. Debería ver la versión del firmware impresa en el monitor serie.

![](https://cdn-learn.adafruit.com/assets/assets/000/081/636/medium800/wireless_Banners_and_Alerts_and__dev_cu_usbmodem1412301__Adafruit_PyPortal_M4__SAMD51__.png?1569859141)
