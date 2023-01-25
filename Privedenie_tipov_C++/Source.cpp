#include<iostream>
#include <string>
#include <vector>
#include<fstream>


class Parent {
public:
	virtual void Sleep() {
		std::cout << "sleep() " << std::endl;
	}

};

class Child :public Parent {
public:
	void Sleep() override{
		std::cout << "Child sleep() " << std::endl;
	}
	void gotoSchool() {
		std::cout << "gotoSchool()" << std::endl;
	}
};












class IVehicle
{
public:    //в абстрактном классе мы не создаем конструктор, нужно чтобы был по умолчанию
	virtual void showType()  = 0;
	virtual void showMaxSpeed()  = 0;
	virtual ~IVehicle() { // здесь создаем виртуальный деструктор, чтобы не было утечки памяти
		
	}

};


class Tram :public IVehicle {
public:
	Tram(const std::string& type, int maxSpeed) : _type(type), _maxSpeed(maxSpeed) {};
	 ~Tram() {
		
	}

	void showType() override{ // создаем override для перегрузки функции ( переопределения ) 
		std::cout << "This is Tram" << std::endl;
	}
	void showMaxSpeed() override {
		std::cout << _maxSpeed << std::endl;
	}
	
private:
	std::string _type;
	int _maxSpeed;
};

class Electrobus :public IVehicle {
public:
	Electrobus(const std::string& type, int maxSpeed) : _type(type), _maxSpeed(maxSpeed) {};
	 ~Electrobus() {
	
	}

	void showType() override {
		std::cout << "This is Electrobus" << std::endl;
	}

	void showMaxSpeed() override {
		std::cout << _maxSpeed << std::endl;
	}


private:
	std::string _type;
	int _maxSpeed;
};


void infoIVehicle(const std::vector<IVehicle*>& vehicles) { // мы передаем по ссылке для экономии памяти ( 8 байт вместо копирования вектора ) 

	for (size_t i = 0; i < vehicles.size(); i++) {
		vehicles[i]->showType();
		vehicles[i]->showMaxSpeed();
		std::cout << sizeof(vehicles); // функция для определения размера, в данном случае ссылки на вектор vehicles

	}
}



void foo(Parent deried_obj) {
	std::cout << "Inside Foo()" << std::endl;
	deried_obj.Sleep();
}

int main() {
	setlocale(LC_ALL, "Russian");

	IVehicle* a = new Tram("Street", 50); // создаем интерфейс 
	IVehicle* b = new Electrobus("Street", 100); // используем указатель на класс, так как наследуемый класс принимает родительский + свои методы


	std::vector<IVehicle*> vehicles; // создаем вектор 
	vehicles.push_back(a); // пушим в вектор
	vehicles.push_back(b);
	

	std::cout << "See transport in the city:" << std::endl;

	infoIVehicle(vehicles);




	delete a;
	delete b;


	std::cout << "\n\n\nТема занятия:\nПереопределение типов \n\n\n\n" << std::endl;



	Parent parent;
	Child child;

	//int a = 5;
	//double b = (double)a; // С style приведение типов
	//double b1 = double(a); // 




	//upcast - неявное преобразование разрешено
	Parent* pParent = &child; // мы child превращаем в родителя ( patrnt ). Методы child пропадут и останутся только методы parent

	//downcast - требуется явное преобразование типа
	Child* pChild = (Child*)&parent; // (мы parent превращаем в child)   -   (Child*)parent*
	
	pParent->Sleep();
	pChild->Sleep();
	foo(*pParent);

}