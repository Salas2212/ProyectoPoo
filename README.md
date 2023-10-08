# Manual Técnico del Sistema de Gestión del Aeropuerto Alfonso Bonilla Aragón

En este manual técnico, presentamos el diseño y desarrollo de un sistema de gestión para el Aeropuerto Alfonso Bonilla Aragón. El sistema tiene como objetivo administrar diversos aspectos operativos del aeropuerto, incluyendo vuelos, pasajeros, tripulación, aeronaves y la asignación de puertas de embarque.


# Diagrama UML

En el presente enlace se encuentra el [Diagrama UML](https://github.com/Salas2212/ProyectoPoo/blob/b412becb1c086b48836f2a83dee6a9c3e6163b1e/Diagrama%20UML.pdf) del proyecto.

# Ejecución del programa
A continuación se mostrara un tutorial de como ejecutar el programa desde **gitbash**.
## **Paso 1: Clonar el Repositorio desde Git Bash**

Ve al directorio donde deseas clonar el repositorio y ejecuta el siguiente comando:
```bash
git clone URL_DEL_REPO
```
Debes reemplazar **URL_DEL_REPO** por la URL del repositorio de Git.

## **Paso 2: Navegar al Directorio del Proyecto**

Usa el comando `cd` para cambiar al directorio del proyecto:
```bash
cd NOMBRE_DEL_DIRECTORIO_DEL_PROYECTO
```
Debes reemplazar **NOMBRE_DEL_DIRECTORIO_DEL_PROYECTO**.

## **Paso 3: Compilar el Programa**

Para compilar el proyecto, debes utilizar un comando que compile varios archivo como siguiente:
```bash
g++ -o mi_programa main.cpp archivo1.cpp archivo2.cpp archivo3.cpp
```
Esto compilará todos los archivos fuente y generará un archivo ejecutable llamado `mi_programa` .

Cada archivo debes reemplazarlo y/o agregar mas:
|                | 				|
|----------------|------------|
|**PuertaDeEmbarque.cpp** | **SistemaPrincipal.cpp**|
|**Aeronave.cpp**| **TorreDeControl.cpp**|
|**Pasajero.cpp**| **Vuelo.cpp**|
|                | 				|


## **Paso 4: Ejecutar el Programa**

Una vez que hayas compilado con éxito el programa, puedes ejecutarlo desde la terminal de Git Bash usando el siguiente comando:
```bash
./mi_programa
```
Debes reemplazar `mi_programa` con el nombre del archivo que generaste en el paso anterior.

# Funcionamiento

Una vez hayas ejecutado el programa se te mostrara un menú como este:
```cpp
Seleccione la accion que desea realizar:
1. Comprar un vuelo.
2. Consultar puertas de embarque.
3. Consultar vuelos.
4. Ver opciones de administrador
0. Salir
```
La opción 1, 2 y 3 en un principio no están disponibles.
Para poder utilizarlas debe primero registrar **Tripulantes** en el sistema. Para lograr esto debe escoger la opción **4** escribiéndola en su teclado.
```cpp
4

Por favor, ingrese la contrasena de administrador:
aeropuerto2023
```
El programa le pedirá una contraseña, esta es solo para el personal autorizado del aeropuerto. La clave es **aeropuerto2023**. Tendrá 3 intentos si se equivoca.
```cpp
Seleccione la accion que desea realizar:
5. Agregar una nave.
6. Consultar informacion de las naves.
7. Editar la informacion de una nave.
8. Generar un vuelo.
9. Ingresar una tripulacion al sistema.
10. Consultar tripulaciones
11. Consultar historial de una puerta de embarque
12. Despachar un vuelo
0. Atras
```
Como puede observar los menús son muy intuitivos.

Ahora debe agregar una **Tripulación** al sistema eligiendo la opción **9**.

Este es un ejemplo de como agregar una tripulación:
```cpp
Desea usar datos guardados en las cookies? (S/N)N
Ingrese la nacionalidad:
Colombiana
Ingrese el url a su informacion medica:
https:www.infomedica.com
Ingrese el numero de su cedula:
1107936789
Ingrese su Nombre (solo uno):
Juan
Ingrese su apellido (solo uno):
Salas
Ingrese el numero de su fecha de nacimiento:
13/03/2005
Ingrese su genero:
Masculino
Ingrese su direccion:
Cra1-N°70-210
Ingrese su numero de telefono:
3015289340
Ingrese su correo:
micorreo@gmail.com
Ingrese el puesto:
34
Ingrese los anios de experiencia:
10
Ingrese la cantidad maxima de horas diarias:
14
Tripulacion guardada exitosamente
```
Asegúrese de no dejar espacios en cada respuesta.

Una vez agregada la tripulación deberá generar un vuelo seleccionando la opción **8**. Cabe resaltar que debe volver a entrar al menú de administrador con la contraseña.
```cpp
8
Digite la ciudad de destino
Cartagena
Digite la ciudad de origen
Cali
Digite la fecha del vuelo
27/10/2023
Las aeronaves disponibles son:
0. Helicoptero | autonomia: 14 | capacidad de pasajeros: 61
1. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
2. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
3. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
4. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
5. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
6. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
7. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
8. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
9. Helicoptero | autonomia: 22 | capacidad de pasajeros: 26
Por favor digite el numero de la aeronave a usar. (Para cancelar, digite -1)
2
Se ha escogido la aeronave 2:
Registro de marca: rxtkbs
Capacidad de pasajeros: 26
Velocidad maxima: 1056
Autonomia: 22
Anio de fabricacion: 1998
Estado: En servicio
Coordenadas: (-96.0044, -94.0986)

Informacion especifica:
Tipo = Helicoptero
Cantidad de rotores: 3
Capacidad de elevacion: 9171
Uso especifico: Combate


Existen 1 tripulaciones registradas en el sistema:
1: Salas: Cantidad maxima de horas: 14
Digite los codigos de los tripulantes a agregar separados por enter:
Si no desea agregar mas, digite 0
1
Agregado!
0
Vuelo generado con exito.
```
Este es un ejemplo de como generar el vuelo, tenga en cuenta que este es el trabajo de un administrador del aeropuerto.

Ahora ya podrá comprar un vuelo.
```cpp
Seleccione la accion que desea realizar:
1. Comprar un vuelo.
2. Consultar puertas de embarque.
3. Consultar vuelos.
4. Ver opciones de administrador
0. Salir
1
Para comprar un vuelo debe iniciar sesion.
Vamos a crear tu perfil.
Desea usar datos guardados en las cookies? (S/N)N
Ingrese la nacionalidad:
Colombiana
Ingrese el numero de maletas:
2
Ingrese el url a su informacion medica:
www.miinfomedica.com
Ingrese el numero de su cedula:
110446482
Ingrese su Nombre (solo uno):
Harold
Ingrese su apellido (solo uno):
Guerrero
Ingrese el numero de su fecha de nacimiento:
03/02/2001
Ingrese su genero:
Masculino
Ingrese su direccion:
Cra1-N°5-110
Ingrese su numero de telefono:
314689344
Ingrese su correo:
micorreo@gmail.com


Vale, ahora selecciona el vuelo que deseas comprar:
Existen 1 vuelos disponibles:
0. CaCa2732364 | Cali-Cartagena
Fecha: 27/10/2023. Puerta de embarque: 0 (Vuelos Nacionales).
Sillas disponibles: 26
(Digita el numero al principio del vuelo, o digita -1 para cancelar)
0
Compra realizada exitosamente.
```
> **Nota:** En este ejemplo se puede observar que el usuario debe registrarse para poder comprar el vuelo. Ahora podrá disfrutar de su viaje.

# Evidencias (Imágenes)
## Menús principales
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160611530858057829/image.png?ex=65354ab8&is=6522d5b8&hm=8b0dddace8d1a3d38291969a083fd2a2a36b32df279a29e3074a8941bc74b618&)

## 1.Comprar Vuelos
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160610125619417098/image.png?ex=65354969&is=6522d469&hm=cec9736c6f14f9da7f158bfb2fadfb71d40f79a200cc75ce7cb4cc0d994254a9&)
## 2. Consultar Puertas de Embarque
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160611066645069844/image.png?ex=65354a49&is=6522d549&hm=b3602c0cfd07db823553c69f71a8e71ebc0bc13cb4dcfd9690cbe690f2375c17&)
## 3. Consultar Vuelos
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160611299537977517/image.png?ex=65354a80&is=6522d580&hm=6c5e7dfc90ad060c2ca7b161ba1c977e0599fd7288d928208305bdf40f87008f&)
## 4. Ver Opciones de Administrador
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160609104180555880/image.png?ex=65354875&is=6522d375&hm=3f3ecd371713d72b28d801249de198aac8c371d4fe24d841414916102d5717ef&)
## 5. Agregar Nave
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160613713599021116/image.png?ex=65354cc0&is=6522d7c0&hm=d94f21f6b1d53b2ecbe1ac9c034584a1c5f887d60b35e03ec4bc98ccafbf7aea&)
## 6. Información de las naves
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160609283361214525/image.png?ex=653548a0&is=6522d3a0&hm=983c34dbcaa6ef11ab259ef90b5aaf7f3c8e536f2f971fabb8a7de7d69873190&)
## 7. Editar Información de la Nave
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160614006545993728/image.png?ex=65354d06&is=6522d806&hm=5b2aa43506d17e4154026209eccaa00ff11850e411f31d397559dec55be7850c&)
## 8.Generar Vuelos
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160609482192191569/image.png?ex=653548cf&is=6522d3cf&hm=464b4fd5af4cefc09d52fb35b4f2a53be786f6fd531ae8aeea73ba75f7a9029f&)
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160609580653490246/image.png?ex=653548e7&is=6522d3e7&hm=519f1c27f13914c164de00d52991eb7293b1ae696bfa1148a1b934871b269131&)
## 9. Agregar Tripulación
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160608668119744532/image.png?ex=6535480d&is=6522d30d&hm=9478ae891e802d167d6d3a20f725b923bafca2877dd09c3cdcb23397b8ce2d4c&)
## 10. Consultar Tripulaciones
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160614504112066691/image.png?ex=65354d7c&is=6522d87c&hm=c1e371c8ce0ba826ff32e595cb0177ef9b4061ab6b388c8124b182ab2a9ed36e&)
## 11. Consultar Historial de una Puerta de Embarque
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160629433812660365/image.png?ex=65355b64&is=6522e664&hm=d87aeaad2bd11f630a00235d96b1e87d19f6f98fc50a0777aaf051d1f1711921&)
## 12. Despachar un Vuelo
![enter image description here](https://cdn.discordapp.com/attachments/1068328195427942430/1160616707568697524/image.png?ex=65354f8a&is=6522da8a&hm=21e4797a11f12bd2564fff4e40523515b88b0e49157920a6409ac3523c14f20f&)

