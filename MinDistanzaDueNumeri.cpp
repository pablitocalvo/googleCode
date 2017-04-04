/*
 * MinDistanzaDueNumeri.cpp
 * 
 * Copyright 2017 Paolo <paolo@NoteBookPaoloD7>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <string>
using namespace std ;

int main(int argc, char **argv)
{	const int NC = 18 ;
	string n1 , n2 ;
	//TO DO :  leggere da input e controllare i caratteri
	/*TO DO :  normalizzare a NC cifre 
	 *         ossia aggiungere zeri non significati sino a NC cifre
	*/
	//TO DO :  ottimizzare per evitare la normalizzazione
	
	
	// pre semplicità li "normalizzo a NC cifre"
	
	// "123456789012345678"   // righello ...
	n1="0??32???2??3?5???1";
	n2="0??31???2??3?5???1";


	cout << n1 << endl;
	cout << n2 << endl<< endl;

			
	int i = 0; 
	while (i<NC)
	{	
		
		if  ( ( n1[i] == '?') and  ( n2[i] == '?') )
			{  
				n1[i] = n2[i] = '0';
				i++ ; continue ;
			} 	
			
		if  ( ( n1[i] == '?') and  ( n2[i] != '?') )
			{  
				n1[i] = n2[i] ;
				i++ ; continue ;
			}
		
		if  ( ( n1[i] != '?') and  ( n2[i] == '?') )
			{  
				n2[i] = n1[i] ;
				i++ ; continue ;
			}

		if  ( ( n1[i] == n2[i] ) )
			{  
				i++ ; continue ;
			}
		else 
			break;
	}
	
	if (i == NC )  // i numeri sono [stati resi] uguali 
	{		cout << n1 << endl;
			cout << n2 << endl;
			cout << "distanza " << 0;
			return 0; 
	}
		
	/* c'è ne uno che variando i ? il suo minimo 
	 è più grande del massimo dell'altro variando i ?.
	*/
	
	if ( n1[i] > n2[i] )      			// grazie al codice ascii !!!
	{	// n1 è sicuramente più grande ...
		// minimizzo n1  e massimizzo n2	
	
		while ( i < NC )
		{ 	if (  n1[i] == '?' )  n1[i] = '0' ;
			if (  n2[i] == '?' )  n2[i] = '9' ;
			i++;
		}
	}
	else
	{	// n2 è sicuramente più grande ...
		// minimizzo n2  e massimizzo n1	
	
		while ( i < NC )
		{ 	if (  n2[i] == '?' )  n2[i] = '0' ;
			if (  n1[i] == '?' )  n1[i] = '9' ;
			i++;
		}
	}
		
			 
	cout << n1 << endl;
	cout << n2 << endl;
	cout << "distanza non so calcolarla ancora " ;
	return 0;

}

