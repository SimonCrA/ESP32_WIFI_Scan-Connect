### SCAN AND CONNECT TO A WIFI

Este código le permite al ESP32 escanear redes wifi y conectarse a la red especificada en la sección

```
const char* ssid = "noShar3";
const char* password = "holacomoestas";
```
Esta sección del código es dónde se debe ingresar las credenciales de la red WIFI a la que deseo conectarme.

### Side Note: 
Recuerden que para que el monitor serial funcionen deben tener la velocidad igual que la que se establece en código

```
Serial.begin(115200);
```

Archivo platformio.ini

```
monitor_speed = 115200
```