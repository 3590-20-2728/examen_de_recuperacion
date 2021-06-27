#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Marca
{
	string Marca;

public: Marcas() {
}
public: Marcas(string mar_marca) {
	Marca = mar_marca;
}

	  // METODOS
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getconectar()) {
			  string  insertar = "INSERT INTO marcas(Marca) VALUES ('" + Marca + "')";
			  const char* i = insertar.c_str();
			  // executar el query
			  q_estado = mysql_query(cn.getconectar(), i);
			  if (!q_estado) {
				  cout << "Ingreso Exitoso ..." << endl;
			  }
			  else {
				  cout << " xxx Error al Ingresar  xxx" << endl;
			  }
		  }
		  else {
			  cout << " xxx Error en la Conexion xxxx" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  void mostrar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getconectar()) {

			  cout << "------------ Datos de Marcas ------------" << endl;
			  string consulta = "select * from marcas";
			  const char* nuevaMarca = consulta.c_str();
			  q_estado = mysql_query(cn.getconectar(), nuevaMarca);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getconectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << "," << fila[1] << endl;
				  }

			  }
			  else {
				  cout << " xxx Error al Consultar  xxx" << endl;
			  }
		  }
		  else {
			  cout << " xxx Error en la Conexion xxxx" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  void eliminar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();

		  cn.abrir_conexion();
		  string e;
		  cout << "Ingrese el idMarca a eliminar: ";
		  cin >> e;
		  string eliminar = "delete from supermercado.marcas where idMarca= '" + e + "'";
		  const char* f = eliminar.c_str();
		  q_estado = mysql_query(cn.getconectar(), f);

		  if (!q_estado) {
			  cout << "Ingreso Exitoso..." << endl;
		  }
		  else {
			  cout << "**** Error al ingresar ****" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  void actualizar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();

		  cn.abrir_conexion();
		  string id;
		  string n;

		  cout << "Ingrese el ID a Editar: ";
		  cin >> id;
		  cout << "Ingrese nueva Marca: ";
		  cin >> n;
		  string editar = "update marcas set Marca= '" + n + "' where idMarca='" + id + "'";
		  const char* c = editar.c_str();
		  q_estado = mysql_query(cn.getconectar(), c);

		  if (!q_estado) {
			  cout << "Ingreso Exitoso..." << endl;
		  }
		  else {
			  cout << "**** Error al ingresar ****" << endl;
		  }
		  cn.cerrar_conexion();

	  }

};

