
#include <iostream>
#include <stdlib.h>

using namespace std;

class Ficha{
		private:
		string color;
		int pos_x,pos_y;
		
		public:
		
		Ficha(){
			this->color="vacia";
			pos_x= 0; pos_y= 0;
		}
		
		void set_color(string color){
				this->color=color;
		}
		
		void set_posx(int x){
			pos_x=x;
		}

		void set_posy(int y){
			pos_y=y;
		}

		string get_color(){
			return this->color;			
			}
		
		int get_posx(){
			return pos_x;
			}
			
		int get_posy(){
			return pos_y;
			}
			
		void eliminar_pieza(){
			this->color="vacia";
			this->pos_x=0;
			this->pos_y=0;
		}
};

class Tablero{
		private:
		Ficha Espacio[8][8];
		
		public:
		
		Tablero(){
			Ficha pieza;
			for (int i=0;i<8;i++){
				for (int j=0;j<8;j++){
					Espacio[i][j]= pieza;
					}
			}
		}
		
		void iniciar_blancas(){
			int acum=0;
			for (int i=0;i<3;i++){
				for (int j=0;j<8;j+=2){
					Espacio[i][j+acum].set_color("blanca");
					Espacio[i][j+acum].set_posx(j);
					Espacio[i][j+acum].set_posy(i);
					}
					if (acum==0)
					acum++;
					else
					acum=0;
			}
		}
		
		void iniciar_negras(){
			int acum=0;
			for (int i=7;i>4;i--){
				for (int j=7;j>0;j-=2){
					Espacio[i][j-acum].set_color("negra");
					Espacio[i][j-acum].set_posx(j);
					Espacio[i][j-acum].set_posy(i);
					}
					if (acum==0)
					acum++;
					else
					acum=0;
			}
		}
		//work in progress
		void Mover_Pieza(){
			int x,y;
			Ficha pieza;
			int resp;
			cout<<"Ingrese el valor x y luego el valor y"<<endl;
			cin>>x>>y;
			if(Espacio[y][x].get_color()=="vacia"){
				cout<<"Elija un espacio que no este vacio"<<endl;
				return;
				}
			pieza=Espacio[y][x];
			Espacio[y][x].eliminar_pieza();
			cout<<"Desea moverse diagona izquierda(1) o diagonal derecha(2)?"<<endl;
			cin>>resp;
			if(resp==1){
				if(pieza.get_color()=="blanca"){
					if(Espacio[y+1][x-1].get_color()=="negra"){
						Espacio[y+1][x-1].eliminar_pieza();
						Espacio[y+2][x-2]=pieza;
					}
					else
					Espacio[y+1][x-1]=pieza;
				}
					
				if(pieza.get_color()=="negra"){
					if(Espacio[y-1][x-1].get_color()=="blanca"){
						Espacio[y-1][x-1].eliminar_pieza();
						Espacio[y-2][x-2]=pieza;
					}
					else
					Espacio[y-1][x-1]=pieza;
				}
			}
			if(resp==2){
				if(pieza.get_color()=="blanca"){
			    	if(Espacio[y+1][x+1].get_color()=="negra"){
						Espacio[y+1][x+1].eliminar_pieza();
						Espacio[y+2][x+2]=pieza;
					}
					else
					Espacio[y+1][x+1]=pieza;
				}
				if(pieza.get_color()=="negra"){
					if(Espacio[y-1][x+1].get_color()=="blanca"){
						Espacio[y-1][x+1].eliminar_pieza();
						Espacio[y-2][x+2]=pieza;
					}
					else
					Espacio[y-1][x+1]=pieza;
				}
			}						
		}
		//funcion mover necesita condicionales de acciones al comer pieza, para los casos de ficha negra, casos de no salirse del tablero
		void Imprimir(){
			int i,j;
			for (i=0;i<8;i++){
				for (j=0;j<8;j++){
					if(Espacio[i][j].get_color()=="blanca")
					cout<<"2"<<"\t";
					if(Espacio[i][j].get_color()=="negra")
					cout<<"1"<<"\t";
					if(Espacio[i][j].get_color()=="vacia")
					cout<<"0"<<"\t";
					}
			cout<<endl<<endl;		
			}			
		}
};


int main(int argc, char **argv)
{
	int win=0;
	Tablero hola;
	hola.iniciar_blancas();
	hola.iniciar_negras();
	while(win==0){
		hola.Imprimir();
		hola.Mover_Pieza();
		system("cls");
		}
	
	return 0;
}
