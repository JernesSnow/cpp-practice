#include <iostream>
/*Clase Vehiculo
- método virtual mover()

Clase Helicoptero : public Vehiculo
- sobrescribe mover()
- muestra "El avion vuela"

Clase Barco : public Vehiculo
- sobrescribe mover()
- muestra "El barco navega"*/
class Vehiculo {
public:
	virtual void mover() = 0; //al convertir el virtual puro se transforma a una clase abstracta
	virtual void Accelerar() = 0;
};
void iniciarMovimiento(Vehiculo& vehiculo) {
	vehiculo.mover();
}
class Helicoptero :public Vehiculo {
public:
	void mover() override {
		std::cout << "El helicoptero vuela" << std::endl;
	}
};
class Barco :public Vehiculo{
public:
	void mover() override {
		std::cout << "El barco navega" << std::endl;
	}
};

class Motor {
private: 
	bool encendido;
public:
	Motor() :encendido(false) {

	}
	void encender() {
		encendido = true;
	}
	void apagar() {
		encendido = false;
	}
	bool estaEncendido()const {
		return encendido;
	}

};
class Avion {
private:
	int altitud, velocidad;
	Motor motor;
public:
	Avion() :altitud(0), velocidad(0){
		
	}


	Avion(int Naltitud, int Nvelocidad) :altitud(0), velocidad(0) {
		setAltitud(Naltitud);
		setVelocidad(Nvelocidad);

	}
	void encenderMotor() {
		motor.encender();
	}
	void apagarMotor() {
		motor.apagar();
	}
	bool motorEstaEncendido() const {
		return motor.estaEncendido();
	}
	
	void setAltitud(int Naltitud) {
		if (Naltitud >= 0) {
			altitud = Naltitud;
		}
		else {
			std::cout << "no se aceptan numeros negativos" << std::endl;
		}
	}
	void setVelocidad(int Nvelocidad) {
		if (Nvelocidad >= 0) {
			velocidad = Nvelocidad;
		}
		else {
			std::cout << "no se aceptan numeros negativos" << std::endl;
		}
	}

	
	int  getVelocidad() const {
		return velocidad;
	}
	int  getAltitud() const {
		return altitud;
	}
	void  mostrarDatos() const {
		std::cout << "el avion va a un altitud de: " << altitud << std::endl;
		std::cout << "el avion va a una velocidad de: " << velocidad << std::endl;
	}
};

int main()
{

	Avion avion1;
	avion1.mostrarDatos();
	Avion avion2(100, 90);
	//avion2.mostrarDatos();
	avion2.setAltitud(3000);
	avion2.setVelocidad(3500);
	std::cout << avion2.getAltitud() << std::endl;
	std::cout << avion2.getVelocidad() << std::endl;

	if (avion1.motorEstaEncendido()) {
		std::cout << "Encendido"<<std::endl;
	}
	else {
		std::cout << "Apagado"<<std::endl;
	}
	avion2.encenderMotor();
	if (avion2.motorEstaEncendido()) {
		std::cout << "Encendido"<<std::endl;
	}
	else {
		std::cout << "Apagado" << std::endl;
	}
	Helicoptero helicoptero;
	iniciarMovimiento(helicoptero);
	Barco barco;
	iniciarMovimiento(barco);

}
