#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;


class Productos
{
	class Productos {

	string idProducto, Producto, idMarca, Descripcion, Precio_costo, Precio_venta, Existencia;

public: Productos() {
}
	public: Productos(string id_Producto, string prod_producto, string idmar_producto, string desc_producto, string preco_producto, string preve_producto, string exis_producto, {
		idProducto = id_Producto;
	Producto = prod_producto;
	idMarca = idmar_producto;
	Descripcion = desc_producto;
	Precio_costo = preco_producto;
	Precio_venta = preve_producto;
	Existencia = exis_producto;
	}

	  // METODOS
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getconectar()) {
			  string  insertar = "INSERT INTO productos(idProducto,Producto,idMarca,Descripcion,Precio_costo,Precio_venta,Existencia) VALUES ('"+idProducto+ "','" + Producto + "','" + idMarca + "','" + Descripcion + "','" + Precio_costo + "','" + Precio_venta + "','" + Existencia + ";
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
			  string consulta = "select * from productos";
			  const char* nuevoProducto = consulta.c_str();
			  q_estado = mysql_query(cn.getconectar(), nuevoProducto);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getconectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6]<<" ,"<< fila[7]<< endl;
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
		  cout << "Ingrese el idProducto a eliminar: ";
		  cin >> e;
		  string eliminar = "delete from examen_recuperacion.productos where idProducto= '" + e + "'";
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
		  string m;
		  string d;
		  string pc;
		  string pv;
		  string ex;

		  cout << "Ingrese el ID a Editar: ";
		  cin >> id;
		  cout << "Ingrese nuevo Producto: ";
		  cin >> n;
		  cout << "Ingrese nuevo ID Marca: ";
		  cin >> m;
		  cout << "Ingrese nueva Descripcion: ";
		  cin >> d;
		  cout << "Ingrese nuevo Precio de Costo: ";
		  cin >> pc;
		  cout << "Ingrese nuevo Predio de Venta: ";
		  cin >> pv;
		  cout << "Ingrese nueva Existencia: ";
		  cin >> ex;
		  string editar = "update productos set Producto= '" + n + "', idMarca = '" + m + "', Descripcion= '" + d + "', Precio_costo= '" + pc + "', Precio_venta= '" + pv + "', Existencia = '" + ex + "'";
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
};


