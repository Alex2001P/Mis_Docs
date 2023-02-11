
function objetos1() { //creamos nuestra función con el nombre de objetos.
    esto.r = función () {}; //creamos nuestro metodo.
}
// Instanciando las clases llamadas objetos
var num1 = new objetos1();
var num2 = new objetos1();
var num3 = new objetos1();
consola.log(Objeto.es(num1.r, numero2.r, numero3.r)); // Mostramos nuestros resultados en nuestra consola, esto con el fin de evaluar si pronto verdaderos o falsos por medio de un Object.is,
FALSO

function objetos2() { //Creamos una nueva clase
}
objetos2.prototipo.f = función() {}; // Creamos un Prototipo. similando al anterior.
var num4 = nuevos objetos2();
var num5 = nuevos objetos2();
var num6 = nuevos objetos2();
console.log(Object.is(num4.r, num5.r, num6.r)) // se realiza la conparacion con la clase anterior en este caso es distinto al anaterio.
verdadero

function objetos3() { //Creamos una tercera clase con nombre de objetos 3.
}
var num7 = new objetos3();
var num8 = new objetos3();
var num9 = new objetos3();
console.log(Object.is(num7.r, num8.r, num9.r)) // en esta presetacion nuestro codigo no tiene que es verdader pero automaticamente la consola ve que se cumple la condicion al primero es decir que es distinto .
