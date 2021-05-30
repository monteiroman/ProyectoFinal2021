Ejemplo de conexión via AP a la red del hogar.

El thread principal se encarga de presentar un AP para que la app envie las 
credenciales de conexión, una vez conectado imprime "Hello world" por consola
cada 1 segundo. 
El thread secundario cambia el estado del led de la placa cada 1,5 segundos 
mientras no esta conectado a la red wifi y cada 200mS cuando si lo está.