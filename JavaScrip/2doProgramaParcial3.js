/* Para la creacion de nuestra tabla Hash hacemos lo siguiente */
/** Creamos una clase en la que nos contenga el constructor para crear un
array con una inicializacion de 0 a 50 */
class TablaHash {
    constructor(){ /**Constructor */
    this.tabla = new Array(50); /**Array */
    this.tamano = 0; /**Inicializacion 0 */
    }

/** Creamos un metodo para que no haga un recorrido de Tahash*/
Tahash(llave) {
    let hash = 0; /**Iniciaizmaos has en 0 */
    for (let i = 0; i < llave.length; i++){ /**Usamos un bucle for para que empieze de cero hasta que sea mayor a la llave sumara 1 en 1 esto solo del lado derecho*/
    
    hash += llave.charCodeAt(i); /** Realizamos una suma de todas nuestra llaves, para eso usmaos el charCodeat para obetener el codigo */
    }
        return hash % this.tabla.length; /** Retornamos los datos segun los codigos obtenidos */
    }

    /** Usamos este set para establecer elvalor de nuestra varible */
    set(llave, valor) {
    const indice = this.Tahash(llave); /**Un indice constante donde se sumara los datos de nuestra llave */
    this.tabla[indice] = [llave, valor]; /** Los datos que guardemos como llave y valor seran igualados a la tabla indice y asi se presentar */
    this.tamano++; /**Por cada dato de la tabla que pase se incrementara de 1 a 1 */
    }

    /** Usmaos nuestros Get para que capture nuestra informacion de nuestra tabla */
    get(llave) {
    const objetivo = this.Tahash(llave); /**Buscamos una llave detnro de la tabla de Thahs */

    //Retornamos los datos en la tabla
    return this.tabla[objetivo]; /**Retornamos nuestro objetivo el cual era buscar una llave */
        }
    }
    const ht = new TablaHash(); /** Creamos un contenedor para nuestro dtos de nuestra tabla Hash */
    /** Ingresamos nuestros datos llave y valor */

    ht.set("Tiros a puerta", 27);
    ht.set("Remates", "11");
    ht.set("2", "Rodrigo");
    ht.set("Fuera juego", "5");
    /** Lo mostramos dentro de la consola */
    console.log(ht.get("Tiros a puerta"));
    console.log(ht.get("Remates"));
    console.log(ht.get("2"));
    console.log(ht.get("Fuera juego"));