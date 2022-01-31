all: a.out

a.out: main.o Ehtesham.o EmployeeRequest.o Employee.o CateringOrder.o Catering.o MenuItem.o functions.o 
	g++ -std=c++11 main.o Ehtesham.o EmployeeRequest.o Employee.o CateringOrder.o Catering.o MenuItem.o functions.o 

main.o: main.cpp Ehtesham.hpp
	g++ -std=c++11 -c main.cpp

Ehtesham.o: Ehtesham.cpp Ehtesham.hpp Catering.hpp CateringOrder.hpp functions.hpp
	g++ -std=c++11 -c Ehtesham.cpp

Employee.o: Employee.cpp Employee.hpp functions.hpp
	g++ -std=c++11 -c Employee.cpp

Catering.o: Catering.cpp Catering.hpp MenuItem.hpp EmployeeRequest.hpp CateringOrder.hpp
	g++ -std=c++11 -c Catering.cpp

CateringOrder.o: CateringOrder.cpp CateringOrder.hpp EmployeeRequest.hpp MenuItem.hpp
	g++ -std=c++11 -c CateringOrder.cpp 

EmployeeRequest.o: EmployeeRequest.cpp EmployeeRequest.hpp Employee.hpp MenuItem.hpp functions.hpp 
	g++ -std=c++11 -c EmployeeRequest.cpp

MenuItem.o: MenuItem.cpp MenuItem.hpp functions.hpp
	g++ -std=c++11 -c MenuItem.cpp

functions.o: functions.cpp functions.hpp
	g++ -std=c++11 -c functions.cpp

clean:
	rm *.o
	rm a.out
