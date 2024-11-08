#include <WiFi.h>

const char* ssid_wifi = "rede"; //ssid da sua rede
const char* password_wifi = "senha_da_rede"; //senha da sua rede

const char* ssid_ap = "NDSL_ESP32_KSLOV"; //rede para se conectar no ds
const char* password_ap = "1234567890"; //senha para se conectar na rede obs: nunca trocar a senha

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Conectando-se à rede Wi-Fi...");
  WiFi.begin(ssid_wifi, password_wifi);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Tentando conectar...");
  }

  Serial.println("Conectado à rede Wi-Fi!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  Serial.println("Configurando o ponto de acesso (AP) com WEP...");
  WiFi.softAP(ssid_ap, password_ap, 1, false, 4);

  WiFi.softAPConfig(IPAddress(192,168,1,1), IPAddress(192,168,1,1), IPAddress(255,255,255,0));

  Serial.println("Configuração do AP concluída!");
  Serial.print("IP do AP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  Serial.print("Dispositivos conectados: ");
  Serial.println(WiFi.softAPgetStationNum());

  delay(5000); 
}
