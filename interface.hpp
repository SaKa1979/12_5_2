/*
 * interface.hpp
 *
 *  Created on: 31 aug. 2014
 *      Author: Sander
 */

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#define NAAM_LEN 10
typedef enum sig{okS, tabel1_leeg, tabel2_leeg, tabel1_vol} sig; //creeer sig type enum

class persoon{
	char naam[NAAM_LEN];
	int nummer;

public:
	void vul_persoon(int *getal);
	void show_persoon();
}; //end class persoon

class personen{
	int aantal_personen;//huidige aantal personen in tabel
	int max_personen;//maximaal aantal personen
	persoon *tabel1;//pointer van type persoon
	persoon *tabel2;

public:
	personen(){aantal_personen=0;max_personen=0;}//constructor 1
	personen(int); //constructor 2
	~personen() {
		delete []tabel1;
		delete []tabel2;
	} //destructor


	sig vul_personen();
	sig copy_tabel();
	sig show_tabel1();
	sig show_tabel2();
}; //end class personen




#endif /* INTERFACE_HPP_ */
