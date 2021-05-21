# ProyectoFinal2021

<div align="center">

<img src="ReadmeDocs/Ener-Fi.png" width="30%"></img>
</div>

### Misión del proyecto:
Utilizar un algoritmo inteligente que aprenda los hábitos de consumo de usuarios domésticos para que les permita hacer uso responsable de la energía eléctrica.


### Descripción del equipo/necesidad a cubrir: 
El kit de EnerFi permite, mediante su interfaces gráficas web y móvil, la monitorización del consumo, la proyección de gasto energético y el control individual de los equipos sensados por el kit. 

Nuestros dispositivos se conectan entre sus electrodomésticos y la red eléctrica permitiéndole a cada nodo adquirir un perfil de consumo individual. 

Utilizando la información recolectada y los cuadros tarifarios vigentes de cada compañía de distribución eléctrica se brindará un reporte al usuario para que pueda realizar un consumo responsable.

También permite el encendido y apagado de los equipos de forma remota a través de la aplicación y el control del funcionamiento de las tasas de consumo emitidas por el ENRE.

Partiendo de que la distribución de la energía eléctrica en nuestro país no es perfecta, como muchos otros servicios, nuestro sistema es capaz de registrar la diferencia de los parámetros normales, informarlos al usuario y ofrecerle un reporte en el caso de que sea necesario presentarlo ante un ente regulador.
 

Medición monofásica orientada a equipos de gran consumo hogareño:
Vrms, Irms, P, Srms, fp, cos fi, THD, sweells, dips,  consumo.
Detección y actuación on/off: control on/off a distancia (fuera de casa) mediante una app en la cual se visualiza el consumo, permitiendo saber si quedo encendida/apagada.
Comunicación: wifi mediante servidor externo
Análisis de resultados: 
Mediante las tablas de consumo energético del ENRE y la medición correspondiente, asignarle una clasificación para ver si cumple o no las especificaciones del fabricante. 
Históricos de consumo


### HW:
ESP32
Sensor de efecto hall para medir corriente ACS712A o Bobina enrollada
Ver como medir tensión (Divisor capacitivo o de tensión)
