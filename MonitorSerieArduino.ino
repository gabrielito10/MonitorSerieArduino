/*
Programa para recibir por el monitor serie el numero de pin a encender
la letra 'E' para encender todo y 'A' para apagar todos los leds
Material:
-Arduino uno
-4 Resistencias de 330 ohmios
-4 leds
-Protoboard

Autor: Juan Gabriel Ibañez Cedillo
*/
void setup()
{
    //pines 2,3,4,5 como salidas
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);

    //Iniciamos el puerto seria a 9600 baudios(por defecto)
    Serial.begin(9600);
}
void loop()
{
    //Colocamos nuestro programa a la escucha de algun dato 
    //introducidopor el monitor serie 
    while(Serial.available())
    {
        //si escucho algo lo recibimos en la variable 'valorRecibido'
        char valorRecibido=Serial.read();

        //verificamos el valor introducido y dependiendo del numero
        //encenderemos el led del pin que fue tipeado 
        if (valorRecibido=='2')
        {
            digitalWrite(2,HIGH);
        }
        if (valorRecibido=='3')
        {
            digitalWrite(3,HIGH);
        }
        if (valorRecibido=='4')
        {
            digitalWrite(4,HIGH);
        }
        if (valorRecibido=='5')
        {
            digitalWrite(2,HIGH);
        }    
        //si el caracter recibido es 'E' encendemos todos los leds
        if (valorRecibido=='E')
        {
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,HIGH);
        }
        //si el caracter recibido es 'A' apagamos todos los leds
        if (valorRecibido=='A')
        {
            digitalWrite(2,LOW);
            digitalWrite(3,LOW);
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
        }
    }
}