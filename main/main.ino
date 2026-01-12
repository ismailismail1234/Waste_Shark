#include <RemoteXY.h>  

// RemoteXY connection settings  

#define REMOTEXY_SERIAL Serial  

#define REMOTEXY_SERIAL_SPEED 115200  

#define REMOTEXY_WIFI_SSID "boat1212"  

#define REMOTEXY_WIFI_PASSWORD "12345678"  

#define REMOTEXY_SERVER_PORT 6377  

// RemoteXY configurate  

#pragma pack(push, 1)  

uint8_t RemoteXY_CONF[] = // 58 bytes  

{ 255,4,0,0,0,51,0,16,6,1,1,0,23,36,12,12,36,8,226,134,  

145,0,1,0,9,50,12,12,2,24,226,134,182,0,1,0,38,49,12,12,  

2,24,226,134,183,0,1,0,24,66,12,12,1,8,226,134,147,0 };  

  

// this structure defines all the variables and events of your control interface  

struct {  

// input variables  

uint8_t up; // =1 if button pressed, else =0  

uint8_t left; // =1 if button pressed, else =0  

uint8_t right; // =1 if button pressed, else =0  

uint8_t back; // =1 if button pressed, else =0  

// other variable  

uint8_t connect_flag; // =1 if wire connected, else =0 

RemoteXY;  

#pragma pack(pop)  

/////////////////////////////////////////////  

// END RemoteXY include //  

/////////////////////////////////////////////  

#define int1 10  

#define int2 9  

#define int3 6  

#define int4 5  

void setup()  

{  

RemoteXY_Init ();  

pinMode (int1, OUTPUT);  

pinMode (int2, OUTPUT);  

pinMode (int3, OUTPUT);  

pinMode (int4, OUTPUT);  

  

// TODO you setup code  

  

}  

void move(uint8_t up, uint8_t left,uint8_t right,uint8_t back)  

{  

if (back == 1) {  

digitalWrite(int1, LOW); 

[ÖS 11:22, 24.12.2023] som3a/cyprus: digitalWrite(int2, HIGH);  

digitalWrite(int3, LOW);  

digitalWrite(int4, HIGH);  

} else if (up== 1) {  

digitalWrite(int1, HIGH);  

digitalWrite(int2, LOW);  

digitalWrite(int3, HIGH);  

digitalWrite(int4, LOW);  

}else if (right == 1) {  

digitalWrite(int1, HIGH);  

digitalWrite(int2, LOW);  

digitalWrite(int3, LOW);  

digitalWrite(int4, HIGH);  

} else if (left == 1) {  

digitalWrite(int1, LOW);  

digitalWrite(int2,HIGH);  

digitalWrite(int3, HIGH);  

digitalWrite(int4, LOW);  

}  

else if (left == 0 && right == 0 && back == 0 && up == 0 ) {  

digitalWrite(int1, LOW);  

digitalWrite(int2,LOW);  

digitalWrite(int3, LOW);  

digitalWrite(int4, LOW);  

}  

}  

void loop ()  

{ 

 RemoteXY_Handler ();  

move(RemoteXY.up,RemoteXY.left,RemoteXY.right,RemoteXY.back);  

  

  

// TODO you loop code  

// use the RemoteXY structure for data transfer  

// do not call delay(), use instead RemoteXY_delay()  

} 

 

 
