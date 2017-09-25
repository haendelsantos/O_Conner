//nome: Rogério S Melo - 77768
//nome: Lucas Damasceno - 78671
//nome: Guilherme Haendel Santos - 79301
// Robo: O'Conner
/*
Drive L298p robocore 
Link: https://www.robocore.net/loja/produtos/arduino-shield-motor-driver-2x2a.html
*/
#include<stdlib.h>
#include<stdio.h>

/* Parte ainda não incluida no robo.
#include "DHT.h"
#define DHTPIN A1 
#define DHTTYPE DHT11 

DHT sensor(DHTPIN,DHTTYPE);//Definindo a biblioteca umidade e temperatura.
const int faroisPin = 2; //Painel de LED
const int sensorLuzPin = 4; //SENSOR LDR
*/

//CONEXÕES DOS MOTORES. (1) HORARIO, (2) ANTI HORARIO;
const int motorEsquerdo1 = 5;
const int motorEsquerdo2 = 6;
const int motorDireito1 = 7;
const int motorDireito2 = 8;
byte comandoApp;
float i;
float j;

void setup()
{
  Serial.begin(9600);
  Serial.println("START!!");
  sensor.begin();
//  pinMode(faroisPin,OUTPUT);
  pinMode(motorEsquerdo1, OUTPUT);
  pinMode(motorEsquerdo2, OUTPUT);
  pinMode(motorDireito1, OUTPUT);
  pinMode(motorDireito2, OUTPUT);
}
 
void loop()
{
  /* Parte ainda não incluída no Robo 
  //SENSORES
  int valorLuz  = analogRead(sensorLuzPin);
  float umidade = sensor.readHumidity();
  float temperatura = sensor.readTemperature();

  if (isnan(umidade)){
    Serial.println("Nao foi possivel obter umidade.");
  } else{
    Serial.print("Hum. = ");
    Serial.print(umidade);
    Serial.println(" % "); 
  } 
  
  if(isnan(temperatura)){
    Serial.println("Nao foi possivel obter temperatura.");  
  } else{
    Serial.print("Temp. = ");
    Serial.print(temperatura);
    Serial.print(" C ");
  }
  if(isnan(valorLuz)){
    Serial.println("Nao foi possivel obter a luminosidade.");
    digitalWrite(faroisPin,LOW); //Por padrão, luz apagada;
  } else{
     if (valorLuz>= 800){ 
          digitalWrite(faroisPin,HIGH);
        } else{ 
          digitalWrite(faroisPin,LOW);
        }
     Serial.println(valorLuz);
  }*/
  //MOTORES
  if(Serial.available()){
    comandoApp = Serial.read();
    
    if((comandoApp >= 0) || (comandoApp <= 255)){
      i = comandoApp;
      delay(100);
    }else{
      switch(comandoApp){
        
        // DESLIGA MOTOR
        case 'S':
          analogWrite(motorEsquerdo2, 0);
          analogWrite(motorDireito2, 0);
          delay(100);
          break;
        
        // PARA FRENTE
        case 'U':
            digitalWrite(motorEsquerdo1, HIGH);
            digitalWrite(motorDireito1, HIGH);
            analogWrite(motorEsquerdo2, i);//VELOCIDADE
            analogWrite(motorDireito2, i);//VELOCIDADE
            delay(100);
          break;
      
        // PARA TRAZ(RÉ)
        case 'D':
            digitalWrite(motorEsquerdo1, LOW);
            digitalWrite(motorDireito1, LOW);
            analogWrite(motorEsquerdo2, i);//VELOCIDADE
            analogWrite(motorDireito2, i);//VELOCIDADE
            delay(100);
          break;
        
        // PARA DIREITA
        case 'R':
            digitalWrite(motorEsquerdo1, HIGH);
            digitalWrite(motorDireito1, HIGH);
            analogWrite(motorEsquerdo2, i);
            analogWrite(motorDireito2, 0);
            delay(100);
          break;
        
        // PARA DIREIRA E FRENTE, DIAGONAL
        case 'W':
            digitalWrite(motorEsquerdo1, HIGH);
            digitalWrite(motorDireito1, HIGH);
            analogWrite(motorEsquerdo2, i);//VELOCIDADE
            j = (i/2)//METADE DA VELOCIDADE
            analogWrite(motorDireito2, j);//VELOCIDADE
            delay(100);
          break; 
          
        // PARA DIREITA E  TRAZ(RÉ), DIAGONAL
        case 'X':
            digitalWrite(motorEsquerdo1, LOW);
            digitalWrite(motorDireito1, LOW);
            analogWrite(motorEsquerdo2, i);//VELOCIDADE
            j = (i/2)//METADE DA VELOCIDADE
            analogWrite(motorDireito2, j);//VELOCIDADE
            delay(100);
          break;
          
        // GIRAR PARA DIREITA, OBS: IRA GIRAR EM O PROPRIO EIXO
        case 'O':
            digitalWrite(motorEsquerdo1, HIGH);
            digitalWrite(motorDireito1, LOW);
            analogWrite(motorEsquerdo2, i);//VELOCIDADE
            analogWrite(motorDireito2, i);//VELOCIDADE
            delay(100);
          break;
        
        // PARA ESQUERDA
        case 'L':
            digitalWrite(motorEsquerdo1, HIGH);
            digitalWrite(motorDireito1, HIGH);
            analogWrite(motorEsquerdo2, 0);//VELOCIDADE
            analogWrite(motorDireito2, i);//VELOCIDADE
            delay(100);
          break;
          
        // PARA ESQUERDA E FRENTE, DIAGONAL
        case 'Z':
            digitalWrite(motorEsquerdo1, HIGH);
            digitalWrite(motorDireito1, HIGH);
            analogWrite(motorDireito2, i);//VELOCIDADE
            j = (i/2)//METADE DA VELOCIDADE
            analogWrite(motorEsquerdo2, j);//VELOCIDADE
            delay(100);
          break;
          
        // PARA ESQUERDA E TRAZ(RÉ), DIAGONAL
        case 'Y':
            digitalWrite(motorEsquerdo1, LOW);
            digitalWrite(motorDireito1, LOW);
            analogWrite(motorDireito2, i);//VELOCIDADE
            j = (i/2)//METADE DA VELOCIDADE
            analogWrite(motorEsquerdo2, j);//VELOCIDADE
            delay(100);
          break;
        
        // GIRAR PARA ESQUERDA, OBS:IRA GIRAR EM O PROPRIO EIXO  
        case 'I':
            digitalWrite(motorEsquerdo1, LOW);
            digitalWrite(motorDireito1, HIGH);
            analogWrite(motorEsquerdo1, i);//VELOCIDADE
            analogWrite(motorDireito1, i);//VELOCIDADE
            delay(100);
          break;

        default:
          Serial.println("Nenhum comando executado.");
          delay(100); 
          break;
      }
    }
  }
 delay(100); 
}

