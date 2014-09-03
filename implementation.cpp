/*
 * implementation.cpp
 *
 *  Created on: 31 aug. 2014
 *      Author: Sander
 */

#include <iostream>
#include <string.h>
#include "interface.hpp"

using namespace std;
//////////////class persoon////////////////////////////
void persoon::vul_persoon(int *getal){
	int i;
	int aantal_letters=NAAM_LEN;//rand() % NAAM_LEN;

	nummer=*getal;
	for(i=0;i<aantal_letters; i++)
		naam[i]='1' + rand() % 9;
	naam[i]=0;
}

void persoon::show_persoon(){
	cout<<naam<<endl;
}
void persoon::give_persoon(char *naam){//plaatst naam in object
	strncpy(this->naam,naam,NAAM_LEN);
}
void persoon::return_persoon(char *naam){//geeft naam terug uit object
	strncpy(naam,this->naam,NAAM_LEN);

}
//////////////class personen///////////////////////////
personen::personen(int max_personen){//constructor 2, max wordt meegegeven tijdens decl. van een var van t typer persoon.
	tabel1=new persoon[max_personen];//pointer tabel1 wijst naar array van type persoon
	tabel2=new persoon[max_personen];
	aantal_personen=0;
	this->max_personen=max_personen;//meegeven variabele max wordt gekopieerd naar class var: max
}

sig personen::vul_personen(){
	if(aantal_personen>max_personen)return tabel1_vol;
		for (aantal_personen=0;aantal_personen<max_personen;aantal_personen++){
			tabel1[aantal_personen].vul_persoon(&aantal_personen);
		}
		if(aantal_personen==max_personen-1)cout<<"tabel 1 gevuld";
		return okS;
}

sig personen::copy_tabel(){
	if(aantal_personen==0)return tabel1_leeg;
		for(int aantal_personen=0;aantal_personen<max_personen;aantal_personen++){
			tabel2[aantal_personen]=tabel1[aantal_personen];
		}
		return okS;
}

sig personen::show_tabel1(){
	if(aantal_personen==0)return tabel1_leeg;
		for(int aantal_personen=0;aantal_personen<max_personen;aantal_personen++){
			tabel1[aantal_personen].show_persoon();
		}
		return okS;
}

sig personen::show_tabel2(){
	if(aantal_personen==0)return tabel2_leeg;
		for(int aantal_personen=0;aantal_personen<max_personen;aantal_personen++){
			tabel2[aantal_personen].show_persoon();
		}
		return okS;
}

sig personen::sort_bubble(){
	char hold[NAAM_LEN],naam1[NAAM_LEN],naam2[NAAM_LEN];

	for(int passes=0;passes<max_personen-1;passes++){
			for(int n=0;n<max_personen-passes-1;n++){
					tabel1[n].return_persoon(naam1);
					tabel1[n+1].return_persoon(naam2);

					cout<<"naam 1 "<<naam1<<endl;
					cout<<"naam 2 "<<naam2<<endl;

				if (naam1[NAAM_LEN] > naam2[NAAM_LEN]){
				//if ((tabel1[n].return_persoon()) > (tabel1[n+1].return_persoon())){
					tabel1[n].return_persoon(hold);
					tabel1[n]=tabel1[n+1];
					tabel1[n+1].give_persoon(hold);
					}
			}
	}
	return okS;
}

//error handling
void errMsg(int code){
	switch(code){
	case okS: cout<<"oke"<<endl;
	break;
	case tabel1_leeg: cout<<"tabel 1 is leeg"<<endl;
	break;
	case tabel2_leeg: cout<<"tabel 2 is leeg"<<endl;
	break;
	default: cout<<"error niet geimplementeerd"<<endl;
	}
}


int main(){
personen *pers;

pers = new personen(AANTAL_PERSONEN);

int keuze;
sig err;

	do{
		cout<<endl;
		cout<<"menu: ;"<<endl;
		cout<<"0: einde "<<endl;
		cout<<"1: vul tabel 1"<<endl;
		cout<<"2: copy tabel 1 naar tabel 2 "<<endl;
		cout<<"3: show tabel 1"<<endl;
		cout<<"4: show tabel 2: "<<endl;
		cout<<"5: bubble sort: "<<endl;
		cout<<"kies :"; cin>>keuze;
		cout<<endl;

		switch(keuze){
		case 0: cout<<"end"<<endl;break;
			break;
		case 1: if ((err=pers->vul_personen())!=okS)errMsg(err);
					pers->show_tabel1();
		break;
		case 2: if ((err=pers->copy_tabel())!=okS)errMsg(err);
		break;
		case 3: if ((err=pers->show_tabel1())!=okS)errMsg(err);
		break;
		case 4: if ((err=pers->show_tabel2())!=okS)errMsg(err);
		break;
		case 5: if ((err=pers->sort_bubble())!=okS)errMsg(err);
					pers->show_tabel1();
		break;
		default: cout<<"onjuiste keuze "<<endl;;
		}//switch
	}
	while(keuze);
	return 0;
}

