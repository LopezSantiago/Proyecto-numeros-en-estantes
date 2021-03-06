//********************************************/
//     DECLARACION DE Uc y Puertos           //
//********************************************/

 #include <16f1937.h>  //microcontrolador ej: #include <xxxx.h>
 #fuses   INTRC_IO  //fusible del cristal #fuses   INTRC_IO  
 #FUSES   NOWDT,PUT,NOPROTECT, NOLVP, NOBROWNOUT ,NOMCLR  //fuses ejm: NOWDT,PUT,NOPROTECT, NOLVP, NOBROWNOUT ,NOMCLR
 #use     delay (CLOCK=8M)  //seleccion de la frecuencia del cristal ejm: #use     delay (CLOCK=8M)
 #use     rs232(baud=9600, xmit=PIN_C6,rcv=PIN_C7)  //seleccion pines comunicacion serial #use     rs232(baud=9600, xmit=PIN_C6) 


//*** DECLARACION DE BANCOS DE PINES ***//

//********************************************/
//      #includes >> Librerias "APIS"        //
//********************************************/



//********************************************/
// #includes  >> Cabeceras '.c y .h' propias //
//********************************************/




//********************************************/
//                #DEFINES                   //
//*******************************************

//********************************************/
//     DECLARACION VARIABLES GLOBALES        //
//********************************************/
float numeroSeleccionado;
char dato;
int gate;
int datos_x_serial[3];
int i =0,unidad,decena;
int1 numeros[10][8]={{1,0,1,1,0,0,0,0},
                     {0,0,1,1,0,0,0,0},
                     {1,0,1,0,0,0,1,0},
                     {0,0,1,0,0,0,0,0},
                     {0,0,0,1,0,0,0,0},
                     {0,0,0,0,1,0,0,0},
                     {0,0,0,0,0,1,0,0},
                     {0,0,0,0,0,0,1,0},
                     {1,1,1,1,1,1,1,0},
                     {0,0,0,0,0,0,0,0}};

//********************************************/
//            PROTOPOS A FUNCIONES           //
//********************************************/
void Mcu_init();
void LlenarVector();


#INT_rda
void serial_isr() 
{ 
    dato=getchar();
    if(dato!='$')
        {
         datos_x_serial[i]=dato;
         i++;
        }           
    else
     {
      i=0;      
      unidad= datos_x_serial[0] - 48;
      decena= datos_x_serial[1] - 48;
      
      numeroSeleccionado= (float)(unidad*10.0)+decena;

     }
}




void llenarVector(void){
   for(int i=1;i<5;i++){  
      for (int i=0;i<8;i++){
         
      }
   }
}

void escribirDatos(void){ 
   disable_interrupts(int_rda);
   int cont=0;       
   while (cont<40){
      if(gate==0)
      {  output_low(pin_a1);
         gate=1;
         cont++;
      }
      else
      {
         
         //(tabla[cont]==0)?(output_low(pin_a2)):(output_high(pin_a2));
         output_high(pin_a1);
         gate=0;
         cont++;
      }      
   }  
      output_high(pin_a4);
      delay_us(100);
      output_low(pin_a2);
      output_low(pin_a5);
      output_low(pin_a4);
           
      enable_interrupts(int_rda);
}

//********************************************/
//                   MAIN                    //
//********************************************/
void main()    
  {
   Mcu_init();       //inicializacion de los pines y perifericos del Uc
   while(1)
   { 
   
   }
   }
    //*********************************************/
//FUNCION Inicializa Pines Perifericos e Intpc//
//*********************************************/
void Mcu_init()
{

   //PORTA_TRIS = 0b00000001;
  
   // lo siguiente se requiere para conigurar el pin d6 como entrada analogica.
   enable_interrupts(GLOBAL);   
   enable_interrupts(int_rda);
   LlenarVector();   
   output_low(pin_a0);
   output_low(pin_a1);
   output_low(pin_a2);
   printf("ok ok ok ok ok ok ok ok ok ok ok");
}


//*********************************************/
//FUNCION Inicializa Las Variables Globales   //
//*********************************************/



