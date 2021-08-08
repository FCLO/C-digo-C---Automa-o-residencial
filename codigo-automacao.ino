#include <ESP8266 NodeMCUWiFi.h>//Inclui biblioteca Wi-Fi do ESP8266 NodeMCU

//Define representação dos pinos usados para cada relé #define Rele_01 16	//mesmo que D0
#define Rele_02 5	//mesmo que D1


//Cria um server na porta 80
//Porta padrão para onde os navegadores enviam as requisições http) WiFiServer server (80);

void setup()
{
//Inicializa a Serial para efeito de log Serial.begin(115200);

//Ajusta o modo de todos os pinos pinMode(Rele_01, OUTPUT); pinMode(Rele_02, OUTPUT);
//Ajusta o estado de todos os pinos digitalWrite(Rele_01, HIGH); digitalWrite(Rele_02, LOW);

Serial.print("Conectando");//informando estado atual (debug)
//Conexão do microcontrolador com a rede Wi-Fi disponível do local onde será usado.
WiFi.begin("nome_wi-fi", "senha");


//Enquanto o ESP não se conectar à rede
 


while (WiFi.status() != WL_CONNECTED)
{
//Configuração de espera em 100 milissegundos delay(100);
Serial.print(".");
}


//Conectou à rede,
//Exibição da conexão no monitor serial Serial.println(""); Serial.println("Conectou");

//Configurações do IP fixo. IPAddress ip(IP_FIXO);
IPAddress gateway('IP'); IPAddress subnet('mácara de rede'); Serial.print("Configurando IP fixo para : "); Serial.println(ip);

//Envia a configuração WiFi.config(ip, gateway, subnet);

//Inicializa o server que criamos na porta 80 server.begin();

//É exibido no monitor serial o IP que o ESP possui Serial.print("Server em: "); Serial.println(WiFi.localIP());
}


void loop()
{
//Verifica se um cliente está tentando se conectar WiFiClient client = server.available();
 


if (!client)
{


//Se não houver nenhum cliente retorna return;
}


Serial.println(" Um cliente conectou-se");


// leitura da requisição
String req = client.readStringUntil('\r'); Serial.print("Requisição: "); Serial.println(req);

String html = "<html>" "<head>"
"<meta	content='width=device-width,	initial-scale=1,	user-scalable=no' name='viewport' />"
"<title>Controle Residencial</title>" "<h1>Automa&ccedil&atildeo Residencial</h1>" "<h2>LopesTec</h2>"
"<h5> Solu&ccedil&otildees Inteligentes Pra Sua Casa</h5>" "<style type='text/css'>"
"body{text-align: center;" "font-family: sans-serif;"
"font-size:21px;padding: 25px;" "}""h2{color: #0000ff"
"}""h1{color: #0000ff"
"}""h5{color: #0000ff"
"}""p{color:#0000ff;"
"}""button{outline: none;" "border: 2px solid #0000CD;" "border-radius:90px;"
 


"background-color:#00FFFF;" "color: #1fa3ec;"
"padding: 15px 15px;" "}"
"button:active{color: #fff;" "background-color:#0000ff;" "}"
"button:hover{border-color:##0000ff;" "}"
"body {"
"background-color: #B0E0E6;}" "</style>"
"</head>" "<body>" "<figure> "
"<img
src=""data:image/jpeg;base64,/9j/4AAQSkZJRgABAQEAYABgAAD/2wBDAAMCA gMCAgMDAwMEAwMEBQgFBQQEBQoHBwYIDAoMDAsKCwsNDhIQDQ4RDgsL EBYQERMUFRUVDA8XGBYUGBIUFRT/2wBDAQMEBAUEBQkFBQkUDQsNFB QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB QUFBQUFBQUFBT/wAARCAEVAMgDASIAAhEBAxEB/8QAHwAAAQUBAQEBA QEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQ
IDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoK So0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIW Gh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2 uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECA wQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQd
hcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5Ok NERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZa XmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6 Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD9Ha6jRf8AkGw/8C/9CNUv+Eb/AOn n/wAc/wDr0f2l/Y/+ieX5vl/x7tuc89Me9AG3VHWv+QbN/wAB/wDQhVL/AIST/p3/AP H/AP61H9pf2x/onl+V5n8e7djHPTHtQBiUVt/8I3/08/8Ajn/16P8AhG/+nn/xz/69AF3Rf
+QbD/wL/wBCNXqxP7S/sf8A0Ty/N8v+Pdtznnpj3o/4ST/p3/8AH/8A61AF3Wv+QbN
 


/wH/0IVy9bf8AaX9sf6J5fleZ/Hu3Yxz0x7Uf8I3/ANPP/jn/ANegDErqNF/5BsP/AAL/A NCNUv8AhG/+nn/xz/69ea/tK6ld6N8AvHtvYTTW15b6RPJFeW8pikRgu/Kkcgj2NN Aey1R1r/kGzf8AAf8A0IV+YH/BPH4heJNW/aAlTVdd1TVrZdIuG8i8vpJE3bowDhiR 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"" width=115 height=90" """align='rigth'>"" </figure>" // Imagem em base64
"<p>Acionamento de L&acirc;mpadas</p>"
 


"<p>L&acirc;mpada 01"
"- <a href='?acao=Rele_01Acender'>" "<button>Acender</button></a>"
"<a href='?acao=Rele_01Apagar'>" "<button>Apagar</button>" "</a></p>"
"<p><span style='color: #0000ff;'>" "L&acirc;mpada 02 -"
" <a href='?acao=Rele_02Acender'>" "<button>Acender</button></a>"
"<a href='?acao=Rele_02Apagar'>" "<button>Apagar</button></a>" "</p>"
"</body>" "</html>";
//Escreve o html no buffer que será enviado para o cliente client.print(html);
//Envia os dados do buffer para o cliente client.flush();


//Verificação de comandos na atuação sobre os relés if (req.indexOf("acao=Rele_01Acender") != -1)
{
digitalWrite(Rele_01, LOW);


}
else if (req.indexOf("acao=Rele_01Apagar") != -1)
{
digitalWrite(Rele_01, HIGH);


}


if (req.indexOf("acao=Rele_02Acender") != -1)
 


{
digitalWrite(Rele_02, HIGH);
}
else if (req.indexOf("acao=Rele_02Apagar") != -1)
{
digitalWrite(Rele_02, LOW);
}
delay(200);//aguarda para que o trafego das informações seja concluído
//Fecha a conexão com o cliente client.stop();
Serial.println("Cliente desconectado");
