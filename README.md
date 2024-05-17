## Introducción
Este es un repositorio para mis prácticas con Arduino, no llevan ningún orden en específico, ni se trata de un proyecto en particular. Se irán agregando descripciones para cada proyecto en este documento.
***
#### Bluetooth1.ino
En este proyecto se usa un módulo Bluetooth para conectar a una aplicación en Android.
- Switches para encender dos LED's conectados a la placa
- Un sensor de ultrasonido que calcula la distancia pero solo lo muestra en el monitor serial
- Usa la aplicación de App Inventor "Arduino 1"

#### Bluetooth2.ino
Este proyecto es una plantilla que ejemplifica el funcionamiento base del módulo Bluetooth.
- Ingresar comandos desde el monitor serial
- Ejemplo de recibir datos desde el Arduino

Para configurar el módulo se debe:
- Desconectar la antena
- Presionar el botón en el módulo y mantener
- Conectar la antena con el botón presionado
- La antena comenzará a parpadear mas lento, con esto ya se encuentra en modo de configuración
- Los comandos comienzan con AT+\[atributo\], por ejemplo
- Para realizar consultas se usa "?" después del comando, por ejemplo AT+NAME? pregunta el nombre del dispositivo
- Para asignar un valor se usa \[COMANDO\]=\[VALOR\]
  - **AT+NAME**: Nombre del dispositivo
  - **AT+PSWD**: Contraseña (PIN)
  - **AT+UART**: Parametros de comunicación, he visto que siempre se usa 38400,0,0
  - **AT+ROLE**: Rol, 0 esclavo y 1 maestro
  - **AT+ORGL**: Restaura valores de fabrica, pero cuando lo usé este falló y salió del modo de configuración, no he determinado a que se debe
  - **AT+RESET**: Vuelve al modo usuario