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
	int aantal_letters=rand() % NAAM_LEN;

	nummer=*getal;
	for(i=0;i<aantal_letters; i++)
		naam[i]='A' + rand() % 26;
	naam[i]=0;
}

void persoon::show_persoon(){
	cout<<naam<<endl;
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

pers = new personen(3);

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
		cout<<"kies :"; cin>>keuze;
		cout<<endl;

		switch(keuze){
		case 0: cout<<"end"<<endl;break;
			break;
		case 1: if ((err=pers->vul_personen())!=okS)errMsg(err);
		break;
		case 2: if ((err=pers->copy_tabel())!=okS)errMsg(err);
		break;
		case 3: if ((err=pers->show_tabel1())!=okS)errMsg(err);
		break;
		case 4: if ((err=pers->show_tabel2())!=okS)errMsg(err);
		break;
		default: cout<<"onjuiste keuze "<<endl;;
		}//switch
	}
	while(keuze);
	return 0;
}

