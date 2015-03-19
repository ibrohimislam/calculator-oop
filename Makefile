all: main
main: Arab.cc Bilangan.cc Calculator.cc Driver.cc Expression.cc Memori.cc Operator.cc Parser.cc Penghitung.cc Perintah.cc Romawi.cc
	g++ Arab.cc Bilangan.cc Calculator.cc Driver.cc Expression.cc Memori.cc Operator.cc Parser.cc Penghitung.cc Perintah.cc Romawi.cc -o main -w
