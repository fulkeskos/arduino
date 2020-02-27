import httplib2
conn = httplib2.Http()
class TsConexion:

    def correcto(nombre):
        print(nombre)
        conn.request("https://api.thingspeak.com/update?api_key=A29IIC7822BE1KF4&field1="+nombre)
    def incorrecto():
        print("error de ingreso")
        conn.request("https://api.thingspeak.com/update?api_key=A29IIC7822BE1KF4&field1=Intento de entrada" )


