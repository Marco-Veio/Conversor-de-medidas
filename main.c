#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

char idioma(int f,int i);
int escolhas(const int tam,int f,char unidades[1001],int e);
char numero(const int tam,int menu,char unidades[1001],int e);
void conversao(const int tam,int menu,char unidades[1001],int e,float numb,int decimal,char num[101],char num1[101],int expoente);

char temperatura(void);
char bases(void);
char prefixos(void);
char tempo(void);
char velocidade(void);
char angulo(void);
char comprimento(void);
char area(void);
char volume(void);

int main()
{
    system("color F0");
    char sair;
    do{
        char unidades[1001]="";
        int i;
        for(i=0;idioma(2,i)!=0;i++)
            unidades[i]=idioma(2,i);
        switch(escolhas(9,1,unidades,0)){
            case -1:return 0;break;
            case 0:sair=temperatura();break;
            case 1:sair=bases();break;
            case 2:sair=prefixos();break;
            case 3:sair=tempo();break;
            case 4:sair=velocidade();break;
            case 5:sair=angulo();break;
            case 6:sair=comprimento();break;
            case 7:sair=area();break;
            case 8:sair=volume();break;
        }
    }while(sair==8);
    return 0;
}
char idioma(int f,int i){
    char frase[1001]="",lang[1000];
    int lingua=0;
    strcpy(lang,setlocale(LC_MONETARY,""));
    if(!strcmp(lang,"English_United States.1252"))
        lingua=0;
    if(!strcmp(lang,"Portuguese_Brazil.1252"))
        lingua=1;
    switch(f){
        case -2:
            if(lingua==0)
                printf(":     ");
            if(lingua==1)
                printf(":   ");
            break;
        case -1:
            if(lingua==0)
                printf("Press enter to restart, backspace to go back or esc to exit!");
            if(lingua==1)
                printf("Aperte enter para recome%car, backspace para voltar ou esc para sair!",-121);
            break;
        case 0:
            if(lingua==0)
                printf("What's the number that must be converted?\n");
            if(lingua==1)
                printf("Qual o n%cmero que deve ser convertido?\n",-93);
            break;
        case 1:
            if(lingua==0)
                printf("Converter of:\n");
            if(lingua==1)
                printf("Conversor de:\n");
            break;
        case 2:
            if(lingua==0)
                strcpy(frase,"Temperature|Numeric bases|Physics prefixes|Time|Speed|Angle|Length|Area|Volume|");
            if(lingua==1){
                strcpy(frase,"Temperatura|Bases numericas|Prefixos de fisica|Tempo|Velocidade|Angulo|Comprimento|Area|Volume|");
                frase[21]=-126;frase[41]=-95;frase[64]=-74;frase[83]=-75;
            }
            break;
        case 3:
            if(lingua==0)
                printf("I'll convert the temperature from one scale to the others!\nWhich scale do you want to use?\n");
            if(lingua==1)
                printf("Irei converter a temperatura de uma escala para outras!\nQual escala voc%c deseja usar?\n",-120);
            break;
        case 4:
            strcpy(frase,"Celsius|Fahrenheit|Kelvin|");
            break;
        case 5:
            if(lingua==0)
                printf("I'll convert the number of a base to the others!\nWhich base do you want to use?\n");
            if(lingua==1)
                printf("Irei converter o n%cmero de uma base para outras!\nQual base voc%c deseja usar?\n",-93,-120);
            break;
        case 6:
            if(lingua==0)
                strcpy(frase,"Decimal|Binary|Hexadecimal|Octal|");
            if(lingua==1){
                strcpy(frase,"Decimal|Binario|Hexadecimal|Octal|");
                frase[11]=-96;
            }
            break;
        case 7:
            if(lingua==0)
                printf("I'll convert the physics prefixes!\nWhich one do you want to use?\n");
            if(lingua==1)
                printf("Irei converter os prefixos de f%csica!\nQual prefixo voc%c deseja usar?\n",-95,-120);
            break;
        case 8:
            if(lingua==0){
                strcpy(frase,"Yotta(Y)|Zetta(Z)|Exa(E)|Peta(P)|Tera(T)|Giga(G)|Mega(M)|Quilo(k)|Hecto(h)|Deca(da)|None|Deci(d)|Centi(c)|Mili(m)|Micro(u)|Nano(n)|Pico(p)|Femto(f)|Atto(a)|Zepto(z)|Yocto(y)|");
                frase[120]=230;
            }
            if(lingua==1){
                strcpy(frase,"Yotta(Y)|Zetta(Z)|Exa(E)|Peta(P)|Tera(T)|Giga(G)|Mega(M)|Quilo(k)|Hecto(h)|Deca(da)|Nenhum|Deci(d)|Centi(c)|Mili(m)|Micro(u)|Nano(n)|Pico(p)|Femto(f)|Atto(a)|Zepto(z)|Yocto(y)|");
                frase[122]=230;
            }
            break;
        case 9:
            if(lingua==0)
                printf("I'll convert  the units of time!\nWhich unit do you want to use?\n");
            if(lingua==1)
                printf("Irei converter as unidades de tempo!\nQual unidade voc%c deseja usar?\n",-120);
            break;
        case 10:
            if(lingua==0)
                strcpy(frase,"Seconds|Minutes|Hours|Days|Weeks|Months|Years|Decades|Centuries|Millenniums|");
            if(lingua==1){
                strcpy(frase,"Segundos|Minutos|Horas|Dias|Semanas|Meses|Anos|Decadas|Seculos|Milenios|");
                frase[48]=-126;frase[56]=-126;frase[66]=-120;
            }
            break;
        case 11:
            if(lingua==0)
                printf("I'll convert the speed from one unit to the others!\nWhich unit do you want to use?\n");
            if(lingua==1)
                printf("Irei converter a velocidade de uma unidade para outras!\nQual unidade voc%c deseja usar?\n",-120);
            break;
        case 12:
            if(lingua==0)
                strcpy(frase,"Meters per second|Kilometers per hour|Knot|");
            if(lingua==1){
                strcpy(frase,"Metros por segundo|Quilometros por hora|Nos|");
                frase[23]=-109;frase[41]=-94;
            }
            break;
        case 13:
            if(lingua==0)
                printf("I'll convert the angle from one unit to the others!\nWhich unit do you want to use?\n");
            if(lingua==1)
                printf("Irei converter o %cngulo de uma unidade para outras!\nQual unidade voc%c deseja usar?\n",-125,-120);
            break;
        case 14:
            if(lingua==0)
                strcpy(frase,"Degrees|Radians(pi)|Revolutions|Grad|");
            if(lingua==1){
                strcpy(frase,"Graus|Radianos(pi)|Revolucoes|Gradianos|");
                frase[25]=-121;frase[26]=-28;
            }
            break;
        case 15:
            if(lingua==0)
                printf("I'll convert the length from one unit to the others!\nWhich unit do you want to use?\n");
            if(lingua==1)
                printf("Irei converter o comprimento de uma unidade para outras!Qual unidade voc%c deseja usar?\n",-120);
            break;
        case 16:
            if(lingua==0)
                strcpy(frase,"Meters|Feet|Miles|Yards|Inches|Light-years|");
            if(lingua==1){
                strcpy(frase,"Metros|Pes|Milhas|Jardas|Polegadas|Anos-luz|");
                frase[8]=-126;
            }
            break;
        case 17:
            if(lingua==0)
                printf("I'll convert the area from one unit to the others!\nWhich unit do you want to use?\n");
            if(lingua==1)
                printf("Irei converter a %crea de uma unidade para outras!\nQual unidade voc%c deseja usar?\n",-96,-120);
            break;
        case 18:
            if(lingua==0)
                strcpy(frase,"Square meters|Square feet|Square miles|Square yards|Square inches|Hectares|");
            if(lingua==1){
                strcpy(frase,"Metros quadrados|Pes quadrados|Milhas quadradas|Jardas quadradas|Polegadas quadradas|Hectares|");
                frase[18]=-126;
            }
            break;
        case 19:
            if(lingua==0)
                printf("I'll convert the volume from one unit to the others!\nWhich unit do you want to use?\n");
            if(lingua==1)
                printf("Irei converter o volume de uma unidade para outras!\nQual unidade voc%c deseja usar?\n",-120);
            break;
        case 20:
            if(lingua==0)
                strcpy(frase,"Cubic meters|Liters|Cubic feet|Cubic miles|Cubic yards|Cubic inches|");
            if(lingua==1){
                strcpy(frase,"Metros cubicos|Litros|Pes cubicos|Milhas cubicas|Jardas cubicas|Polegadas cubicas|");
                frase[8]=-93;frase[23]=-126;frase[27]=-93;frase[42]=-93;frase[57]=-93;frase[75]=-93;
            }
            break;
    }
    return frase[i];
}
int escolhas(const int tam,int f,char unidades[1001],int e){
    int er,i,j;
    char escolha[tam],move;
    do{
        system("cls");
        for (er=0;er<tam;er++)
            escolha[er]=' ';
        escolha[e]=254;
        idioma(f,0);
        for(i=0,j=0;unidades[i]!=0;i++,j++){
            printf("%c ",escolha[j]);
            for(;unidades[i]!='|';i++)
                printf("%c",unidades[i]);
            printf("\n");
        }
        do{
            do{
                move=getch();
            }while(move!=-32 && move!='w' && move!='s' && move!=13 && move!=27 && move!=8 &&(move<'1' && move>tam+48));
            if(move==-32)
                move=getch();
        }while(move!='H' && move!='P' && move!='w' && move!='s' && move!=13 && move!=27 && move!=8 &&(move<'1' && move>tam+48));
        if(tam<10 && move>='1' && move<=tam+48)
            e=move-49;
        switch(move){
            case 'w':
            case 'H':if(e>0) e--;else e=tam-1;break;
            case 's':
            case 'P':if(e<tam-1) e++;else e=0;break;
            case 27:return -1;break;
            case 8:return -2;break;
        }
    }while(move!=13);
    return e;
}
char numero(const int tam,int menu,char unidades[1001],int e){
    int ponto=0,i=0,j=0,decimal,expoente;
    char sair,num[101]="",num1[101]="",temp[101]="";
    float numb;
    system("cls");
    idioma(0,0);
    do{
        num[i]=getch();
        if(menu==1){
            if(e==0){
                if(num[i]>='0' && num[i]<='9'){
                    printf("%c",num[i]);
                    i++;
                }
            }
            if(e==1){
                if(num[i]=='0' || num[i]=='1'){
                    printf("%c",num[i]);
                    i++;
                }
            }
            if(e==2){
                if(num[i]>='A' && num[i]<='F')
                    num[i]+=32;
                if((num[i]>='0' && num[i]<='9')||(num[i]>='a' && num[i]<='f')){
                    printf("%c",num[i]);
                    i++;
                }
            }
            if(e==3){
                if(num[i]>='0' && num[i]<='7'){
                    printf("%c",num[i]);
                    i++;
                }
            }
        }
        if(menu!=1){
            if((num[i]>='0' && num[i]<='9')||(num[i]=='-' && i==0)||(num[i]=='.' && ponto==0)){
                if(num[i]=='.')
                    ponto++;
                printf("%c",num[i]);
                i++;
            }
        }
        if(num[i]==8 && i>0){
            system("cls");
            num[i]=0;
            i--;
            if(num[i]=='.')
                ponto--;
            num[i]=0;
            idioma(0,0);
            if(num[0]!=0)
                printf("%s",num);
        }
        if(num[i]==27)
            return 27;
        if(num[i]==8)
            return 13;
    }while(num[i]!=13);
    if(num[0]==13){
        num[0]=48;
        num[1]=0;
    }else
        num[i]=0;
    numb=atof(num);
    system("cls");
    if(menu==0){
        if(e==1)
            numb=(numb-32)/1.8;
        if(e==2)
            numb=numb-273.15;
    }
    if(menu==1){
        if(e==0)
            decimal=atoi(num);
        if(e==1)
            for (j=1,i=strlen(num)-1,decimal=0;i>=0;decimal+=((num[i]-48)*j),i--,j*=2){}
        if(e==2)
            for (j=1,i=strlen(num)-1,decimal=0;i>=0;i--,j*=16){
                if (num[i]>57)
                    decimal+=((num[i]-87)*j);
                else
                    decimal+=((num[i]-48)*j);
            }
        if(e==3)
            for (j=1,i=strlen(num)-1,decimal=0;i>=0;decimal+=((num[i]-48)*j),i--,j*=8){}
    }
    if(menu==2){
        j=1;
        if(ponto==0){
            num[i]='.';
            num[i+1]=0;
        }
        i=0;
        do{
            num1[0]=num[i];
            i++;
        }while(num[i-1]<'1' && num[i-1]!=0);
        if(num[0]=='-'){
            num1[1]=num1[0];
            num1[0]='-';
            j++;
        }
        if(num1[0]==0 || (num1[0]=='-' && num1[1]==0)){
            num1[0]='0';
            j++;
        }
        num1[j]='.';
        for(j+=1;num[i]!=0;i++){
            if(num[i]!='.'){
                num1[j]=num[i];
                j++;
            }
        }
        for(i=0;num[i]<'1';i++){}
        for(j=0;num[j]!='.';j++){}
        expoente=j-i;
        if(j>i)
            expoente--;
        if(num1[0]=='0')
            expoente=0;
        j=strlen(num1)-1;
        while(num1[j]=='0'){
            num1[j]=0;
            j--;
        }
        if(num1[j]=='.')
            num1[j]=0;
        if(num1[0]==0)
            num1[0]='0';
        if(e>=0 && e<=6)
            expoente+=(24-e*3);
        if(e>=7 && e<=13)
            expoente+=(10-e);
        if(e>=14 && e<=20)
            expoente+=(36-e*3);
    }
    if(menu==3){
        if(e<=2)
            numb/=(24*pow(60,2-e));
        if(e==4)
            numb*=7;
        if(e==5)
            numb*=30;
        if(e>=6)
            numb*=(365*pow(10,e-6));
    }
    if(menu==4){
        if(e==1)
            numb/=3.6;
        if(e==2)
            numb/=1.94384;
    }
    if(menu==5){
        if(e==1)
            numb*=180;
        if(e==2)
            numb*=360;
        if(e==3)
            numb*=0.9;
    }
    if(menu==6){
        if(e==1)
            numb/=3.28084;
        if(e==2)
            numb/=0.000621371;
        if(e==3)
            numb/=1.09361;
        if(e==4)
            numb/=39.3701;
        if(e==5)
            numb/=(1.057*pow(10,-16));
    }
    if(menu==7){
        if(e==1)
            numb/=pow(3.28084,2);
        if(e==2)
            numb/=pow(0.000621371,2);
        if(e==3)
            numb/=pow(1.09361,2);
        if(e==4)
            numb/=pow(39.3701,2);
        if(e==5)
            numb/=0.0001;
    }
    if(menu==8){
        if(e==1)
            numb/=pow(3.28084,3);
        if(e==2)
            numb/=1000;
        if(e==3)
            numb/=pow(0.000621371,3);
        if(e==4)
            numb/=pow(1.09361,3);
        if(e==5)
            numb/=pow(39.3701,3);
    }
    conversao(tam,menu,unidades,e,numb,decimal,num,num1,expoente);
    idioma(-1,0);
    do{
        sair=getch();
    }while(sair!=13 && sair!=8 && sair!=27);
    return sair;
}
void conversao(const int tam,int menu,char unidades[1001],int e,float numb,int decimal,char num[101],char num1[101],int expoente){
    int i,j;
    char escolha[tam];
    for (i=0;i<tam;i++)
        escolha[i]=' ';
    escolha[e]=254;
    for(i=0,j=0;unidades[i]!=0;i++,j++){
        printf("%c ",escolha[j]);
        for(;unidades[i]!='|';i++)
            printf("%c",unidades[i]);
        switch(menu){
            case 0:
                switch(j){
                    case 0:printf(": %.2f\n",numb);break;
                    case 1:printf(": %.2f\n",1.8*numb+32);break;
                    case 2:printf(": %.2f\n",numb+273.15);break;
                }
                break;
            case 1:
                switch(j){
                    case 0:printf(": %d\n",decimal);break;
                    case 1:printf(": %s\n",itoa(decimal,num,2));break;
                    case 2:printf(": %s\n",itoa(decimal,num,16));break;
                    case 3:printf(": %s\n",itoa(decimal,num,8));break;
                }
                break;
            case 2:
                switch(j){
                    case 0:printf(": %s * 10^(%d)\n",num1,expoente-24);break;
                    case 1:printf(": %s * 10^(%d)\n",num1,expoente-21);break;
                    case 2:printf(":   %s * 10^(%d)\n",num1,expoente-18);break;
                    case 3:printf(":  %s * 10^(%d)\n",num1,expoente-15);break;
                    case 4:printf(":  %s * 10^(%d)\n",num1,expoente-12);break;
                    case 5:printf(":  %s * 10^(%d)\n",num1,expoente-9);break;
                    case 6:printf(":  %s * 10^(%d)\n",num1,expoente-6);break;
                    case 7:printf(": %s * 10^(%d)\n",num1,expoente-3);break;
                    case 8:printf(": %s * 10^(%d)\n",num1,expoente-2);break;
                    case 9:printf(": %s * 10^(%d)\n",num1,expoente-1);break;
                    case 10:idioma(-2,0);printf("%s * 10^(%d)\n",num1,expoente);break;
                    case 11:printf(":  %s * 10^(%d)\n",num1,expoente+1);break;
                    case 12:printf(": %s * 10^(%d)\n",num1,expoente+2);break;
                    case 13:printf(":  %s * 10^(%d)\n",num1,expoente+3);break;
                    case 14:printf(": %s * 10^(%d)\n",num1,expoente+6);break;
                    case 15:printf(":  %s * 10^(%d)\n",num1,expoente+9);break;
                    case 16:printf(":  %s * 10^(%d)\n",num1,expoente+12);break;
                    case 17:printf(": %s * 10^(%d)\n",num1,expoente+15);break;
                    case 18:printf(":  %s * 10^(%d)\n",num1,expoente+18);break;
                    case 19:printf(": %s * 10^(%d)\n",num1,expoente+21);break;
                    case 20:printf(": %s * 10^(%d)\n",num1,expoente+24);break;
                }
                break;
            case 3:
                switch(j){
                    case 0:printf(": %.5f\n",numb*86400);break;
                    case 1:printf(": %.5f\n",numb*1440);break;
                    case 2:printf(": %.5f\n",numb*24);break;
                    case 3:printf(": %.5f\n",numb);break;
                    case 4:printf(": %.5f\n",numb/7);break;
                    case 5:printf(": %.5f\n",numb/30);break;
                    case 6:printf(": %.5f\n",numb/365);break;
                    case 7:printf(": %.5f\n",numb/3650);break;
                    case 8:printf(": %.5f\n",numb/36500);break;
                    case 9:printf(": %.5f\n",numb/365000);break;
                }
                break;
            case 4:
                switch(j){
                    case 0:printf(": %.2f\n",numb);break;
                    case 1:printf(": %.2f\n",numb*3.6);break;
                    case 2:printf(": %.2f\n",numb*1.94384);break;
                }
                break;
            case 5:
                switch(j){
                    case 0:printf(": %.2f\n",numb);break;
                    case 1:printf(": %.2f(pi)\n",numb/180);break;
                    case 2:printf(": %.2f\n",numb/360);break;
                    case 3:printf(": %.2f\n",numb/0.9);break;
                }
                break;
            case 6:
                switch(j){
                    case 0:printf(": %.5f\n",numb);break;
                    case 1:printf(": %.5f\n",numb*3.28084);break;
                    case 2:printf(": %.5f\n",numb*0.000621371);break;
                    case 3:printf(": %.5f\n",numb*1.09361);break;
                    case 4:printf(": %.5f\n",numb*39.3701);break;
                    case 5:printf(": %.5f * 10^(-16)\n",numb*1.057);break;
                }
                break;
            case 7:
                switch(j){
                    case 0:printf(": %.5f\n",numb);break;
                    case 1:printf(": %.5f\n",numb*pow(3.28084,2));break;
                    case 2:printf(": %.5f\n",numb*pow(0.000621371,2));break;
                    case 3:printf(": %.5f\n",numb*pow(1.09361,2));break;
                    case 4:printf(": %.5f\n",numb*pow(39.3701,2));break;
                    case 5:printf(": %.5f\n",numb*0.0001);break;
                }
                break;
            case 8:
                switch(j){
                    case 0:printf(": %.5f\n",numb);break;
                    case 1:printf(": %.5f\n",numb*1000);break;
                    case 2:printf(": %.5f\n",numb*pow(3.28084,3));break;
                    case 3:printf(": %.5f\n",numb*pow(0.000621371,3));break;
                    case 4:printf(": %.5f\n",numb*pow(1.09361,3));break;
                    case 5:printf(": %.5f\n",numb*pow(39.3701,3));break;
                }
                break;
        }
    }
}
char temperatura(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(4,e)!=0;e++)
            unidades[e]=idioma(4,e);
        e=escolhas(3,3,unidades,0);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(3,0,unidades,e);
    }while(sair==13);
    return sair;
}
char bases(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(6,e)!=0;e++)
            unidades[e]=idioma(6,e);
        e=escolhas(4,5,unidades,0);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(4,1,unidades,e);
    }while(sair==13);
    return sair;
}
char prefixos(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(8,e)!=0;e++)
            unidades[e]=idioma(8,e);
        e=escolhas(21,7,unidades,10);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(21,2,unidades,e);
    }while(sair==13);
    return sair;
}
char tempo(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(10,e)!=0;e++)
            unidades[e]=idioma(10,e);
        e=escolhas(10,9,unidades,3);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(10,3,unidades,e);
    }while(sair==13);
    return sair;
}
char velocidade(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(12,e);e++)
            unidades[e]=idioma(12,e);
        e=escolhas(3,11,unidades,0);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(3,4,unidades,e);
    }while(sair==13);
    return sair;
}
char angulo(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(14,e)!=0;e++)
            unidades[e]=idioma(14,e);
        e=escolhas(4,13,unidades,0);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(4,5,unidades,e);
    }while(sair==13);
    return sair;
}
char comprimento(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(16,e)!=0;e++)
            unidades[e]=idioma(16,e);
        e=escolhas(6,15,unidades,0);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(6,6,unidades,e);
    }while(sair==13);
    return sair;
}
char area(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(18,e)!=0;e++)
            unidades[e]=idioma(18,e);
        e=escolhas(6,17,unidades,0);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(6,7,unidades,e);
    }while(sair==13);
    return sair;
}
char volume(void){
    char sair;
    do{
        int e;
        char unidades[1001]="";
        for(e=0;idioma(20,e)!=0;e++)
            unidades[e]=idioma(20,e);
        e=escolhas(7,19,unidades,0);
        if(e==-1)
            return 27;
        if(e==-2)
            return 8;
        sair=numero(7,8,unidades,e);
    }while(sair==13);
    return sair;
}
