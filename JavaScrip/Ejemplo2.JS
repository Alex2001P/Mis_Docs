//obtener_localstorage();
obtener_localstorage();

function obtener_localstorage() { //Creamos una funcion de obtener
    if (localStorage.getItem(" nombre ")) {
        //esto cuando existe algun nombre en nuestro local storage.
        let nombre = localStorage.getItem("Nombre"); //Obteniendo una variable, en este caso el nombre
        let persona = JSON.parse(localStorage.getItem("persona"));
        //Obtenemos nuestro objeto persona.
        //nuestro JSON Anterior es para pasar nuestros objetos y asi obtenerlos
        console.log(nombre);
        console.log(persona);
    } else {
        console.log("No tiene entradas en nuestro local Storage");
    }

}
/** CREAMOS NUESTRA FUNCION */
function guardar_localstorage() {
    let persona = {
        /**Creamos nuestro objeto en este caso es nuestra
persona */
        nombre: "Alejandra",
        apellido: "Lopez",
        edad: 18,
        coords: {
            /**Estas son unas cordenadas para fallida */
            lat: 10,
            /** esta es nuestra latitud */
            lng: -10 /** esta es una longitud */
        }
    };
    let nombre = "Daniel"; /** creamos otro objeto */
    localStorage.setItem("Nombre", nombre);
    /**esto es para poder grabar
nuestro local_storage*/
    localStorage.setItem("persona", JSON.stringify(persona));
    /**Ahora
vamos a grabar a una persona por el JSON */
}

/** En este caso por nuestro for, esto por si existe un objeto en nuestro local storage podemos trabajar en el codigo, */