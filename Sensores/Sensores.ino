#include <SPI.h>
#include <Ethernet.h>
#include <dht11.h>
#include <Wire.h>

//Declara constantes y pin de entrada
#define DHT11PIN 2  // El sensor de temperatura y humedad
#define LED 9     //El LED esta conectado en el pin 9 
#define LDR 0     //El LDR esta conectador en el pin A0
const int EchoPin = 5;
const int TriggerPin = 6;
const int LedPin = 13;
const int luz = 0;       
const int buzzer = 8;
int valor_sensor = 0;       
int valor_limite = 490; 

// Se introducen la ip y la mac.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10,54,1,5);

// Inicializa la libreria ethernet, el puerto 80 esta por defecto para HTTP
EthernetServer server(80);

dht11 DHT11;  //El objeto sensor

void setup()
{
  // Abrir comunicacion serial y esperar que el puerto responda
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(LED,OUTPUT);
  pinMode(LDR,INPUT);
  while (!Serial) {
    ; // Esperar a que el puerto serial se conecte (solo cuando usamos Arduino Leonardo)
  }

  //Inicializar la conexion Ethernet y el servidor
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
} //Termina setup

 

void loop()
{
  //Escucha clientes de entrada
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    //Una solicitud http cuya linea esta en blanco
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        
        // Si la linea en la solicitud http esta en blanco y el cliente esta disponible se puede enviar una respuesta
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connnection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // Agregar una etiqueta meta que recargue la pagina cada segundo
          client.println("<meta http-equiv=\"refresh\" content=\"1\">"); 
          client.println("<br />");    

          //Obtener las lecturas del sensor e imprimir el resultado
          int chk = DHT11.read(DHT11PIN);

          Serial.print("Read sensor: ");
          switch (chk)
          {
          case 0: 
            Serial.println("OK"); 
            break;
          case -1: 
            Serial.println("Checksum error"); 
            break;
          case -2: 
            Serial.println("Time out error"); 
            break;
          default: 
            Serial.println("Unknown error"); 
            break;
          }  

          //Sensor de luz
          valor_sensor = analogRead(LDR); 
          luz = (5.0 * valor_sensor * 100.0)/1024.0;              
          delay(300);                       
          if (luz <= valor_limite)   //Si el valor de luz es menor o igual que el valor limite
          {
           client.print("Buenas dias");  
          digitalWrite (LED, LOW);  //El led se apaga
          }
          if (luz > valor_limite)   //Si es mayor que el valor limite
          {
          client.print("Buenas noches.");  
          digitalWrite (LED, HIGH);  //El led se eniende
          }
          client.println("<br />");

          //Sensor de temperatura
          client.print("Temperatura (Celsius): ");
          client.println((float)DHT11.temperature, 1);  
          client.println("<br />");   
          
          client.print("Humedad (%): ");
          client.println((float)DHT11.humidity, 0);  
          client.println("<br />");
 
          //Sensor de distancia
          int cm = ping(TriggerPin, EchoPin);
          if (cm<10){ //La distancia que saca el sensor es menor a 10
            client.print("Ten cuidado alguien esta muy cerca:"); //Impre mensaje de alerta
            tone(buzzer, 250); //Suena el buzzer
            client.print("Distancia: ");
            client.println(cm);
            client.println("<br />");
           }
            client.println("<br />");
            noTone(buzzer);
            
          //Termina lectura del sensor
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          //Linea en blanco
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          //Si hay un caracter en la linea en blanco
          currentLineIsBlank = false;
        }
      }
    }
    //Darle al navegador web tiempo para recibir los datos 
    delay(1);
    //Se cierra la conexion
    client.stop();
    Serial.println("client disonnected");
  }
} //Termina loop

//Convertir de grados Centrigrados a Farenheit
double Fahrenheit(double celsius)
{
  return 1.8 * celsius + 32;
}

//Centigrados a Kelvin
double Kelvin(double celsius)
{
  return celsius + 273.15;
}

 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}

