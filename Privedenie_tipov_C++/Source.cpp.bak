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
	virtual ~IVehicle() { // здесь создаем виртуальный деструктор, чтобы не было утечки пам€ти
		
	}

};


class Tram :public IVehicle {
public:
	Tram(const std::string& type, int maxSpeed) : _type(type), _maxSpeed(maxSpeed) {};
	 ~Tram() {
		
	}

	void showType() override{ // создаем override дл€ перегрузки функции ( переопределени€ ) 
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


void infoIVehicle(const std::vector<IVehicle*>& vehicles) { // мы передаем по ссылке дл€ экономии пам€ти ( 8 байт вместо копировани€ вектора ) 

	for (size_t i = 0; i < vehicles.size(); i++) {
		vehicles[i]->showType();
		vehicles[i]->showMaxSpeed();
		std::cout << sizeof(vehicles); // функци€ дл€ определени€ размера, в данном случае ссылки на вектор vehicles

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


	std::cout << "\n\n\n“ема зан€ти€:\nѕереопределение типов \n\n\n\n" << std::endl;



	Parent parent;
	Child child;

	//int a = 5;
	//double b = (double)a; // — style приведение типов
	//double b1 = double(a); // 




	//upcast - не€вное преобразование разрешено
	Parent* pParent = &child; // мы child превращаем в родител€ ( patrnt ). ћетоды child пропадут и останутс€ только методы parent

	//downcast - требуетс€ €вное преобразование типа
	Child* pChild = (Child*)&parent; // (мы parent превращаем в child)   -   (Child*)parent*
	
	pParent->Sleep();
	pChild->Sleep();
	foo(*pParent);

}